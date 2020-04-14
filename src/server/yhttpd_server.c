#include "./yhttpd_server.h"

static const uint16_t listen_port = 6666;
static const int backlog = 10;
static unsigned int thread_max = 20;
static unsigned int thread_current = 0;
static int pt_index[20] = { 0 };

void *thread_function(void *arg)
{
    struct env *args = (struct env *)arg;
    int flags = 0;

    pthread_detach(pthread_self());

    send(args->client_fd, args->str, strlen(args->str), flags);

    pt_index[args->pt_index] = 0;
    thread_current--;
    return NULL;
}

int main(int argc, char *argv[])
{
    int i = 0;
    int server_fd = 0;
    int client_link_fd = 0;
    struct sockaddr_in server_addr;
    struct SockFun *sockfun;
    struct LogFun *logfun;
    struct PthreadFun *pthread_fun;
    struct env *arg;

    sockfun = (struct SockFun *)malloc(sizeof(struct SockFun));
    logfun = (struct LogFun *)malloc(sizeof(struct LogFun));
    pthread_fun = (struct PthreadFun *)malloc(sizeof(struct PthreadFun));
    arg = (struct env *)malloc(sizeof(struct env));
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    memset(sockfun, 0, sizeof(struct SockFun));
    memset(logfun, 0, sizeof(struct LogFun));
    memset(pthread_fun, 0, sizeof(struct PthreadFun));
    memset(arg, 0, sizeof(struct env));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(listen_port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    sockfun->Socket = dlsym_socket();
    sockfun->Bind = dlsym_bind();
    sockfun->Listen = dlsym_listen();
    sockfun->Accept = dlsym_accept();

    logfun->Log_add = dlsym_add_log();
    logfun->init_log = dlsym_init_log();
    logfun->exit_log = dlsym_exit_log();

    pthread_fun->Pthread_create = dlsym_pthread_create();

    logfun->init_log();
    server_fd = sockfun->Socket(AF_INET, SOCK_STREAM, 0);
    logfun->Log_add(OP_SOCKET);
    sockfun->Bind(server_fd, (struct sockaddr *)&server_addr, (socklen_t)sizeof(server_addr));
    logfun->Log_add(OP_BIND);
    sockfun->Listen(server_fd, backlog);
    logfun->Log_add(OP_LISTEN);

    while (1) {
        client_link_fd = sockfun->Accept(server_fd, (struct sockaddr *)NULL, (socklen_t *)NULL);
        logfun->Log_add(OP_ACCEPT);
        wait_thread:
        if (thread_current < thread_max) {
            for (i = 0; i < 20; i++) {
                if (pt_index[i] == 0) {
                    pt_index[i] = 1;
                    thread_current++;
                    arg->client_fd = client_link_fd;
                    arg->str = "Hello!";
                    arg->pt_index = i;
                    pthread_t PT_NAME(i);
                    pthread_fun->Pthread_create(&PT_NAME(i), NULL, thread_function, arg);
                    break;
                }
            }
        }
        else {
            goto wait_thread;
        }
    }

    logfun->exit_log();
    free(sockfun);
    free(logfun);
    exit(EXIT_SUCCESS);
}