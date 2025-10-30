#define _POSIX_C_SOURCE 200112L
#include "network.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

int connect_to_server(const char *hostname, int port)
{
    struct addrinfo hints, *res, *p;
    int sockfd;
    char port_str[6];

    snprintf(port_str, sizeof(port_str), "%d", port);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;     // IPv4 eller IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP

    int status = getaddrinfo(hostname, port_str, &hints, &res);
    if (status != 0)
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return -1;
    }

    for (p = res; p != NULL; p = p->ai_next)
    {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1)
            continue;

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == 0)
        {

            freeaddrinfo(res);
            printf("Connected to: %s:%d\n", hostname, port);
            return sockfd;
        }

        close(sockfd);
    }

    fprintf(stderr, " Couldn't connect to: %s:%d\n", hostname, port);
    freeaddrinfo(res);
    return -1;
}

int send_post_request(int sockfd, const char *data)
{

    const char *request_template =
        "POST /post HTTP/1.1\r\n"
        "Host: httpbin.org\r\n"
        "Content-Type: application/json\r\n"
        "Content-Length: %zu\r\n"
        "Connection: close\r\n"
        "\r\n"
        "%s";

    char request[1024];
    int len = snprintf(request, sizeof(request), request_template, strlen(data), data);

    if (len >= (int)sizeof(request))
    {
        fprintf(stderr, "POST-data to big!\n");
        return -1;
    }

    ssize_t sent = write(sockfd, request, len);
    if (sent < 0)
    {
        perror("write");
        return -1;
    }

    printf("POST-request sent (%zd byte)\n", sent);
    return 0;
}

int receive_response(int sockfd)
{
    printf("Received response... (not implemented)\n");
    return 0;
}