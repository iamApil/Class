#include <stdio.h>
#include <graphics.h>
#include <math.h>

int midx, midy; // Global variables for midpoint of the window

void scale();

int main()
{
    int gd = DETECT, gm;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, " ");

    // Calculate midpoint of the window
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;

    scale(); // Call the scale function

    getch();
    closegraph();
    return 0;
}

void scale()
{
    int sx, sy, sz;

    // Original coordinates of the object
    int x1 = midx + 50;
    int y1 = midy - 100;
    int x2 = midx + 100;
    int y2 = midy - 50;

    // Draw coordinate axes
    line(100, 0, 100, getmaxy());
    line(100, getmaxy(), getmaxx(), getmaxy());

    // Draw the original object
    bar3d(x1, y1, x2, y2, 20, 1);

    printf("Before scaling\n");
    printf("Enter scaling factors (sx sy sz): ");
    scanf("%d %d %d", &sx, &sy, &sz);
    printf("After scaling\n");

    // Calculate new coordinates after scaling
    int newX1 = midx + (x1 - midx) * sx;
    int newY1 = midy - (midy - y1) * sy;
    int newX2 = midx + (x2 - midx) * sx;
    int newY2 = midy - (midy - y2) * sy;

    // Draw the scaled object
    bar3d(newX1, newY1, newX2, newY2, 20 * sz, 1);
}
