
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <process.h>
#include "SFML/Graphics.h"
#include "render.h"

#define CAPTION "Territory"

int main(void) {
    
    char errstring[256];
    
    // Spawn rendering thread
    uintptr_t renderThread = _beginthread(render_main, 0, NULL);
    if (renderThread == -1L) {
        snprintf(errstring, 256, "Can't create render thread: %x", errno);
        MessageBox(NULL, errstring, CAPTION, 0x10);
        return 1;
    }
    
    while (1);
    
    // Create window
    sfRenderWindow* window = sfRenderWindow_create((sfVideoMode){DEFAULT_WIN_WIDTH, DEFAULT_WIN_HEIGHT, 32}, "Territory", sfResize | sfClose, NULL);
    if (!window)
        return 1;
    sfView* mainView = sfView_createFromRect((sfFloatRect){0, 0, DEFAULT_WIN_WIDTH, DEFAULT_WIN_HEIGHT});
    sfView_zoom(mainView, 0.25);
    sfRenderWindow_setView(window, mainView);
    
    printf("Center of mainView = %f, %f\n", sfView_getCenter(mainView).x, sfView_getCenter(mainView).y);
    
    // Create text
    sfFont* font = sfFont_createFromFile("res/OpenSans-Light.ttf");
    if (!font)
        return 1;
    sfText* text = sfText_create();
    sfText_setString(text, "Hello world!");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, (sfVector2f){25, 60});
    
    // Create images
    sfImage* oceanImage = sfImage_createFromFile("res/ocean.png");
    if (!oceanImage)
        return 1;
    
    sfImage* grassImage = sfImage_createFromFile("res/grass.png");
    if (!grassImage)
        return 1;
    
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
    
    
    // Render loop
    sfEvent event;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtResized) {
                printf("Window resized!\n");
                sfView_setSize(mainView, (sfVector2f){event.size.width, event.size.height});
                sfView_zoom(mainView, 0.25);
                sfRenderWindow_setView(window, mainView);
            }
        }
        
        // Draw stuff
        sfRenderWindow_clear(window, sfBlue);
        
        for (int x = 0; x < mapWidth; x++) {
            for (int y = 0; y < mapHeight; y++) {
                sfRenderWindow_drawSprite(
                    window,
                    mapSprite,
                    NULL);
            }
        }
        
        sfRenderWindow_drawText(window, text, NULL);
        
        // Redraw
        sfRenderWindow_display(window);
    }
    
    // Cleanup
    sfRenderWindow_destroy(window);
    
    return 0;
}
