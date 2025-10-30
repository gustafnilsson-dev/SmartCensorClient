#include <stdio.h>
#include <unistd.h>
#include "network.h"

int main()
{
    printf("TCP POST client starts...\n");

    const char *server = "httpbin.org";
    int port = 80;

    int sockfd = connect_to_server(server, port);
    if (sockfd == -1)
    {
        printf("Failed to connect to server.\n");
        return 1;
    }

    printf("Connection succeded! Socket FD = %d\n", sockfd);
    close(sockfd);

    return 0;
}