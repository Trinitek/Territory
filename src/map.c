
#include <stdlib.h>
#include "map.h"

worldmap* newMap(int width, int height) {
    worldmap* map = malloc(sizeof(worldmap));
    map->width = width;
    map->height = height;
    map->tiles = (maptile**) malloc(width * sizeof(maptile*));
    for (int i = 0; i < width; i++) {
        map->tiles[i] = (maptile*) malloc(height * sizeof(maptile));
    }
    generateTerrain(map);
    return map;
}

void generateTerrain(worldmap* map) {
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            map->tiles[x][y] = rand() % 2;
        }
    }
}
