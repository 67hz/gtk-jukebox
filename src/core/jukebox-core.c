#include "jukebox-core.h"





/**
 * \defgroup core_public_variables
 * \{
 */
void *jukebox_core_running;

ConnectionManager *conn;

/** @} */ // end of core_public_variables



/**
 * \brief The initialization of core components to JukeBox.
 */
void
jukebox_core_init (GApplication *app)
{
  static int jb_core_running;
  if (!jukebox_core_running)
    jukebox_core_running = &jb_core_running;
}




/* void jukebox_core_cleanup  (void); */
/* void jukebox_core_configure(void); */
/*  */
/* void jukebox_core_quit     (void); */

