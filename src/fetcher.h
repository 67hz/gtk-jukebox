#ifndef fetcher_h
#define fetcher_h
#include <curl/curl.h>
#include <string.h>


typedef struct _Connection Connection;

/**
 * @brief Basic connection class
 *
 * Curl interface.
 */
struct _Connection
{
  char* req; /**< holds the req url _Connection#req. */
  CURL* curl; /**< curl itself _Connection#curl. */
  CURLcode res; /**< res code _Connection#res. */
};



#endif /* fetcher_h */
