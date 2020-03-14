#ifndef __JUKEBOX_CONFIG_H__
#define __JUKEBOX_CONFIG_H__


#include <glib.h>
#include <glib/gprintf.h>
#include <stdlib.h>


void
jukebox_get_configuration ()
{
  g_autoptr(GError) error = NULL;
  g_autoptr(GKeyFile) key_file = g_key_file_new ();

  if (!g_key_file_load_from_file (key_file, "example.ini", G_KEY_FILE_NONE, &error))
  {
    if (!g_error_matches (error, G_FILE_ERROR, G_FILE_ERROR_NOENT))
      g_warning("Error loading configuration file: %s", error->message);
    return;
  }

  g_autofree gchar *val = g_key_file_get_string (key_file, "Group Name", "SomeKey", &error);
  g_printf("test\n\n\n");
  if (val == NULL &&
      !g_error_matches (error, G_KEY_FILE_ERROR, G_KEY_FILE_ERROR_KEY_NOT_FOUND))
  {
    g_warning ("Could not find key in configuration file: %s", error->message);
    return;
  }

  else if (val == NULL)
  {
    val = g_strdup("default-value");
  }

  g_printf("Found value: %s", val);

  exit(EXIT_SUCCESS);

}

#endif /* ifndef __JUKEBOX_CONFIG_H__ */
