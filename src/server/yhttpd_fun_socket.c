#include "./yhttpd_functions.h"

int Socket(int sockfd, int type, int protocol)
{
    int ret = 0;
    char *E_buff = "socket error!\n";

    ret = socket(sockfd, type, protocol);

    if (ret == -1) {
        write(STDOUT_FILENO, E_buff, strlen(E_buff));
        exit(EXIT_FAILURE);
    }
    else {
        return ret;
    }
}