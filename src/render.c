
#define _RENDER_PROC_

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "sfml.h"
#include "render.h"

sfRenderWindow* window;
sfView* mainView;
sfEvent event;
volatile bool closeFlag;
volatile sfBool eventAvailable;

void render_main(void) {
    
    // Create the main window and the main view
    window = sfRenderWindow_create(
        (sfVideoMode){
            DEFAULT_WIN_WIDTH,
            DEFAULT_WIN_HEIGHT,
            32
        },
        "Territory",
        sfResize | sfClose,
        NULL
        );
    if (!window) return;
    mainView = sfView_createFromRect(
        (sfFloatRect){
            0,
            0,
            DEFAULT_WIN_WIDTH,
            DEFAULT_WIN_HEIGHT
        });
    sfView_zoom(mainView, 0.25);
    sfRenderWindow_setView(window, mainView);
    
    closeFlag = false;
    eventAvailable = sfFalse;
    while (sfRenderWindow_isOpen(window)) {
        eventAvailable = sfRenderWindow_pollEvent(window, &event);
        if (closeFlag) {
            closeFlag = false;
            sfRenderWindow_close(window);
            sfRenderWindow_destroy(window);
        }
        
        sfRenderWindow_clear(window, sfBlue);
        sfRenderWindow_display(window);
        
        Sleep(10);
    }
}

void closeMainWindow(void) {
    closeFlag = true;
}
