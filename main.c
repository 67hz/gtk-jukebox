#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include "connection_manager.h"
#include "jukebox-song-player.h"
#include "jukebox-login-box.h"

static int counter = 0;

static void greet (GtkWidget *widget, gpointer data)
{
  g_print ("%s clicked %d times \n", (char*)data, ++counter);
  gtk_widget_destroy(widget);
}

/* destroy (GtkWidget *widget, gpointer data) */
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
  GtkWidget                  *button;
  GtkWidget                  *close_button;
  JukeboxSongPlayer          *juker;

  char playlist[] = "http://dummy.restapiexample.com/api/v1/employees";

  juker = jukebox_song_player_new ();
  jukebox_song_player_load (juker, playlist);

  ConnectionManager *myconn;

  // sets up a new CURL object
  myconn = connection_new (playlist);

  myconn->display_info ();

  printf ("curling url: %s", myconn->req);
  connection_request (myconn);

  /* jukebox_gst_test (argc, argv); */

  connection_close (myconn);




  /* init GTK+ libs passing in cli params */
  gtk_init (&argc, &argv);

  /* standard framed window opts: _POPUP */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Grid");
  g_signal_connect (window, "destroy", G_CALLBACK (destroy), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (window), 100);

  grid = gtk_grid_new ();

  /* pack the container grid in the window */
  gtk_container_add (GTK_CONTAINER (window), grid);

  button = gtk_button_new_with_label ("Analyze Me");
  g_signal_connect (button, "clicked", G_CALLBACK (greet), "button");



  close_button = gtk_button_new_with_label ("Close it down");
  g_signal_connect_swapped (close_button, "clicked", G_CALLBACK (gtk_widget_destroy), window);




  /* place the first button in grid cell (0,0) and make it fill
   * one cell horizontally and vertically (no spanning)
   */
  gtk_grid_attach (GTK_GRID (grid), button, 0, 2, 1, 1);

  /* place @ (0,1) and span 2 cols, 1 row */
  gtk_grid_attach (GTK_GRID (grid), close_button, 1, 2, 1, 1);



  /* gtk_widget_show (button); */
  gtk_widget_show_all (window);
  gtk_main ();

  return 0; 
}
