#include <graphics.h>
#include <stdio.h>

// flood fill algorithm
void flood(int x, int y, int new_col, int bg_col)
{
    // check current pixel is old_color or not
    if (getpixel(x, y) == bg_col)
    {

        // put new pixel with new color
        putpixel(x, y, new_col);

        // recursive call for bottom pixel fill
        flood(x + 1, y, new_col, bg_col);

        // recursive call for top pixel fill
        flood(x - 1, y, new_col, bg_col);

        // recursive call for right pixel fill
        flood(x, y + 1, new_col, bg_col);

        // recursive call for left pixel fill
        flood(x, y - 1, new_col, bg_col);
    }
}

int main()
{
    int gd, gm = DETECT;

    // initialize graph
    initgraph(&gd, &gm, "");

    // rectangle coordinate
    int top, left, bottom, right;

    top = left = 50;
    bottom = right = 150;

    // rectangle for print rectangle
    rectangle(left, top, right, bottom);

    // filling start coordinate
    int x = 51;
    int y = 51;

    // new color to fill
    int newcolor = 9;

    // new color which you want to fill
    int oldcolor = 0;

    // call for fill rectangle
    flood(x, y, newcolor, oldcolor);
    getch();

    return 0;
}
