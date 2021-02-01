#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "server.h"

#define PORT 37
#define TIME_OFFSET 0

int tcp_fd, udp_fd;
fd_set fdset;
struct sockaddr_in address, cliaddress;

int max(int x, int y) 
{ 
    return (x > y) ? x : y;
} 

void start_server()
{
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    start_tcp(tcp_fd, address);
    start_udp(udp_fd, address);

    FD_ZERO(&fdset);
    int max_fd = max(tcp_fd, udp_fd) + 1;
    char buff[32] = {0};
    while (1)
    {        
        FD_SET(tcp_fd, &fdset);
        FD_SET(udp_fd, &fdset);

        int ready = select(max_fd, &fdset, NULL, NULL, NULL);

        if (FD_ISSET(tcp_fd, &fdset)) {
            bzero(buff, sizeof(buff));
            socklen_t len = sizeof(cliaddress);
            int conn_fd = accept(tcp_fd, (struct sockaddr*)&cliaddress, &len);

            uint64_t seconds = (uint64_t)time(NULL) + TIME_OFFSET;
            snprintf(buff, sizeof(buff), "%u", seconds);
            send(conn_fd, buff, sizeof(buff), 0);

            close(conn_fd);
        }

        if (FD_ISSET(udp_fd, &fdset)) {
            socklen_t len = sizeof(cliaddress);
            bzero(buff, sizeof(buff)); 
            recvfrom(udp_fd, buff, sizeof(buff), 0, (struct sockaddr*)&cliaddress, &len); 

            uint64_t seconds = (uint64_t)time(NULL) + TIME_OFFSET;
            snprintf(buff, sizeof(buff), "%u", seconds);

            sendto(udp_fd, buff, sizeof(buff), 0, (struct sockaddr*)&cliaddress, len); 
        }
    }
}

void start_tcp(int &tcp, sockaddr_in &addr)
{
    // Creating socket file descriptor
    if ((tcp_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("tcp socket failed");
        exit(EXIT_FAILURE);
    }

    if (bind(tcp_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("tcp bind failed");
        exit(EXIT_FAILURE);
    }

    // Now server is ready to listen and verification
    if ((listen(tcp_fd, 5)) != 0)
    {
        printf("tcp listen failed...\n");
        exit(0);
    }
    else
        printf("tcp socket online..\n");
}

void start_udp(int &udp, sockaddr_in &addr)
{
    if ((udp_fd = socket(AF_INET, SOCK_DGRAM, 0)) == 0)
    {
        perror("udp socket failed");
        exit(EXIT_FAILURE);
    }

    if (bind(udp_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("udp bind failed");
        exit(EXIT_FAILURE);
    }
    else
        printf("udp socket online..\n");
}

void *tcp_runner(void *args) {

}

void *udp_runner(void *args) {

}
