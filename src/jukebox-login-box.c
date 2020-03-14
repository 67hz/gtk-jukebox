#include <glib.h>
#include <glib/gi18n.h>
#include "jukebox-login-box.h"
#include "jukebox-user.h"
#include "jukebox-types.h"

enum {
  AUTH_LOGIN_SIGNAL,
  AUTH_LOGOUT_SIGNAL,
  NUM_SIGNALS
};

static guint signals[NUM_SIGNALS] = {0, };

struct _JukeboxLoginBox
{
  GtkBin parent_class;

  /* instance members */
  GtkWidget *combo_box;
  GtkWidget *login_box; 
  GtkWidget *entry_primary;
  GtkWidget *entry_secondary;
  GtkWidget *button;
  JukeboxLoginParams login_params;
};

enum {
  SERVICE_SPOTIFY,
  SERVICE_GOOGLE,
  SERVICE_SOUNDCLOUD
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

gpointer
jukebox_login_box_get_inputs(JukeboxLoginBox *self)
{
    return &self->login_params;
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



  /* GtkWidget *login_box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 6); */
  self->login_box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 5);

  self->entry_primary = gtk_entry_new ();
  self->entry_secondary = gtk_entry_new ();

  gtk_entry_set_placeholder_text (GTK_ENTRY (self->entry_primary), "username");
  gtk_entry_set_placeholder_text (GTK_ENTRY (self->entry_secondary), "password");
  gtk_entry_set_visibility ( GTK_ENTRY (self->entry_secondary), FALSE);

  self->combo_box = gtk_combo_box_text_new ();
  gtk_combo_box_text_insert_text (GTK_COMBO_BOX_TEXT (self->combo_box), SERVICE_GOOGLE, _("Google Music"));
  gtk_combo_box_text_insert_text (GTK_COMBO_BOX_TEXT (self->combo_box), SERVICE_SPOTIFY, _("Spotify"));
  gtk_combo_box_text_insert_text (GTK_COMBO_BOX_TEXT (self->combo_box), SERVICE_SOUNDCLOUD, _("SoundCloud"));
  gtk_combo_box_set_active (GTK_COMBO_BOX (self->combo_box), 0);

  self->button = gtk_button_new_with_label (_("Login"));

  gtk_box_pack_start (GTK_BOX (self->login_box), self->entry_primary, TRUE, TRUE, 3);
  gtk_box_pack_start (GTK_BOX (self->login_box), self->entry_secondary, TRUE, TRUE, 3);
  gtk_box_pack_start (GTK_BOX (self->login_box), self->combo_box, TRUE, TRUE, 3);
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

  signals[AUTH_LOGIN_SIGNAL] =
    g_signal_new ("login_request", G_TYPE_FROM_CLASS(class),
	                     G_SIGNAL_RUN_LAST, 0, NULL, NULL, NULL,
			     G_TYPE_NONE, 0);
}


/**
 * \brief Send event back so main bus can handle login request
 *
 */
  static void
on_login_clicked (GtkButton *button, gpointer user_data)
{
  JukeboxLoginBox *self = JUKEBOX_LOGIN_BOX (user_data);

  const gchar* username = gtk_entry_get_text (GTK_ENTRY (self->entry_primary));
  const gchar* pw  = gtk_entry_get_text (GTK_ENTRY (self->entry_secondary));
  gint service_id = gtk_combo_box_get_active (GTK_COMBO_BOX (self->combo_box));
  gchar* service = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT (self->combo_box));

  self->login_params = (struct JukeboxLoginParams) {
      .username = username,
      .pw = pw,
      .service_id = service_id,
      .service = service
  };

  g_signal_emit (self, signals[AUTH_LOGIN_SIGNAL], 0, NULL);



  /* example of setting props after class init */
#if 0
  GValue val = G_VALUE_INIT;
  g_value_init (&val, G_TYPE_STRING);
  g_value_set_string (&val, "some custom service");
  g_object_set_property (G_OBJECT (user), "servicename", &val);
#endif

}
