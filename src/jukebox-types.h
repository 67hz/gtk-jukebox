/**
 * jukebox-types.h
 *
 * \brief Common typedefs, enums, et.al
 */

#ifndef __JUKEBOX_TYPES_H__
#define __JUKEBOX_TYPES_H__

#include <glib.h>


/**
 * \typedef struct JukeboxLoginParams
 * \brief A type definition for containment of login credentials.
 */
typedef struct JukeboxLoginParams {
  const gchar *username;
  const gchar *pw;
  gchar *service;
  gint service_id;
} JukeboxLoginParams;


#endif /* ifndef __JUKEBOX_TYPES_H__ */
