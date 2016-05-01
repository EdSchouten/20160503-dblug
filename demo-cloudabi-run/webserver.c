#include <sys/socket.h>

#include <argdata.h>
#include <netdb.h>
#include <program.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void program_main(const argdata_t *ad) {
  // Default configuration values.
  int sockfd = -1;
  int logfd = -1;
  const char *message = "Hello, world\n";

  // Obtain overrides from configuration.
  {
    argdata_map_iterator_t it;
    argdata_map_iterate(ad, &it);
    const argdata_t *key, *value;
    while (argdata_map_next(&it, &key, &value)) {
      const char *keystr;
      if (argdata_get_str_c(key, &keystr) != 0)
        continue;
      if (strcmp(keystr, "socket") == 0)
        argdata_get_fd(value, &sockfd);
      else if (strcmp(keystr, "logfile") == 0)
        argdata_get_fd(value, &logfd);
      else if (strcmp(keystr, "message") == 0)
        argdata_get_str_c(value, &message);
    }
  }

  // Handle incoming requests.
  {
    int connfd;
    struct sockaddr_storage ss;
    socklen_t sslen = sizeof(ss);
    while ((connfd = accept(sockfd, (struct sockaddr *)&ss, &sslen)) >= 0) {
      // Log request.
      char host[NI_MAXHOST];
      char serv[NI_MAXSERV];
      if (getnameinfo((const struct sockaddr *)&ss, sslen, host, sizeof(host),
                      serv, sizeof(serv), NI_NUMERICHOST | NI_NUMERICSERV) == 0)
        dprintf(logfd, "Incoming request from %s:%s\n", host, serv);

      // Write response to client.
      dprintf(connfd, "HTTP/1.1 200 OK\r\n"
                      "Content-Type: text/html\r\n"
                      "Content-Length: %zu\r\n\r\n"
                      "%s",
              strlen(message), message);
      close(connfd);
    }
  }

  exit(1);
}
