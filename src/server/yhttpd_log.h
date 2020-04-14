#ifndef __H_YHTTPD_LOG__
#define __H_YHTTPD_LOG__

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <stdint.h>
#include <sys/stat.h>

#define OP_SOCKET 0x1
#define OP_BIND 0x2
#define OP_LISTEN 0x4
#define OP_ACCEPT 0x8


int add_log(int);
int get_timer(void);
int init_log(void);
int exit_log(void);

#endif