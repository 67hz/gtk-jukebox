#ifndef JUKEBOX_LOGIN_BOX_H
#define JUKEBOX_LOGIN_BOX_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct JukeboxLoginParams {
    const gchar *username;
    const gchar *pw;
    gchar *service;
    gint service_id;
} JukeboxLoginParams;

#define JUKEBOX_TYPE_LOGIN_BOX (jukebox_login_box_get_type())
G_DECLARE_FINAL_TYPE (JukeboxLoginBox, jukebox_login_box, JUKEBOX, LOGIN_BOX, GtkBin)

GtkWidget                *jukebox_login_box_new                         (void);
gpointer                  jukebox_login_box_get_inputs (JukeboxLoginBox *self);


G_END_DECLS

#endif /* ifndef JUKEBOX_LOGIN_BOX_H */
