#include "jukebox-song-player.h"
#include "gst/gstclock.h"
#include "gst/gstelement.h"
#include "gst/gstmessage.h"
#include <glib.h>
#include <gst/gst.h>

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
#ifdef DEBUG
  g_message ("jukebox_song_player_constructed");
#endif
}

JukeboxSongPlayer *
jukebox_song_player_new ()
{
#ifdef DEBUG
  g_message ("jukebox__song_player_new");
#endif
  return g_object_new (JUKEBOX_TYPE_SONG_PLAYER, NULL);
}



static void
jukebox_song_player_init (JukeboxSongPlayer *self)
{
#ifdef DEBUG
  g_message ("jukebox_song_player_init");
#endif
}



void
jukebox_song_player_load (JukeboxSongPlayer *self,
                          gchar* url)
{
#ifdef DEBUG
  g_message("jukebox_song_player_load: %s", url);
#endif
}


static void
jukebox_song_player_dispose (GObject *object)
{
  /* JukeboxSongPlayer *self = JUKEBOX_SONG_PLAYER (object); */
  /* g_clear_object (&self->grid); */

  G_OBJECT_CLASS (jukebox_song_player_parent_class)->dispose (object);
}

/* https://developer.gnome.org/gobject/stable/howto-gobject-destruction.htm */
/* static void */
/* jukebox_song_player_dispose (GObject *gobject) {}; */

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
  object_class->dispose = jukebox_song_player_dispose;
}

/**
 * GST test - move logic to separate class
 *
 *
 */
void
jukebox_gst_test (int argc, char **argv)
{
  GstElement        *pipeline;
  GstBus            *bus;
  GstMessage        *msg;

  /* initialize streamer */
  gst_init (&argc, &argv);

  /* build the pipeline */
  pipeline =
    gst_parse_launch
    ("playbin uri=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm",
     NULL);
  /* pipeline = */
  /*   gst_parse_launch */
  /*   ("playbin uri:http://open.spotify.com/track/6rqhFgbbKwnb9MLmUQDhG6", NULL); */


  /* start playing */
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  /* wait until error or EOS */
  bus = gst_element_get_bus (pipeline);
  msg =
    gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE,
        GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

  /* Free resources */
  if (msg != NULL)
    gst_message_unref (msg);
  gst_object_unref (bus);
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (pipeline);
}



