#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "network.h"

void print_response_handler(const char *response);
void count_response_handler(const char *response);

typedef void (*ResponseHandler)(const char *);

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

    char *fields[] = {"device", "time", "temperature"};
    char **ptr_to_ptr = fields;
    printf("Pointer to pointer example: first field = %s\n", ptr_to_ptr[0]);

    ResponseHandler handler = print_response_handler;

    receive_response_with_handler(sockfd, handler);

    close(sockfd);
    return 0;
}

void print_response_handler(const char *response)
{
    printf("%s", response);
}

void count_response_handler(const char *response)
{
    printf("%zu\n", strlen(response));
}