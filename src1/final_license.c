//#include <Python.h>
#ifndef WIN32
#include <unistd.h>
#endif
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include"final_hash.c"

#ifndef PyMODINIT_FUNC
#define PyMODINIT_FUNC void
#endif

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


char* _read_license(char *lfile, char *err) {
  err="Valid licence file";
  FILE *fp;
  int ret_err = 0;
  char *client, *site, *users, *machines, *callers, *workflows, *time_from, *time_to;
  char *final=NULL;
  char *hash;
  
  if (!lfile) {
    err = "No Licene File Specified";
    return 0;
  }
  fp = fopen(lfile, "r");
  if (!fp) {
    //err = strerror(errno);
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
    err = "Bad or Corrupted License File";
    goto bye_bye;
  }
  
  final = hash_this(client, site, MAP_NAN(users), MAP_NAN(machines), MAP_NAN(callers), MAP_NAN(workflows),
MAP_TIME_NAN(time_from), MAP_TIME_NAN(time_to), 59265359);
  if (!final) {
    err = "Computation error - couldn't compute hash";
    goto bye_bye;
  }
  if (strcmp(hash, final)) {
    /* Our computed hash & the stored hash don't agree. The License file has probably being
tweaked */
    err = "Corrupted or Bad License File";
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
  return err;
}
