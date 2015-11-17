
#define _RENDER_PROC_

#include <stdio.h>
#include <windows.h>
#include "SFML/Graphics.h"
#include "render.h"

void render_main(void) {
    
    // Create the main window and the main view
    sfRenderWindow* window = sfRenderWindow_create(
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
    sfView* mainView = sfView_createFromRect(
        (sfFloatRect){
            0,
            0,
            DEFAULT_WIN_WIDTH,
            DEFAULT_WIN_HEIGHT
        });
    sfView_zoom(mainView, 0.25);
    sfRenderWindow_setView(window, mainView);
    
    sfEvent event;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            switch (event.type) {
                case sfEvtClosed:
                    sfRenderWindow_close(window);
                    break;
                case sfEvtResized:
                    sfView_setSize(
                        mainView,
                        (sfVector2f){
                            event.size.width,
                            event.size.height
                        }
                    );
                    sfView_zoom(mainView, 0.25);
                    sfRenderWindow_setView(window, mainView);
                    break;
            }
        }
        
        sfRenderWindow_clear(window, sfBlue);
        sfRenderWindow_display(window);
    }
}
