#ifndef fetcher_h
#define fetcher_h
#include <string.h>

typedef struct _Connection_Manager ConnectionManager;
typedef void CURL;

/* cannot forward declare CURLcode enum, so cast it to a size_t */
typedef size_t curl_code;


/**
 * @brief Basic connection class
 *
 * Curl interface.
 */
struct _Connection_Manager {
  char* req; /**< holds the req url _ConnectionManager#req. */
  CURL* curl; /**< curl itself _ConnectionManager#curl. */
  curl_code res; /**< res code ((enum)CURLcode) _ConnectionManager#res. */

  /* virtual methods */
  void (*display_info) ();
};

ConnectionManager        *connection_new (char* req);
void                     connection_close (ConnectionManager *self);
void                     connection_request (ConnectionManager *self);


#endif /* fetcher_h */
