#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include "connection_manager.h"
#include "jukebox-song-player.h"
#include "jukebox-login-box.h"
#include "jukebox-user.h"

#define APP_TITLE "Jukebox"

/**
 * \brief hold the essentials in a global
 * struct. not sure if this is a good idea yet
 */
typedef struct jukebox_core {
  JukeboxUser *user;
  ConnectionManager *conn;
} jukebox_core;

static void
login_user (JukeboxLoginBox *login_box, GPtrArray *userData)
{

    JukeboxLoginParams *params = (struct JukeboxLoginParams *)
        jukebox_login_box_get_inputs(login_box);

    g_message("servce: %s", (gchar *)params->username);


    if (!userData)
        g_message("no user data");
    else
        g_message("main got login user signal");
}

static void
destroy ()
{
  gtk_main_quit();
}

int main
(int argc, char* argv[]) 
{
  GtkWidget                  *window;
  GtkWidget                  *grid;
  GtkWidget                  *close_button;
  GtkWidget                  *login_box;
  JukeboxSongPlayer          *juker;
  /* ConnectionManager          *myconn; */

  /* init GTK+ libs passing in cli params */
  gtk_init (&argc, &argv);

  char playlist[] = "http://dummy.restapiexample.com/api/v1/employees";
  juker = jukebox_song_player_new ();
  jukebox_song_player_load (juker, playlist);



  // sets up a new CURL object
  /* myconn = connection_new (playlist); */
  /* myconn->display_info (); */
  /* connection_request (myconn); */
  /* connection_close (myconn); */
  /* jukebox_gst_test (argc, argv); */

  login_box = jukebox_login_box_new ();


  /* standard framed window opts: _POPUP */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), APP_TITLE);

  g_signal_connect (window, "destroy", G_CALLBACK (destroy), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (window), 100);

  grid = gtk_grid_new ();
  /* pack the container grid in the window */
  gtk_container_add (GTK_CONTAINER (window), grid);

  close_button = gtk_button_new_with_label ("Close it down");
  g_signal_connect_swapped (close_button, "clicked", G_CALLBACK (gtk_widget_destroy), window);

  g_signal_connect (login_box, "login_request", G_CALLBACK (login_user), login_box);
  gtk_grid_attach (GTK_GRID (grid), close_button, 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID (grid), login_box, 0, 2, 2, 5);


  gtk_widget_show_all (window);
  gtk_main ();

  return 0; 
}
