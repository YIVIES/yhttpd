#include "./yhttpd_functions.h"

int Listen(int sockfd, int backlog)
{
    int ret = 0;
    char *E_buff = "listen error!\n";

    ret = listen(sockfd, backlog);

    if (ret == -1) {
        write(STDOUT_FILENO, E_buff, strlen(E_buff));
        exit(EXIT_FAILURE);
    }
    else {
        return ret;
    }
}