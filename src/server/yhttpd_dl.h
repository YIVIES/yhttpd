#ifndef __H_YHTTPD_DL__
#define __H_YHTTPD_DL__


#include <dlfcn.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void *dlsym_socket(void);
void *dlsym_bind(void);
void *dlsym_listen(void);
void *dlsym_accept(void);
void *dlsym_add_log(void);
void *dlsym_init_log(void);
void *dlsym_exit_log(void);
void *dlsym_pthread_create(void);

#endif