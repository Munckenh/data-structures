#ifndef QUADTREE_H
#define QUADTREE_H

#include <stdbool.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point top_left;
    int height;
    int width;
} Rectangle;

typedef struct quadtree {
    Point* points;
    Rectangle boundary;
    int capacity;
    int count;
    struct quadtree* northwest;
    struct quadtree* northeast;
    struct quadtree* southwest;
    struct quadtree* southeast;
    bool is_divided;
} Quadtree;

bool insert(Quadtree*, Point);
Quadtree* create(Rectangle, int);
void subdivide(Quadtree*);
bool contains(Rectangle, Point);
bool intersects(Rectangle, Rectangle);

#endif