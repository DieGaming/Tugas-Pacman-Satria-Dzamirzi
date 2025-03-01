#ifndef MAP_H
#define MAP_H

const int rows = 21;
const int cols = 21;
const float cellSize = 20.0f;

extern char map[rows][cols + 1];

void initMap();
void drawMap();
void drawCell(float x, float y, float size, float r, float g, float b);
int getRows();
int getCols();
float getCellSize();

#endif
