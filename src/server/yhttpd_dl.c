#include "./yhttpd_dl.h"

static const int flag = RTLD_LAZY;
static const char *
socket_so_path = "/home/yivies/Desktop/yhttpd/lib/yhttpd_fun_socket.so";
static const char *
bind_so_path = "/home/yivies/Desktop/yhttpd/lib/yhttpd_fun_bind.so";
static const char *
listen_so_path = "/home/yivies/Desktop/yhttpd/lib/yhttpd_fun_listen.so";
static const char *
accept_so_path = "/home/yivies/Desktop/yhttpd/lib/yhttpd_fun_accept.so";
static const char *
log_so_path = "/home/yivies/Desktop/yhttpd/lib/yhttpd_log.so";
static const char *
pthread_path = "/home/yivies/Desktop/yhttpd/lib/yhttpd_pthread.so";

void *dlsym_socket(void)
{
    void *ret;
    void *Handle;
    char *E_buff_open = "dlopen socket error!\n";
    char *E_buff_sym = "dlsym socket error!\n";
    char *name = "Socket";

    Handle = dlopen(socket_so_path, flag);

    if (Handle == NULL) {
        write(STDOUT_FILENO, E_buff_open, strlen(E_buff_open));
        exit(EXIT_FAILURE);
    }

    ret = dlsym(Handle, name);

    if (ret == NULL) {
        write(STDOUT_FILENO, E_buff_sym, strlen(E_buff_sym));
        exit(EXIT_FAILURE);
    }
    else {
        return ret;
    }
}

void *dlsym_bind(void)
{
    void *ret;
    void *Handle;
    char *E_buff_open = "dlopen bind error!\n";
    char *E_buff_sym = "dlsym bind error!\n";
    char *name = "Bind";

    Handle = dlopen(bind_so_path, flag);

    if (Handle == NULL) {
        write(STDOUT_FILENO, E_buff_open, strlen(E_buff_open));
        exit(EXIT_FAILURE);
    }

    ret = dlsym(Handle, name);

    if (ret == NULL) {
        write(STDOUT_FILENO, E_buff_sym, strlen(E_buff_sym));
        exit(EXIT_FAILURE);
    }
    else {
        return ret;
    }
}

void *dlsym_listen(void)
{
    void *ret;
    void *Handle;
    char *E_buff_open = "dlopen listen error!\n";
    char *E_buff_sym = "dlsym listen error!\n";
    char *name = "Listen";

    Handle = dlopen(listen_so_path, flag);

    if (Handle == NULL) {
        write(STDOUT_FILENO, E_buff_open, strlen(E_buff_open));
        exit(EXIT_FAILURE);
    }

    ret = dlsym(Handle, name);

    if (ret == NULL) {
        write(STDOUT_FILENO, E_buff_sym, strlen(E_buff_sym));
        exit(EXIT_FAILURE);
    }
    else {
        return ret;
    }
}

void *dlsym_accept(void)
{
    void *ret;
    void *Handle;
    char *E_buff_open = "dlopen accept error!\n";
    char *E_buff_sym = "dlsym accept error!\n";
    char *name = "Accept";

    Handle = dlopen(accept_so_path, flag);

    if (Handle == NULL) {
        write(STDOUT_FILENO, E_buff_open, strlen(E_buff_open));
        exit(EXIT_FAILURE);
    }

    ret = dlsym(Handle, name);

    if (ret == NULL) {
        write(STDOUT_FILENO, E_buff_sym, strlen(E_buff_sym));
        exit(EXIT_FAILURE);
    }
    else {
        return ret;
    }
}

void *dlsym_add_log(void)
{
    void *ret;
    void *Handle;
    char *E_buff_open = "dlopen add_log error!\n";
    char *E_buff_sym = "dlsym add_log error!\n";
    char *name = "add_log";

    Handle = dlopen(log_so_path, flag);

    if (Handle == NULL) {
        write(STDOUT_FILENO, E_buff_open, strlen(E_buff_open));
        exit(EXIT_FAILURE);
    }

    ret = dlsym(Handle, name);

    if (ret == NULL) {
        write(STDOUT_FILENO, E_buff_sym, strlen(E_buff_sym));
        exit(EXIT_FAILURE);
    }
    else {
        return ret;
    }
}

void *dlsym_init_log(void)
{
    void *ret;
    void *Handle;
    char *E_buff_open = "dlopen init_log error!\n";
    char *E_buff_sym = "dlsym init_log error!\n";
    char *name = "init_log";

    Handle = dlopen(log_so_path, flag);

    if (Handle == NULL) {
        write(STDOUT_FILENO, E_buff_open, strlen(E_buff_open));
        exit(EXIT_FAILURE);
    }

    ret = dlsym(Handle, name);

    if (ret == NULL) {
        write(STDOUT_FILENO, E_buff_sym, strlen(E_buff_sym));
        exit(EXIT_FAILURE);
    }
    else {
        return ret;
    }
}

void *dlsym_exit_log(void)
{
    void *ret;
    void *Handle;
    char *E_buff_open = "dlopen exit_log error!\n";
    char *E_buff_sym = "dlsym exit_log error!\n";
    char *name = "exit_log";

    Handle = dlopen(log_so_path, flag);

    if (Handle == NULL) {
        write(STDOUT_FILENO, E_buff_open, strlen(E_buff_open));
        exit(EXIT_FAILURE);
    }

    ret = dlsym(Handle, name);

    if (ret == NULL) {
        write(STDOUT_FILENO, E_buff_sym, strlen(E_buff_sym));
        exit(EXIT_FAILURE);
    }
    else {
        return ret;
    }
}

void *dlsym_pthread_create(void)
{
    void *ret;
    void *Handle;
    char *E_buff_open = "dlopen pthread_create error!\n";
    char *E_buff_sym = "dlsym pthread_create error!\n";
    char *name = "Pthread_create";

    Handle = dlopen(pthread_path, flag);

    if (Handle == NULL) {
        write(STDOUT_FILENO, E_buff_open, strlen(E_buff_open));
        exit(EXIT_FAILURE);
    }

    ret = dlsym(Handle, name);

    if (ret == NULL) {
        write(STDOUT_FILENO, E_buff_sym, strlen(E_buff_sym));
        exit(EXIT_FAILURE);
    }
    else {
        return ret;
    }
}