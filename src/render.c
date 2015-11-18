
#define _RENDER_PROC_

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "sfml.h"
#include "render.h"

sfRenderWindow* window;
sfView* mainView;
sfView* infoView;

void render_main(void) {
    
    // Create the main window and the main view
    window = sfRenderWindow_create(
        (sfVideoMode){DEFAULT_WIN_WIDTH, DEFAULT_WIN_HEIGHT, 32},
        "Territory",
        sfResize | sfClose,
        NULL
        );
        
    if (!window) return;
    
    mainView = sfView_createFromRect(
        (sfFloatRect){0, 0, DEFAULT_WIN_WIDTH * 0.80, DEFAULT_WIN_HEIGHT});
        
    sfView_zoom(mainView, 0.75);
    
    sfView_setViewport(mainView, (sfFloatRect){0, 0, 0.80, 1});
        
    sfRenderWindow_setView(window, mainView);
    
    /*** ***/
    
    // Create images
    sfImage* oceanImage = sfImage_createFromFile("res/ocean.png");
    if (!oceanImage) return;
    
    sfImage* grassImage = sfImage_createFromFile("res/grass.png");
    if (!grassImage) return;
    
    const int mapWidth = 40;
    const int mapHeight = 20;
    int map[mapWidth][mapHeight];
    sfImage* mapImage = sfImage_create(mapWidth * 16, mapHeight * 16);
    
    int r;
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            r = rand() % 2;
            map[x][y] = r;
            printf("%d", r);
            sfImage_copyImage(
                mapImage,
                r ? grassImage : oceanImage,
                x * 16,
                y * 16,
                (sfIntRect){0, 0, 16, 16},
                sfTrue);
        }
        printf("\n");
    }
    
    sfSprite* mapSprite = sfSprite_create();
    sfSprite_setTexture(
        mapSprite,
        sfTexture_createFromImage(mapImage, NULL),
        sfTrue);
        
    /*** ***/
    
    sfVector2u winDimensions;
    render_closeFlag = false;
    eventAvailable = sfFalse;
    while (sfRenderWindow_isOpen(window)) {
        eventAvailable = sfRenderWindow_pollEvent(window, &render_event);
        if (render_closeFlag) {
            render_closeFlag = false;
            sfRenderWindow_close(window);
            sfRenderWindow_destroy(window);
            return;
        }
        if (render_rescaleFlag) {
            render_rescaleFlag = false;
            winDimensions = sfRenderWindow_getSize(window);
            if (winDimensions.x < DEFAULT_WIN_WIDTH) {
                winDimensions.x = DEFAULT_WIN_WIDTH;
                sfRenderWindow_setSize(window, winDimensions);
            }
            if (winDimensions.y < DEFAULT_WIN_HEIGHT) {
                winDimensions.y = DEFAULT_WIN_HEIGHT;
                sfRenderWindow_setSize(window, winDimensions);
            }
            sfView_setSize(
                mainView,
                (sfVector2f){render_event.size.width * 0.80, render_event.size.height}
                );
            sfView_zoom(mainView, 0.75);
            sfRenderWindow_setView(window, mainView);
        }
        
        sfRenderWindow_clear(window, sfBlue);
        sfRenderWindow_drawSprite(window, mapSprite, NULL);
        sfRenderWindow_display(window);
        
        Sleep(10);
    }
}
