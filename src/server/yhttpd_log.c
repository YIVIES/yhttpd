#include "./yhttpd_log.h"

enum OP_NUMBER { _OP_RUN, _OP_SOCKET, _OP_BIND, _OP_LISTEN, _OP_ACCEPT };
static const char *
log_path = "/home/yivies/Desktop/yhttpd/log/yhttpd_log.txt";
static const uint32_t len = 256;
static char
opera[][256] = {
    { "Welcome to yhttpd!\n" },
    { "socket(): Create socket.\n" },
    { "bind(): Bind socket address.\n" },
    { "listen(): Listening socket.\n" },
    { "accept(): Received a connection.\n" }
};

int get_timer(void)
{
    int flags = O_RDWR | O_APPEND;
    int fd = 0;
    int n = 0;
    int i = 0;
    char *E_buff = "get_timer(): open yhttpd_log.txt error!\n";
    char *timer_str;
    char *timer_style = "-->";
    struct tm tm  = { 0 };
    time_t timer = 0;

    fd = open(log_path, flags);
    if (fd == -1) {
        write(STDOUT_FILENO, E_buff, strlen(E_buff));
        return 1;
    }

    timer = time(NULL);
    localtime_r(&timer, &tm);
    timer_str = asctime(&tm);
    
    n = strlen(timer_str);
    for (i = 0; i < n; i++) {
        if (timer_str[i] == '\r' || timer_str[i] == '\n') {
            timer_str[i] = '\0';
        }
    }

    write(fd, timer_str, strlen(timer_str));
    write(fd, timer_style, strlen(timer_style));
    close(fd);
    return 0;
}

int add_log(int op)
{
    int flags = O_RDWR | O_APPEND | O_CREAT;
    int fd = 0;
    char *E_buff = "add_log(): open yhttpd_log.txt error!\n";
    enum OP_NUMBER op_number;
    
    get_timer();

    fd = open(log_path, flags);
    if (fd == -1) {
        write(STDOUT_FILENO, E_buff, strlen(E_buff));
        return 1;
    }

    switch (op) {
        case OP_SOCKET:
            op_number = _OP_SOCKET;
            write(fd, opera[op_number], strlen(opera[op_number]));
            close(fd);
        return 0;
        case OP_BIND:
            op_number = _OP_BIND;
            write(fd, opera[op_number], strlen(opera[op_number]));
            close(fd);
        return 0;
        case OP_LISTEN:
            op_number = _OP_LISTEN;
            write(fd, opera[op_number], strlen(opera[op_number]));
            close(fd);
        return 0;
        case OP_ACCEPT:
            op_number = _OP_ACCEPT;
            write(fd, opera[op_number], strlen(opera[op_number]));
            close(fd);
        return 0;
    default:
        return 1;
    }
}

int init_log(void)
{
    int fd = 0;
    int n = 0;
    int i = 0;
    int flags = O_RDWR | O_APPEND;
    time_t timer;
    struct tm tm = { 0 };
    char *E_buff = "init_log(): open yhttpd_log.txt error!\n";
    char *init_title0 = "++++++++++ ";
    char *init_title1 = " run-->yhttpd ++++++++++\n";
    char *init_timer;
    
    enum OP_NUMBER op_number;
    op_number = _OP_RUN;
    write(STDOUT_FILENO, opera[op_number], strlen(opera[op_number]));

    fd = open(log_path, flags);
    if (fd == -1) {
        write(STDOUT_FILENO, E_buff, strlen(E_buff));
        return 1;
    }

    timer = time(NULL);
    localtime_r(&timer, &tm);
    init_timer = asctime(&tm);

    write(fd, init_title0, strlen(init_title0));

    n = strlen(init_timer);
    for (i = 0; i < n; i++) {
        if (init_timer[i] == '\r' || init_timer[i] == '\n') {
            init_timer[i] = '\0';
        }
    }
    write(fd, init_timer, strlen(init_timer));
    write(fd, init_title1, strlen(init_title1));

    close(fd);
    return 0;
}

int exit_log(void)
{
    int fd = 0;
    int n = 0;
    int i = 0;
    int flags = O_RDWR | O_APPEND;
    time_t timer;
    struct tm tm = { 0 };
    char *E_buff = "init_log(): open yhttpd_log.txt error!\n";
    char *exit_title0 = "========== ";
    char *exit_title1 = " exit-->yhttpd ==========\n\n";
    char *exit_timer;
    
    fd = open(log_path, flags);
    if (fd == -1) {
        write(STDOUT_FILENO, E_buff, strlen(E_buff));
        return 1;
    }

    timer = time(NULL);
    localtime_r(&timer, &tm);
    exit_timer = asctime(&tm);

    write(fd, exit_title0, strlen(exit_title0));

    n = strlen(exit_timer);
    for (i = 0; i < n; i++) {
        if (exit_timer[i] == '\r' || exit_timer[i] == '\n') {
            exit_timer[i] = '\0';
        }
    }
    write(fd, exit_timer, strlen(exit_timer));
    write(fd, exit_title1, strlen(exit_title1));

    close(fd);
    return 0;
}