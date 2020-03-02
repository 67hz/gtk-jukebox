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
  GtkWidget    *login_box;
  GtkWidget *entry_primary;
  GtkWidget *entry_secondary;
  GtkWidget *button;
};

G_DEFINE_TYPE(JukeboxLoginBox, jukebox_login_box, GTK_TYPE_BIN);

static void on_login_clicked   (GtkButton *button, gpointer user_data);


GtkWidget *
jukebox_login_box_new ()
{
#ifdef DEBUG
  g_message("login_box_new");
#endif
  return g_object_new (JUKEBOX_TYPE_LOGIN_BOX, NULL);
}


/**
 * update object state depending on ctor properties
 */
static void
jukebox_login_box_constructed (GObject *object)
{

  JukeboxLoginBox *self = JUKEBOX_LOGIN_BOX (object);
  /* Always chain up to parent constructed () to complete object initialization */
  G_OBJECT_CLASS (jukebox_login_box_parent_class)->constructed (object);

  /* jukebox_login_box_setup_block_handlers (self); */
  g_signal_connect (self->button, "clicked", G_CALLBACK (on_login_clicked), self);



#ifdef DEBUG
  g_message("login_box_constructed");
#endif
}


static void
jukebox_login_box_finalize(GObject *object)
{
  /* JukeboxLoginBox *self = JUKEBOX_LOGIN_BOX (object); */
  G_OBJECT_CLASS (jukebox_login_box_parent_class)->finalize (object);
}

/**
 * For composite widgets, init () creates the component widgets
 */
static void
jukebox_login_box_init (JukeboxLoginBox *self)
{
#ifdef DEBUG
  g_message("loginbox_init");
#endif

  /* GtkWidget *login_box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 5); */
  self->login_box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 5);

  self->entry_primary = gtk_entry_new ();
  self->entry_secondary = gtk_entry_new ();

  gtk_entry_set_placeholder_text (GTK_ENTRY (self->entry_primary), "username");
  gtk_entry_set_placeholder_text (GTK_ENTRY (self->entry_secondary), "password");
  self->button = gtk_button_new_with_label ("Login");


  gtk_entry_set_visibility ( GTK_ENTRY (self->entry_secondary), FALSE);
  gtk_box_pack_start (GTK_BOX (self->login_box), self->entry_primary, TRUE, TRUE, 3);
  gtk_box_pack_start (GTK_BOX (self->login_box), self->entry_secondary, TRUE, TRUE, 3);
  gtk_box_pack_start (GTK_BOX (self->login_box), self->button, TRUE, TRUE, 3);

  gtk_container_add (GTK_CONTAINER (self), self->login_box);
  gtk_widget_show_all (GTK_WIDGET (self));



}

static void
jukebox_login_box_class_init (JukeboxLoginBoxClass *class)
{
  GObjectClass *object_class = G_OBJECT_CLASS (class);
  object_class->constructed = jukebox_login_box_constructed;
  object_class->finalize = jukebox_login_box_finalize;
}

static void
on_login_clicked (GtkButton *button, gpointer user_data)
{
  JukeboxLoginBox *self = JUKEBOX_LOGIN_BOX (user_data);
  const gchar* user = gtk_entry_get_text (GTK_ENTRY (self->entry_primary));
  const gchar* pw  = gtk_entry_get_text (GTK_ENTRY (self->entry_secondary));
  g_message("login submitted user: %s", user);
  g_message("login submitted pw: %s", pw);
}
