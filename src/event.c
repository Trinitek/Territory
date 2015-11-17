
#define _EVENT_PROC_

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "sfml.h"
#include "render.h"
#include "event.h"

volatile sfEvent event;
volatile sfBool eventAvailable;

void event_main(void) {
    while (true) {
        if (eventAvailable) {
            switch (event.type) {
                case sfEvtClosed:
                    closeMainWindow();
                    break;
            }
        }
        Sleep(10);
    }
}
