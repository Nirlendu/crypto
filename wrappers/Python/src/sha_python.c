#include<Python.h>
#include<stdio.h>
#include<stdlib.h>
#include"../../../src/SHA/license.c"

static PyObject *create_node(PyObject *self, PyObject *args) {
  PyObject *eval_fn, *owner, *pobj, *temp, *kwtemp, *str, *machine_class;
  int machine_count = 0, ssh_port;
  char *name, *address, *os, *comment;
  
  if (!PyArg_ParseTuple(args, "OOssisOs", &eval_fn, &machine_class, &name, &address, &ssh_port, &os, &owner, &comment)) {
    return NULL;
  }
  if (!PyCallable_Check(eval_fn)) {
    PyErr_SetString(PyExc_TypeError, "1st argument must be a callable");
    return NULL;
  }
  if (!PyCallable_Check(machine_class)) {
    PyErr_SetString(PyExc_TypeError, "2nd argument must be a callable");
    return NULL;
  }
  
  str = PyString_FromString("_s.query(Machine).count()");
  temp = Py_BuildValue("(O)", str);
  pobj = PyEval_CallObject(eval_fn, temp);
  Py_DECREF(temp);
  Py_DECREF(str);
  
  if (!pobj) {
    return NULL;
  }
  if (!PyArg_Parse(pobj, "i", &machine_count)) {
    return NULL;
  }
  Py_DECREF(pobj);
  if (num_machines < machine_count + 1) {
    return PyErr_Format(PyExc_RuntimeError, "All node licenses (%d) have been exhausted. No new node can be created. Please contact Support", num_machines);
  }
  
  temp = Py_BuildValue("(ssisO)", name, address, ssh_port, os, owner);
  kwtemp = Py_BuildValue("{s:s}", "comment", comment);
  pobj = PyObject_Call(machine_class, temp, kwtemp);
  Py_DECREF(temp);
  Py_DECREF(kwtemp);
  return pobj;
}

static PyObject *read_license(PyObject *self, PyObject *args) {
  char *license_file, *err;
  PyObject *obj;
  int licenses;
  
  if (!PyArg_ParseTuple(args, "s", &license_file)) {
    return NULL;
  }
  licenses = _read_license(license_file, &err);
  if (!licenses) {
    return PyErr_Format(PyExc_RuntimeError, "Could not read license file. (%s). Please contact Support.", err);
  }
  obj = Py_BuildValue("i", licenses);
  return obj;
}

static PyObject *get_license_value(PyObject *self, PyObject *args) {
  PyObject *obj;
  obj = Py_BuildValue("{s:i,s:i,s:i,s:i,s:i,s:i}", "max_users", num_users, "max_machines", num_machines, "max_callers", num_callers,
		      "max_workflows", num_workflows, "valid_from", gtime_from, "valid_for", gtime_to);
  return obj;
}

static PyObject *get_license_duration(PyObject *self, PyObject *args) {
  time_t current_time, licence_expiry_time;
  struct tm licence_expiry_time_struct;
  char expiry_time_str[10];
  if (gtime_to == -1)
    return Py_BuildValue("i", gtime_to);
  sprintf(expiry_time_str, "%d", gtime_to);                           // casting gtime_to back to char *
  memset(&licence_expiry_time_struct, 0, sizeof(struct tm));          // initalize to all 0's
  strptime(expiry_time_str, "%Y%m%d", &licence_expiry_time_struct);   // populating the struct tm variable
  licence_expiry_time_struct.tm_hour = 23;                            // expires at midnight
  licence_expiry_time_struct.tm_min = 59;
  licence_expiry_time = mktime(&licence_expiry_time_struct);
  time(&current_time);  
  return Py_BuildValue("l", licence_expiry_time - current_time);
}


static PyObject *init_license(PyObject *self, PyObject *args) {
  char *err, *license_file;
  
  if (!PyArg_ParseTuple(args, "s", &license_file)) {
    return NULL;
  }
  if (!_read_license(license_file, &err))
    return PyErr_Format(PyExc_RuntimeError, "Could not read license file. (%s). Please contact Support.", err);
  return Py_None;
}



static PyMethodDef license_methods[] = {
  {"create_node", create_node, METH_VARARGS, "Create a node in the system"},
  {"read_license", read_license, METH_VARARGS, "Read the license for this system"},
  {"init_license", init_license, METH_VARARGS, "Init the license in memory"},
  {"get_license_value", get_license_value, METH_VARARGS, "Returns complete license details"},
  {"get_license_duration", get_license_duration, METH_VARARGS, "Returns seconds remaining from license expiry"},
  {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initlicense(void)
{
  Py_InitModule3("license", license_methods, "License Methods");
}


