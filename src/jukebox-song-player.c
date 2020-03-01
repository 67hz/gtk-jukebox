#include "jukebox-song-player.h"
#include <glib.h>

/* Private structure definition */
/* typedef struct { */
/*   gchar *filename; */
/* } JukeboxSongPlayerPrivate; */
/*  */
/**
 * Forward definitions
 */
struct _JukeboxSongPlayer
{
  GObject parent_instance;

  /* Other members, including private data */
  gchar *filename;
};

G_DEFINE_TYPE (JukeboxSongPlayer, jukebox_song_player, G_TYPE_OBJECT);

/* static void */
/* jukebox_song_player_constructed (GObject *object) */
/* { */
/*   #<{(| called after init() but before regular properties passed to g_object_new () |)}># */
/* } */

static void
jukebox_song_player_init (JukeboxSongPlayer *self)
{
}

static void
jukebox_song_player_class_init (JukeboxSongPlayerClass *class)
{
/* https://developer.gnome.org/gobject/stable/howto-gobject-construction.htmlV */
  /* GObject *object_class = G_OBJECT_CLASS (class); */
  /* object_class->constructed = jukebox_song_player_constructed; */
}
