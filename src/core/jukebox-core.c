#include "jukebox-core.h"
#include "jukebox-user.h"
#include "../config/config.h"


/**
 * \defgroup core_public_variables
 * \{
 */
void *jukebox_core_running;

GApplication  *jukebox_core_application;
JukeboxUser   *jukebox_user;
ConnectionManager *jukebox_conn;

/** @} */ // end of core_public_variables



/**
 * \brief The initialization of core components to JukeBox.
 */
void
jukebox_core_init ()
{
  static int jb_core_running;
  if (!jukebox_core_running)
  {
    g_message("jukebox_core_running");
    jukebox_core_running = &jb_core_running;

    /* test .ini read */
    jukebox_get_configuration ();
  }
}



/* void jukebox_core_cleanup  (void); */
/* void jukebox_core_configure(void); */
/*  */
/* void jukebox_core_quit     (void); */
