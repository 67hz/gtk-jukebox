#include <stdio.h>
#include "fetcher.h"
#include <malloc.h>

void
display ()
{
  printf("fp: display");
}


ConnectionManager *
connection_new (char* request)
{
  ConnectionManager *conn = malloc(sizeof(ConnectionManager));
  conn->req = request;
  conn->num = 5;
  conn->test= display;
  return conn;
}
