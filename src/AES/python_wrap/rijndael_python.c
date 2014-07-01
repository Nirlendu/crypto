#include<Python.h>
#include<stdio.h>
#include<stdlib.h>

#include "../include/enc_dec.h"

static PyObject *encode(PyObject *self, PyObject *args) {
  PyObject *obj;
  char *ans;
  char *key,*message;
  if (!PyArg_ParseTuple(args, "ss", &key, &message)) {
    return NULL;
  }
  ans=encd(key,message);
  obj=Py_BuildValue("s",ans);
  Py_DECREF(ans);
  return obj;
}

static PyObject *decode(PyObject *self, PyObject *args) {
  PyObject *obj;
  char *ans;
  char *key,*message;
  if (!PyArg_ParseTuple(args, "ss", &key, &message)) {
    return NULL;
  }
  ans=decd(key,message);
  obj=Py_BuildValue("s",ans);
  Py_DECREF(ans);
  return obj;
}


static PyMethodDef rijndael_methods[] = {
  {"encode", encode, METH_VARARGS, "Encodes it"},
  {"decode", decode, METH_VARARGS, "Decodes it"}
};

PyMODINIT_FUNC initrijndael(void)
{
  Py_InitModule3("rijndael", rijndael_methods, "rijndael Methods");
}


