#ifndef __H_YHTTPD_SERVER__
#define __H_YHTTPD_SERVER__

#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <dlfcn.h>
#include <stdint.h>
#include <pthread.h>
#include "./yhttpd_dl.h"
#include "./yhttpd_log.h"
#include "./yhttpd_pthread.h"

#define PT_NAME(s) pt##s

struct SockFun {
    int (*Socket)(int sockfd, int type, int protocol);
    int (*Bind)(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    int (*Listen)(int sockfd, int backlog);
    int (*Accept)(int listenfd, struct sockaddr *addr, socklen_t *addrlen);
};

struct LogFun {
    int (*Log_add)(int);
    int (*init_log)(void);
    int (*exit_log)(void);
};

struct PthreadFun {
    int (*Pthread_create)(pthread_t *, const pthread_attr_t *, void *(*)(void *), void *);
};

void *thread_function(void *);

#endif