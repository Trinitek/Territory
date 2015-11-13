
#include "SFML/Graphics.h"

int main(void) {
    
    // Create window
    sfVideoMode mode = {640, 480, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "Territory", sfResize | sfClose, NULL);
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
    
    // Render loop
    sfEvent event;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        
        // Draw stuff
        sfRenderWindow_clear(window, sfBlue);
        
        sfRenderWindow_drawText(window, text, NULL);
        
        // Redraw
        sfRenderWindow_display(window);
    }
    
    // Cleanup
    sfRenderWindow_destroy(window);
    
    return 0;
}
