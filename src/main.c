
#include <stdlib.h>
#include <stdio.h>
#include "SFML/Graphics.h"

int main(void) {
    
    // Create window
    sfRenderWindow* window = sfRenderWindow_create((sfVideoMode){640, 480, 32}, "Territory", sfResize | sfClose, NULL);
    if (!window)
        return 1;
    
    // Create text
    sfFont* font = sfFont_createFromFile("res/OpenSans-Light.ttf");
    if (!font)
        return 1;
    sfText* text = sfText_create();
    sfText_setString(text, "Hello world!");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, (sfVector2f){25, 60});
    
    // Create sprites
    sfTexture* texture = sfTexture_createFromFile("res/ocean.png", NULL);
    if (!texture)
        return 1;
    sfSprite* oceanSprite = sfSprite_create();
    sfSprite_setTexture(oceanSprite, texture, sfTrue);
    texture = sfTexture_createFromFile("res/grass.png", NULL);
    if (!texture)
        return 1;
    sfSprite* grassSprite = sfSprite_create();
    sfSprite_setTexture(grassSprite, texture, sfTrue);
    
    const int mapWidth = 40;
    const int mapHeight = 20;
    int map[mapWidth][mapHeight];
    
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            map[x][y] = rand() % 2;
            printf("%d", map[x][y]);
        }
        printf("\n");
    }
    
    
    // Render loop
    sfEvent event;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        
        // Draw stuff
        sfRenderWindow_clear(window, sfBlue);
        
        for (int x = 0; x < mapWidth; x++) {
            for (int y = 0; y < mapHeight; y++) {
                sfSprite_setPosition(
                    map[x][y] ? grassSprite : oceanSprite,
                    (sfVector2f){x * 16, y * 16});
                sfRenderWindow_drawSprite(
                    window,
                    map[x][y] ? grassSprite : oceanSprite,
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
