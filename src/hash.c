/***
 * DO NOT SHIP
***/

#include <Python.h>
#ifndef WIN32
#include <unistd.h>
#endif
#include <stdio.h>
#include <ctype.h>

char *_fudge(char *client, char *site, char *ucount, char *mcount, char *ccount, char *wcount, char *t_from, char *t_till, int cookie) {
  unsigned int i,j,len = 0;
  char *temp;
  
  len = strlen(client)*2 + strlen(site)*2 + strlen(ucount)*2 + strlen(mcount)*2 + strlen(ccount)*2 + strlen(wcount)*2 
    + strlen(t_from)*2 + strlen(t_till)*2 + 4;
  temp = malloc(len);
  memset(temp, 'B', len);
  /* interleave all arguments. Gaps are filled with 'B' */
  for (j = 0,i = 0; i < strlen(client); i++, j += 8)
    temp[j] = client[i];
  for (j = 1,i = 0; i < strlen(site); i++, j+= 8)
    temp[j] = site[i];
  for (j = 2,i = 0; i < strlen(ucount); i++, j += 8)
    temp[j] = ucount[i];
  for (j = 3,i = 0; i < strlen(mcount); i++, j += 8)
    temp[j] = mcount[i];
  for (j = 4,i = 0; i < strlen(ccount); i++, j += 8)
    temp[j] = ccount[i];
  for (j = 5,i = 0; i < strlen(wcount); i++, j += 8)
    temp[j] = wcount[i];
  for (j = 6,i = 0; i < strlen(t_from); i++, j += 8)
    temp[j] = t_from[i];
  for (j = 7,i = 0; i < strlen(t_till); i++, j += 8)
    temp[j] = t_till[i];
  temp[len-5] = '\0';
  return strncat(temp, (char *)&cookie, 4);
}

char *hash_this(char *client, char *site, char *ucount, char *mcount, char *ccount, char *wcount, char *t_from, char *t_till, int cookie) {
  PyObject *digest, *sha1, *obj, *mod = PyImport_ImportModuleNoBlock("hashlib");
  char *hash, *prehash = _fudge(client, site, ucount, mcount, ccount, wcount, t_from, t_till, cookie);
  
  sha1 = PyObject_GetAttrString(mod, "sha1");
  obj = PyObject_CallFunction(sha1, "(s)", prehash);
  digest = PyObject_CallMethod(obj, "hexdigest", NULL);
  free(prehash);
  
  if (digest) {
    hash = strdup(PyString_AsString(digest));
  } else
    hash = NULL;
  
  Py_XDECREF(digest);
  Py_XDECREF(obj);
  Py_XDECREF(sha1);
  Py_XDECREF(mod);
  
  return hash;
}

