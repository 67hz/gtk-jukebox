#include "jukebox-core.h"





/**
 * \defgroup public_variables
 * \{
 */
void *jukebox_core_running;

ConnectionManager *conn;

/** @} */ // end of group1



void
jukebox_core_init (void)
{
    static int jb_core_running;
    if (!jukebox_core_running)
        jukebox_core_running = &jb_core_running;
}

