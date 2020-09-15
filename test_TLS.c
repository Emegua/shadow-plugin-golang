#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <gnu/lib-names.h>
# define LM_ID_BASE 0 /* Initial namespace.  */
# define LM_ID_NEWLM  -1  /* For dlmopen: request new namespace.  */

int main(int argc, char **argv) {
  void *handle;
  char *error;

  handle = dlmopen (LM_ID_BASE, "./libpthread.so", RTLD_LAZY);
  if (!handle) {
    fputs (dlerror(), stderr);
    exit(1);
  }

  void (* test) () = dlsym(handle, "main");
  (*test)();
 //dlclose(handle);
}
