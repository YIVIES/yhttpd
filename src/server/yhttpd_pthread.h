#ifndef __H_YHTTPD_PTHREAD__
#define __H_YHTTPD_PTHREAD__

#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

struct env {
    int client_fd;
    int pt_index;
    char *str;
};

int Pthread_create(pthread_t *, const pthread_attr_t *, void *(*)(void *), void *);

#endif