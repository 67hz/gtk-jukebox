#ifndef fetcher_h
#define fetcher_h
#include <curl/curl.h>
#include <string.h>

/* @TODO forward decl curl and move curl.h to fetcher.c */

typedef struct _Connection_Manager ConnectionManager;

/**
 * @brief Basic connection class
 *
 * Curl interface.
 */
struct _Connection_Manager {
  char* req; /**< holds the req url _ConnectionManager#req. */
  CURL* curl; /**< curl itself _ConnectionManager#curl. */
  // CURLcode res; /**< res code _ConnectionManager#res. */
  int num;


  /* virtual methods */
  void (*test) ();
};

ConnectionManager        *connection_new (char* req);
void                     connection_close (ConnectionManager *self);
ConnectionManager        *connection_request (ConnectionManager *self);



#endif /* fetcher_h */