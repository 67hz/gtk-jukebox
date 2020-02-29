#include <curl/curl.h>
#include <stdio.h>
#include "fetcher.h"
#include <malloc.h>

void
display ()
{
  printf("\nfp: display\n");
}


ConnectionManager *
connection_new (char* request)
{
  CURL *curl;
  curl = curl_easy_init();
  ConnectionManager *conn = malloc(sizeof(ConnectionManager));
  conn->req = request;
  conn->curl = curl;
  conn->num = 5;
  conn->test= display;
  return conn;
}

void
connection_close (ConnectionManager *self)
{
  if (self->curl)
  {
    printf ("\nclosing down connection\n");
    curl_easy_cleanup (self->curl);
  }

  free (self);
}
