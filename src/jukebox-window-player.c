#include <gtk/gtk.h>
#include <glib.h>

#define JUKEBOX_TYPE_WINDOW_PLAYER (jukebox_window_player_get_type ())

G_DECLARE_FINAL_TYPE (JukeboxWindowPlayer, jukebox_window_player, JUKEBOX, WINDOW_PLAYER, GObject)


G_DEFINE_TYPE (JukeboxWindowPlayer, jukebox_window_player, G_TYPE_OBJECT)
