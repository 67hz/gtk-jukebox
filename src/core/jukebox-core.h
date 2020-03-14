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
 * \defgroup global_variables
 * \{
 */
extern void *jukebox_core_running;

extern GApplication  *jukebox_core_application;

extern ConnectionManager *conn;

// extern Jukebox_Player      *jukebox_core_player;

/** @} */ // end of group1



#endif /* ifndef __JUKEBOX_CORE_H__ */
