#ifndef __JUKEBOX_AUTHORIZE_USER_H__
#define __JUKEBOX_AUTHORIZE_USER_H__

#include <glib-object.h>


G_BEGIN_DECLS

#define JUKEBOX_TYPE_AUTHORIZE_USER jukebox_authorize_user_get_type ()
G_DECLARE_FINAL_TYPE (JukeboxAuthorizeUser, jukebox_authorize_user, JUKEBOX, AUTHORIZE_USER, GObject);


/**
 * gpointer is generic cast of user struct
 * see: https://stackoverflow.com/questions/22384333/passing-additional-arguments-to-gtk-function
 * @return GString - dynamic c-string that grows as needed since token is of undetermined size
 */
GString jukebox_authorize_user_request_token (gpointer user_data);





G_END_DECLS

#endif /* __JUKEBOX_AUTHORIZE_USER_H__ */
