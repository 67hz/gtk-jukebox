#ifndef __JUKEBOX_SONG_PLAYER_H__
#define __JUKEBOX_SONG_PLAYER_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

/**
 * Type declaration
 */
#define JUKEBOX_TYPE_SONG_PLAYER (jukebox_song_player_get_type ())
G_DECLARE_FINAL_TYPE (JukeboxSongPlayer, jukebox_song_player, JUKEBOX, SONG_PLAYER, GObject)

/**
 * Method definitions
 */
JukeboxSongPlayer         *jukebox_song_player_new        (void);
void                       jukebox_song_player_load       (JukeboxSongPlayer *self,
                                                           gchar* url);

G_END_DECLS


#endif /* __JUKEBOX_SONG_PLAYER_H__ */
