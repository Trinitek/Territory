
typedef enum {
    OCEAN,
    GRASS
} maptile;

typedef struct {
    int width;
    int height;
    maptile** tiles;
} worldmap;

worldmap* newMap(int width, int height);
void generateTerrain(worldmap* map);
