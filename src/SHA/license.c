#ifndef WIN32
#include"license.h"
#include <unistd.h>
#endif
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include<string.h>
#include<stdlib.h>
#define PyMODINIT_FUNC void
#ifdef WIN32
#define STRSEP id_strsep
#else
#define STRSEP strsep
#endif

char *hash_this(char *client, char *site, char *ucount, char *mcount, char *ccount, char *wcount, char *t_from, char *t_till, int cookie);

int num_users = 0;
int num_machines = 0;
int num_callers = 0;
int num_workflows = 0;
int gtime_from = 0;
int gtime_to = 0;
char *gclient = NULL;
char *gsite = NULL;

int id_atoi(char *str) {
  if (!strcmp(str, "NaN"))
    return -1;
  return atoi(str);
}

#define MAP_NAN(a) strcmp(a, "NaN") ? a : "-00001"
#define MAP_TIME_NAN(a) strcmp(a, "NaN") ? a : "-0000001"

char *readnodeline(FILE *fp) {
  int c, i = 0;
  char *line;

  c = getc(fp);
  ungetc(c, fp);

 ws_slurp:
  /* eat whitespaces at start of line */
  if (isspace(c)) {
    while ((c = getc(fp)) != EOF) {
      if (!isspace(c)) 
	break;
    }
  }

 comment_slurp:
  /* if this is a comment, slurp up the line */
  if (c == '#') {
    while ((c = getc(fp)) != EOF) {
      if (c == '\n') 
	break;
    }
  } 
  c = getc(fp);
  if (c == '#') 
    goto comment_slurp;
  else if (isspace(c)) 
    goto ws_slurp;

  line = malloc(4096);
  do {
    if (c == '\n'){
      line[i] = '\0';
      break;
    }
    else
      line[i] = c;
    i++;
  } while ((c = getc(fp)) != EOF);
  return line;
}

char *get_value(char *token, FILE *fp) {
  char *line, *c, *d;

  line = readnodeline(fp);
  if (!line)
    return NULL;
  if (strncmp(token, line, strlen(token))) {
    printf("Bad Match ! - expected token %s, but got %s\n", token, line);
    return NULL;
  }
  c = strchr(line, ' ');
  if (!c)
    return NULL;
  d = strdup(c+1);
  free(line);
  return d;
}


char* _read_license(char *lfile, char **err) {
  FILE *fp;
  int ret_err = 0;
  *err= "Perfect !";
  int errno;
  char *client, *site, *users, *machines, *callers, *workflows, *time_from, *time_to, *hash, *final=NULL;
  
  if (!lfile) {
    *err = "No Licene File Specified";
    return 0;
  }
  fp = fopen(lfile, "r");
  if (!fp) {
    *err = strerror(errno);
    return 0;
  }

  client = get_value("CLIENT", fp);
  site = get_value("SITE", fp);
  users = get_value("USERS", fp);
  machines = get_value("MACHINES", fp);
  callers = get_value("CALLERS", fp);
  workflows = get_value("WORKFLOWS", fp);
  time_from = get_value("TIME_FROM", fp);
  time_to = get_value("TIME_TO", fp);
  hash = get_value("HASH", fp);
  fclose(fp);

  if (!client || !site || !users || !machines || !callers || !workflows || !time_from || !time_to || !hash) {
    /* corrupted license file */
    *err = "Bad or Corrupted License File";
    goto bye_bye;
  }
  
  final = hash_this(client, site, MAP_NAN(users), MAP_NAN(machines), MAP_NAN(callers), MAP_NAN(workflows),
		    MAP_TIME_NAN(time_from), MAP_TIME_NAN(time_to), 59265359);
  if (!final) {
    *err = "Computation error - couldn't compute hash";
    goto bye_bye;
  }
  if (strcmp(hash, final)) {
    /* Our computed hash & the stored hash don't agree. The License file has probably being
       tweaked */
    *err = "Corrupted or Bad License File";
    goto bye_bye;
  }
  ret_err = 1;
  gclient = strdup(client);
  gsite = strdup(site);
  num_users = id_atoi(users);
  num_machines = id_atoi(machines);
  num_callers = id_atoi(callers);
  num_workflows = id_atoi(workflows);
  gtime_from = id_atoi(time_from);
  gtime_to = id_atoi(time_to);

 bye_bye:
  free(client);
  free(site);
  free(users);
  free(machines);
  free(callers);
  free(workflows);
  free(time_from);
  free(time_to);
  free(hash);
  //if (final)
  //  free(final);
  return *err;
}
/*

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
*/
