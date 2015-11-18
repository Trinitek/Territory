
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <process.h>
#include "sfml.h"
#include "render.h"
#include "event.h"

#define CAPTION "Territory"

int main(void) {
    
    char errstring[256];
    
    // Spawn rendering thread
    uintptr_t renderThread = _beginthread(render_main, 0, NULL);
    if (renderThread == -1L) {
        snprintf(errstring, 256, "Cannot create render thread: 0x%x", errno);
        MessageBox(NULL, errstring, CAPTION, 0x10);
        return 1;
    }
    
    // Spawn event handling thread
    uintptr_t eventThread = _beginthread(event_main, 0, NULL);
    if (eventThread == -1L) {
        snprintf(errstring, 256, "Cannot create event handler thread: 0x%x", errno);
        MessageBox(NULL, errstring, CAPTION, 0x10);
        return 1;
    }
    
    while (1) Sleep(10);
    
    return 0;
}
