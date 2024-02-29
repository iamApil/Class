#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void drawcircle(int, int, int);

int main(void)
{
    int gdriver = DETECT, gmode;
    int xc, yc, r;

    printf("Enter the center co-ordinates:");
    scanf("%d%d", &xc, &yc);
    printf("Enter the radius");
    scanf("%d", &r);

    initgraph(&gdriver, &gmode, (char*)"");

    drawcircle(xc, yc, r);
    getch();
    closegraph();
    return 0;
}

void drawcircle(int xc, int yc, int r)
{
    int pk, xk, yk;
    xk = 0;
    yk = r;
    putpixel(xc + xk, yc + yk, 15);
    putpixel(xc - xk, yc + yk, 15);
    putpixel(xc + xk, yc - yk, 15);
    putpixel(xc - xk, yc - yk, 15);
    putpixel(xc + yk, yc + xk, 15);
    putpixel(xc - yk, yc + xk, 15);
    putpixel(xc + yk, yc - xk, 15);
    putpixel(xc - yk, yc - xk, 15);

    pk = 1 - r;
    while (xk < yk)
    {
        if (pk < 0)
        {
            xk = xk + 1;
            pk = pk + 2 * xk + 1;
        }
        else
        {
            xk = xk + 1;
            yk = yk - 1;
            pk = pk + 2 * (xk - yk) + 1;
        }

        putpixel(xc + xk, yc + yk, 15);
        putpixel(xc - xk, yc + yk, 15);
        putpixel(xc + xk, yc - yk, 15);
        putpixel(xc - xk, yc - yk, 15);
        putpixel(xc + yk, yc + xk, 15);
        putpixel(xc - yk, yc + xk, 15);
        putpixel(xc + yk, yc - xk, 15);
        putpixel(xc - yk, yc - xk, 15);
    }
}
