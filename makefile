DEBUG32_OPTIONS1=gcc -Wall -g -m32 -std=gnu11	-shared -fPIC -o
DEBUG32_OPTIONS2=gcc -Wall -g -m32 -std=gnu11 -rdynamic -o

DEBUG64_OPTIONS1=gcc -Wall -g -m64 -std=gnu11 -shared -fPIC -o
DEBUG64_OPTIONS2=gcc -Wall -g -m64 -std=gnu11 -rdynamic -o

RELEASE32_OPTIONS1=gcc -Wall -m32 -std=gnu11 -shared -fPIC -o
RELEASE32_OPTIONS2=gcc -Wall -m32 -std=gnu11 -rdynamic -o

RELEASE64_OPTIONS1=gcc -Wall -m64 -std=gnu11 -shared -fPIC -o
RELEASE64_OPTIONS2=gcc -Wall -m64 -std=gnu11 -rdynamic -o

debug32:
	${DEBUG32_OPTIONS1} ./lib/yhttpd_fun_socket.so ./src/server/yhttpd_fun_socket.c
	${DEBUG32_OPTIONS1} ./lib/yhttpd_fun_bind.so ./src/server/yhttpd_fun_bind.c
	${DEBUG32_OPTIONS1} ./lib/yhttpd_fun_listen.so ./src/server/yhttpd_fun_listen.c
	${DEBUG32_OPTIONS1} ./lib/yhttpd_fun_accept.so ./src/server/yhttpd_fun_accept.c
	${DEBUG32_OPTIONS1} ./lib/yhttpd_pthread.so ./src/server/yhttpd_pthread.c
	# Log functions
	${DEBUG32_OPTIONS1} ./lib/yhttpd_log.so ./src/server/yhttpd_log.c
	${DEBUG32_OPTIONS2} yhttpd ./src/server/yhttpd_server.c ./src/server/yhttpd_dl.c -lpthread -ldl

debug64:
	${DEBUG64_OPTIONS1} ./lib/yhttpd_fun_socket.so ./src/server/yhttpd_fun_socket.c
	${DEBUG64_OPTIONS1} ./lib/yhttpd_fun_bind.so ./src/server/yhttpd_fun_bind.c
	${DEBUG64_OPTIONS1} ./lib/yhttpd_fun_listen.so ./src/server/yhttpd_fun_listen.c
	${DEBUG64_OPTIONS1} ./lib/yhttpd_fun_accept.so ./src/server/yhttpd_fun_accept.c
	${DEBUG64_OPTIONS1} ./lib/yhttpd_pthread.so ./src/server/yhttpd_pthread.c
	# Log functions
	${DEBUG64_OPTIONS1} ./lib/yhttpd_log.so ./src/server/yhttpd_log.c
	${DEBUG64_OPTIONS2} yhttpd ./src/server/yhttpd_server.c ./src/server/yhttpd_dl.c -lpthread -ldl

release32:
	${RELEASE32_OPTIONS1} ./lib/yhttpd_fun_socket.so ./src/server/yhttpd_fun_socket.c
	${RELEASE32_OPTIONS1} ./lib/yhttpd_fun_bind.so ./src/server/yhttpd_fun_bind.c
	${RELEASE32_OPTIONS1} ./lib/yhttpd_fun_listen.so ./src/server/yhttpd_fun_listen.c
	${RELEASE32_OPTIONS1} ./lib/yhttpd_fun_accept.so ./src/server/yhttpd_fun_accept.c
	$(RELEASE32_OPTIONS1) ./lib/yhttpd_pthread.so ./src/server/yhttpd_pthread.c
	${RELEASE32_OPTIONS1} ./lib/yhttpd_log.so ./src/server/yhttpd_log.c
	${RELEASE32_OPTIONS2} yhttpd ./src/server/yhttpd_server.c ./src/server/yhttpd_dl.c -lpthread -ldl

release64:
	${RELEASE64_OPTIONS1} ./lib/yhttpd_fun_socket.so ./src/server/yhttpd_fun_socket.c
	${RELEASE64_OPTIONS1} ./lib/yhttpd_fun_bind.so ./src/server/yhttpd_fun_bind.c
	${RELEASE64_OPTIONS1} ./lib/yhttpd_fun_listen.so ./src/server/yhttpd_fun_listen.c
	${RELEASE64_OPTIONS1} ./lib/yhttpd_fun_accept.so ./src/server/yhttpd_fun_accept.c
	${RELEASE64_OPTIONS1} ./lib/yhttpd_pthread.so ./src/server/yhttpd_pthread.c
	${RELEASE64_OPTIONS1} ./lib/yhttpd_log.so ./src/server/yhttpd_log.c
	${RELEASE64_OPTIONS2} yhttpd ./src/server/yhttpd_server.c ./src/server/yhttpd_dl.c -lpthread -ldl