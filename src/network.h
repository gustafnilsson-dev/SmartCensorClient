#ifndef NETWORK_H
#define NETWORK_H

int connect_to_server(const char *hostname, int port);
int send_post_request(int sockfd, const char *data);

typedef void (*ResponseHandler)(const char *);

int receive_response_with_handler(int sockfd, ResponseHandler handler);

#endif