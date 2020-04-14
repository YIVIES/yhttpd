#include "./yhttpd_functions.h"

int Accept(int listenfd, struct sockaddr *addr, socklen_t *addrlen)
{
    int ret = 0;
    char *E_buff = "accept error!\n";

    ret = accept(listenfd, addr, addrlen);

    if (ret == -1) {
        write(STDOUT_FILENO, E_buff, strlen(E_buff));
        exit(EXIT_FAILURE);
    }
    else {
        return ret;
    }
}