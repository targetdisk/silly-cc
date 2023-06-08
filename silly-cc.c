#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define _STRINGIFY(s)  #s
#define STRINGIFY(s) _STRINGIFY(s)
#ifndef CLANG
#define CLANG /usr/bin/clang
#endif

int main (int argc, char **argv) {
  char *silly_args[argc + 3];
  char *clang_filename = STRINGIFY(CLANG);
  char *json_filename = NULL;
  int ii = 2;

  for (int i = 1; i < argc; i++) {
    silly_args[ii++] = argv[i];
    if (strcmp("-o", argv[i]) == 0) {
      silly_args[ii++] = argv[++i];
      json_filename = malloc(strlen(argv[i]) + 6);
      if (!json_filename)
        exit(ENOMEM);
      strcpy(json_filename, argv[i]);
      strcat(json_filename, ".json");
    }
  }

  if (!json_filename)
    exit(ENOMSG);

  silly_args[0] = clang_filename;
  silly_args[1] = malloc(4);
  if (!silly_args[1])
    exit(ENOMEM);
  silly_args[1] = "-MJ";
  silly_args[2] = json_filename;
  silly_args[argc + 2] = NULL;

  printf("%s\n", json_filename);
  return execv(clang_filename, silly_args);
}
