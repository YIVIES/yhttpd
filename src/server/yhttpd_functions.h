#ifndef __H_YHTTPD_FUNCTIONS__
#define __H_YHTTPD_FUNCTIONS__


#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int Socket(int, int, int);
int Bind(int, const struct sockaddr *, socklen_t);
int Listen(int, int);
int Accept(int, struct sockaddr *, socklen_t *);

#endif