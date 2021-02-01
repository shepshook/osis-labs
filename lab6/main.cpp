#include <syslog.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <time.h>
#include <unistd.h>
#include "daemon.h"
#include "server.h"

// seconds since 01/01/1900 till 01/01/1970
// #define TIME_OFFSET 2208988800L
#define TIME_OFFSET 0

int main()
{
    init_daemon();
    start_server();

    return EXIT_SUCCESS;
}