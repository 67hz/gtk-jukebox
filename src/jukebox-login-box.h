#ifndef JUKEBOX_LOGIN_BOX_H
#define JUKEBOX_LOGIN_BOX_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define JUKEBOX_TYPE_LOGIN_BOX (jukebox_login_box_get_type())
G_DECLARE_FINAL_TYPE (JukeboxLoginBox, jukebox_login_box, JUKEBOX, LOGIN_BOX, GtkBox)


GtkWidget             *jukebox_login_box_new                    (void);





G_END_DECLS

#endif /* ifndef JUKEBOX_LOGIN_BOX_H */
