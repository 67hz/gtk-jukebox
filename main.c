#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>


/* _t is POSIX compliant */
typedef unsigned short int mytype_t;

static int counter = 0;

static void
greet (GtkWidget *widget, gpointer data)
{
    g_print ("Hello, and welcome to dr.funkenstein\n");
    g_print ("%s clicked %d times \n", (char*)data, ++counter);
}

static void
destroy (GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main
(int argc, char* argv[]) 
{
    GtkWidget *win;
    GtkWidget *button;
    /* init GTK+ libs passing in cli params */
    gtk_init(&argc, &argv);

    /* standard framed window opts: _POPUP */
    win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    button = gtk_button_new_with_label ("Analyze Me");

    gtk_container_add (GTK_CONTAINER (win), button);

    g_signal_connect (win, "destroy", G_CALLBACK (destroy), NULL);
    g_signal_connect (GTK_OBJECT (button), "clicked", G_CALLBACK (greet), "button");


    gtk_widget_show_all (win);
    gtk_main ();

    return 0; 
}
