#ifndef __JUKEBOX_USER_H__
#define __JUKEBOX_USER_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define JUKEBOX_TYPE_USER jukebox_user_get_type ()

G_DECLARE_FINAL_TYPE (JukeboxUser, jukebox_user, JUKEBOX, USER, GObject);

JukeboxUser *jukebox_user_new (void);

JukeboxUser *jukebox_user_login (gchar *name, char* pw, gint service_name);
JukeboxUser *jukebox_user_logout (gchar *name, char* pw, gint service_name);

gboolean     jukebox_user_is_logged_in (JukeboxUser *self);


G_END_DECLS

#endif /* __JUKEBOX_USER_H__ */
