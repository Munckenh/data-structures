#include <stdlib.h>
#include <stdbool.h>
#include "quadtree.h"

void subdivide(Quadtree* qt) {
    Point top_left = qt->boundary.top_left;
    int new_height = qt->boundary.height / 2;
    int new_width = qt->boundary.width / 2;

    // Handle odd widths and heights
    int extra_height = qt->boundary.height % 2;
    int extra_width = qt->boundary.width % 2;

    qt->northwest = create((Rectangle){top_left, new_height, new_width}, qt->capacity);
    qt->northeast = create((Rectangle){(Point){top_left.x + new_width, top_left.y}, new_height, new_width + extra_width}, qt->capacity);
    qt->southwest = create((Rectangle){(Point){top_left.x, top_left.y + new_height}, new_height + extra_height, new_width}, qt->capacity);
    qt->southeast = create((Rectangle){(Point){top_left.x + new_width, top_left.y + new_height}, new_height + extra_height, new_width + extra_width}, qt->capacity);
    qt->is_divided = true;
}

bool contains(Rectangle rect, Point point) {
    if (rect.top_left.x <= point.x &&
        rect.top_left.x + rect.width >= point.x &&
        rect.top_left.y <= point.y &&
        rect.top_left.y + rect.height >= point.y) {
        return true;
    }
    return false;
}

bool intersects(Rectangle rect, Rectangle range) {
    if (rect.top_left.x + rect.width < range.top_left.x ||
        range.top_left.x + range.width < rect.top_left.x ||
        rect.top_left.y + rect.height < range.top_left.y ||
        range.top_left.y + range.height < rect.top_left.y) {
        return false;
    }
    return true;
}

bool insert(Quadtree* qt, Point point) {
    if (!contains(qt->boundary, point))
        return false;
    if (qt->count < qt->capacity && !qt->is_divided) {
        qt->points[qt->count++] = point;
        return true;
    }
    if (!qt->is_divided) {
        subdivide(qt);
        for (int i = 0; i < qt->count; i++) {
            if (insert(qt->northeast, qt->points[i]))
                continue;
            if (insert(qt->northwest, qt->points[i]))
                continue;
            if (insert(qt->southeast, qt->points[i]))
                continue;
            insert(qt->southwest, qt->points[i]);
        }
        qt->count = 0;
    }
    if (insert(qt->northeast, point))
        return true;
    if (insert(qt->northwest, point))
        return true;
    if (insert(qt->southeast, point))
        return true;
    if (insert(qt->southwest, point))
        return true;
    return false;
}

Quadtree* create(Rectangle boundary, int capacity) {
    Quadtree* qt = (Quadtree*)malloc(sizeof(Quadtree));
    qt->points = (Point*)malloc(sizeof(Point) * capacity);
    qt->boundary = boundary;
    qt->capacity = capacity;
    qt->count = 0;
    qt->northwest = NULL;
    qt->northeast = NULL;
    qt->southwest = NULL;
    qt->southeast = NULL;
    qt->is_divided = false;
    return qt;
}