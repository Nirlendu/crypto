#include<Python.h>
#include<stdio.h>
#include<stdlib.h>
#include"../lib/rijndael.c"

static PyObject *encode(PyObject *self, PyObject *args) {
  PyObject *obj;
  char *ans;
  char *key,*message;
  if (!PyArg_ParseTuple(args, "ss", &key, &message)) {
    return NULL;
  }
  ans=enc(key,message);
  obj=Py_BuildValue("s",ans);
  return obj;
}

static PyObject *decode(PyObject *self, PyObject *args) {
  PyObject *obj;
  char *ans;
  char *key,*message;
  if (!PyArg_ParseTuple(args, "ss", &key, &message)) {
    return NULL;
  }
  ans=dec(key,message);
  obj=Py_BuildValue("s",ans);
  return obj;
}


static PyMethodDef aes_methods[] = {
  {"encode", encode, METH_VARARGS, "Encode it"},
  {"decode", decode, METH_VARARGS, "Decodes it"}
};

PyMODINIT_FUNC initaes(void)
{
  Py_InitModule3("aes", aes_methods, "AES Methods");
}


