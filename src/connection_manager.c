#include <curl/curl.h>
#include <curl/easy.h>
#include <stdio.h>
#include "connection_manager.h"
#include <malloc.h>

  void
display ()
{
  printf("\n===========?>fp: virtual insanity\n");
}


  ConnectionManager *
connection_new (char* request)
{
  CURL *curl;
  curl = curl_easy_init();
  ConnectionManager *conn = malloc(sizeof(ConnectionManager));
  conn->req = request;
  conn->curl = curl;
  conn->display_info = display;

  conn->res = (CURLcode) conn->res;
  return conn;
}

/* @TODO return res */
  void
connection_request (ConnectionManager *self)
{
  if (self->curl)
  {
    curl_easy_setopt (self->curl, CURLOPT_URL, self->req);
    /* follow redirects */
    curl_easy_setopt (self->curl, CURLOPT_FOLLOWLOCATION, 1L);

    self->res = curl_easy_perform(self->curl);


    if (self->res != CURLE_OK)
    {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
          curl_easy_strerror (self->res));
    }
    else
    {
      printf ("\n\nres: %zu", self->res);
    }
  }
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
