#include "./yhttpd_pthread.h"

int Pthread_create(pthread_t *__restrict__ pt,
    const pthread_attr_t *__restrict__ attr, void *(*function)(void *), void *arg)
{
    int ret = 0;
    char *E_buff = "pthread_create(): error!\n";

    ret = pthread_create(pt, attr, function, arg);
    if (ret != 0) {
        write(STDOUT_FILENO, E_buff, strlen(E_buff));
        return 1;
    }
    return 0;
}