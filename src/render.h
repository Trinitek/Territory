
#ifndef _RENDER_H_
#define _RENDER_H_

#include <stdbool.h>

#define DEFAULT_WIN_WIDTH 800
#define DEFAULT_WIN_HEIGHT 600

volatile sfBool eventAvailable;
volatile bool render_closeFlag;
volatile bool render_rescaleFlag;

#ifndef _RENDER_PROC_

    volatile const sfEvent render_event;

    void render_main(void* arg);

#endif

#ifdef _RENDER_PROC_
#undef _RENDER_PROC_
    
    sfEvent render_event;

#endif

#endif
