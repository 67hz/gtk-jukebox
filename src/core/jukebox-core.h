/**
 * jukebox-core.h
 * 
 * \brief The core init process for jb.
 * This should read user creds, request auth, ...
 */

#ifndef __JUKEBOX_CORE_H__
#define __JUKEBOX_CORE_H__
#include <glib.h>
#include <gio/gio.h>
#include "connection_manager.h"

/**
 * \defgroup core_global_variables
 * \{
 */
extern void *jukebox_core_running;

extern GApplication  *jukebox_core_application;

extern ConnectionManager *conn;

// extern Jukebox_Player      *jukebox_core_player;

/** @} */ // end of core_global_variables


/**
 * \defgroup core_functions
 * \{
 */
// void jukebox_core_init     (GApplication *app);
void jukebox_core_init     ();
void jukebox_core_cleanup  (void);
void jukebox_core_configure(void);

void jukebox_core_quit     (void);

/** @} */ // end of core_functions



#endif /* ifndef __JUKEBOX_CORE_H__ */
