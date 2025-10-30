#ifndef NETWORK_H
#define NETWORK_H

// Här ska vi deklarera våra nätverksfunktioner
int connect_to_server(const char *hostname, int port);
int send_post_request(int sockfd, const char *data);
int receive_response(int sockfd);

#endif