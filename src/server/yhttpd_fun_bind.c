#include "./yhttpd_functions.h"

int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int ret = 0;
    char *E_buff = "bind error!\n";

    ret = bind(sockfd, addr, addrlen);

    if (ret == -1) {
        write(STDOUT_FILENO, E_buff, strlen(E_buff));
        exit(EXIT_FAILURE);
    }
    else {
        return ret;
    }
}