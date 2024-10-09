#include <assert.h>
#include "quadtree.h"

void test() {
    // Test contains()
    assert(contains((Rectangle){(Point){0, 0}, 100, 100}, (Point){30, 80}));
    assert(contains((Rectangle){(Point){0, 0}, 100, 100}, (Point){100, 100}));
    assert(contains((Rectangle){(Point){0, 0}, 100, 100}, (Point){0, 0}));
    assert(!contains((Rectangle){(Point){0, 0}, 100, 100}, (Point){101, 100}));
    assert(!contains((Rectangle){(Point){0, 0}, 100, 100}, (Point){-1, 0}));

    // Test intersects()
    assert(intersects((Rectangle){(Point){0, 0}, 100, 100}, (Rectangle){(Point){30, 60}, 100, 100}));
    assert(intersects((Rectangle){(Point){0, 0}, 100, 100}, (Rectangle){(Point){100, 100}, 2, 2}));
    assert(!intersects((Rectangle){(Point){0, 0}, 100, 100}, (Rectangle){(Point){-10, -10}, 5, 5}));
    assert(!intersects((Rectangle){(Point){0, 0}, 100, 100}, (Rectangle){(Point){0, -10}, 9, 100}));

    Quadtree* quadtree = create((Rectangle){(Point){0, 0}, 10, 10}, 2);
    insert(quadtree, (Point){1, 1});
    insert(quadtree, (Point){2, 2});
    insert(quadtree, (Point){5, 7});
}

int main() {
    test();
    return 0;
}