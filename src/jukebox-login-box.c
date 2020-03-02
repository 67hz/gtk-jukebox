#include <glib.h>
#include "jukebox-login-box.h"


struct _JukeboxLoginBox
{
  GtkBox parent_class;

  /* instance members */
  /* GtkWidget *primary_label; */
  /* GtkEntry *primary_entry; */
  /* GtkWidget *secondary_label; */
  /* GtkEntry *secondary_entry; */
  GtkWidget *button;
};


G_DEFINE_TYPE(JukeboxLoginBox, jukebox_login_box, GTK_TYPE_BOX);


GtkWidget *
jukebox_login_box_new ()
{
  printf("\nDebug: new login box");
  return g_object_new (JUKEBOX_TYPE_LOGIN_BOX, NULL);
}


/**
 * update object state depending on ctor properties
 */
void
jukebox_login_box_constructed (GObject *object)
{

  JukeboxLoginBox *self = JUKEBOX_LOGIN_BOX (object);
  GtkWidget *login_box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 5);
  self->button = gtk_button_new_with_label("Login");

  /* Always chain up to parent constructed () to complete object initialization */
  G_OBJECT_CLASS (jukebox_login_box_parent_class)->constructed (object);

  gtk_box_pack_start (GTK_BOX (login_box), self->button, TRUE, TRUE, 3);
  gtk_container_add (GTK_CONTAINER (self), login_box);
  gtk_widget_show_all (GTK_WIDGET (self));
  printf("\nDebug: login box constructed\n");
}


/**
 * For composite widgets, init () creates the component widgets
 */
static void
jukebox_login_box_init (JukeboxLoginBox *self)
{
  printf("\nDebug: init loginbox\n");
}

static void
jukebox_login_box_class_init (JukeboxLoginBoxClass *class)
{
  GObjectClass *object_class = G_OBJECT_CLASS (class);
  object_class->constructed = jukebox_login_box_constructed;
}

