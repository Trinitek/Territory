
#define _EVENT_PROC_

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "sfml.h"
#include "render.h"
#include "event.h"

void event_main(void) {
    while (true) {
        if (eventAvailable) {
            switch (render_event.type) {
                case sfEvtClosed:
                    render_closeFlag = true;
                    break;
                case sfEvtResized:
                    render_rescaleFlag = true;
                    break;
            }
        }
        Sleep(10);
    }
}
