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
    // Hårdkodad JSON-sträng
    const char *json_data =
        "{ \"device\": \"123e4567-e89b-12d3-a456-426614174000\", "
        "\"time\": \"2025-10-30T12:00:00Z\", "
        "\"temperature\": \"22.5°C\" }";

    if (send_post_request(sockfd, json_data) == -1)
    {
        printf("Failed to send POST-request.\n");
        close(sockfd);
        return 1;
    }

    close(sockfd);

    return 0;
}