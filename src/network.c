#include "network.h"
#include <stdio.h>

int connect_to_server(const char *hostname, int port)
{
    printf("Ansluter till %s:%d ... (ej implementerad ännu)\n", hostname, port);
    return -1;
}

int send_post_request(int sockfd, const char *data)
{
    printf("Skickar POST-request... (ej implementerad ännu)\n");
    return 0;
}

int receive_response(int sockfd)
{
    printf("Tar emot svar... (ej implementerad ännu)\n");
    return 0;
}