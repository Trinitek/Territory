
#define _RENDER_PROC_

#include <stdio.h>
#include <windows.h>
#include "SFML/Graphics.h"
#include "render.h"

void render_main(render_instance* instance) {
    
    // Create the main window and the main view
    instance->window = sfRenderWindow_create(
        (sfVideoMode){
            DEFAULT_WIN_WIDTH,
            DEFAULT_WIN_HEIGHT,
            32
        },
        "Territory",
        sfResize | sfClose,
        NULL
        );
    if (!instance->window) return;
    instance->mainView = sfView_createFromRect(
        (sfFloatRect){
            0,
            0,
            DEFAULT_WIN_WIDTH,
            DEFAULT_WIN_HEIGHT
        });
    sfView_zoom(instance->mainView, 0.25);
    sfRenderWindow_setView(instance->window, instance->mainView);
    
    while (sfRenderWindow_isOpen(instance->window)) {
        while (sfRenderWindow_pollEvent(instance->window, &instance->event)) {
            switch (instance->event.type) {
                case sfEvtClosed:
                    sfRenderWindow_close(instance->window);
                    break;
                case sfEvtResized:
                    sfView_setSize(
                        instance->mainView,
                        (sfVector2f){
                            instance->event.size.width,
                            instance->event.size.height
                        }
                    );
                    sfView_zoom(instance->mainView, 0.25);
                    sfRenderWindow_setView(instance->window, instance->mainView);
                    break;
            }
        }
        
        sfRenderWindow_clear(instance->window, sfBlue);
        sfRenderWindow_display(instance->window);
    }
}
