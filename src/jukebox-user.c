#include "jukebox-user.h"
#include <glib.h>


/**
 * 
 * storing password here, need to move to a read from config file
 */
struct _JukeboxUser
{
  GObject parent_instance;

  gchar *service_name;
  gchar *user_name;
  gchar *user_pw;

  gboolean is_logged_in;
};


G_DEFINE_TYPE (JukeboxUser, jukebox_user, G_TYPE_OBJECT);


typedef enum
{
  PROP_SERVICE = 1,
  PROP_USER_NAME,
  PROP_PW,
  N_PROPERTIES
} JukeboxUserProperty;

static GParamSpec *obj_properties[N_PROPERTIES] = { NULL, };


static void
jukebox_user_set_property (GObject      *object,
                           guint         property_id,
                           const GValue *value,
                           GParamSpec   *pspec)
{
  JukeboxUser *self = JUKEBOX_USER (object);

  switch ((JukeboxUserProperty) property_id)
  {
    case PROP_SERVICE:
      g_free (self->service_name);
      self->service_name = g_value_dup_string (value);
      g_print ("Music Service: %s\n", self->service_name);
      break;

    case PROP_USER_NAME:
      g_free (self->user_name);
      self->user_name = g_value_dup_string (value);
      g_print ("User: %s\n", self->user_name);
      break;

    case PROP_PW:
      g_free (self->user_pw);
      self->user_pw = g_value_dup_string (value);
      g_print ("Pw store: %s\n", self->user_pw);
      break;

    default:
      /* no other properties */
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
  }
}

static void
jukebox_user_get_property (GObject    *object,
                           guint        property_id,
                           GValue      *value,
                           GParamSpec  *pspec)
{
  JukeboxUser *self = JUKEBOX_USER (object);

  switch ((JukeboxUserProperty) property_id)
  {
    case PROP_SERVICE:
      g_value_set_string (value, self->service_name);
      break;

    case PROP_USER_NAME:
      g_value_set_string (value, self->user_name);
      break;

    case PROP_PW:
      g_value_set_string (value, self->user_pw);
      break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
jukebox_user_init (JukeboxUser *self)
{
  g_message ("jukebox_user_init");
}

static void
jukebox_user_constructed (GObject *object)
{
  g_message ("jukebox_user_constructed");
}

static void
jukebox_user_finalize (GObject *object)
{
  g_message ("jukebox_user_finalize");
}


/**
 * register object's properties
 */
static void
jukebox_user_class_init (JukeboxUserClass * klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->set_property = jukebox_user_set_property;
  object_class->get_property = jukebox_user_get_property;
  object_class->constructed = jukebox_user_constructed;
  object_class->finalize = jukebox_user_finalize;

  obj_properties[PROP_SERVICE] =
    g_param_spec_string ("servicename",
        "Music Service",
        "Name of the service to play music from.",
        NULL,
        G_PARAM_READWRITE);

  obj_properties[PROP_USER_NAME] =
    g_param_spec_string ("username",
        "User name",
        "User to log in",
        NULL,
        G_PARAM_READWRITE);

  obj_properties[PROP_PW] =
    g_param_spec_string ("password",
        "user password",
        "user's password for music service",
        NULL,
        G_PARAM_WRITABLE);

  g_object_class_install_properties (object_class,
                                     N_PROPERTIES,
                                     obj_properties);

}
