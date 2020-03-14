/**
 * JukeboxAuthorizeUser - holds responsiblity for auth'ing and deauth'ing
 * users across any of the music streaming services
 */

#include "jukebox-authorize-user.h"
#include <glib.h>

/**
 * what data to hold? 
 * If concurrent users, token should not be held here - Let user hold on to it.
 *
 */

struct _JukeboxAuthorizeUser
{
  GObject parent_instance;
  GString response_token;
};



  GString *
jukebox_authorize_user_request_token (gpointer user_creds)
{

  return (GString *) "asdfasf23r235432tr";
}

