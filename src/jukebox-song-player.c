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



