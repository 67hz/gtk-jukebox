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

static void
jukebox_song_player_constructed (GObject *object)
{
  /* called after init() but before regular properties passed to g_object_new () */
  printf ("DEBUG: jukebox_song_player_constructed");
}

JukeboxSongPlayer *
jukebox_song_player_new ()
{
  printf ("\nDEBUG: new jukebox created\n");
  return g_object_new (JUKEBOX_TYPE_SONG_PLAYER, NULL);
}

static void
jukebox_song_player_init (JukeboxSongPlayer *self)
{
  printf ("\nDEBUG: jukebox_song_player_init\n");
}

/**
 * Override all virtual methods here
 */
static void
jukebox_song_player_class_init (JukeboxSongPlayerClass *class)
{
/* https://developer.gnome.org/gobject/stable/howto-gobject-construction.htmlV */
/* https://developer.gnome.org/gobject/stable/chapter-gobject.html#gobject-instantiation */
  GObjectClass *object_class = G_OBJECT_CLASS (class);
  object_class->constructed = jukebox_song_player_constructed;
}
void
jukebox_song_player_load (JukeboxSongPlayer *self,
                          gchar* url)
{
  printf("\nDEBUG: loading juker with: %s\n", url);
}


/* https://developer.gnome.org/gobject/stable/howto-gobject-destruction.htm */
/* static void */
/* jukebox_song_player_dispose (GObject *gobject) {}; */

