#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
void Bresenham(int x1, int y1, int x2, int y2);

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    printf("Please enter (x1, y1)\n");
    scanf("%d%d", &x1, &y1);

    printf("Please enter (x2, y2)\n");
    scanf("%d%d", &x2, &y2);
    initgraph(&gd, &gm, "");
    // Bresenham(20,35,120,10);
    Bresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

void Bresenham(int x1, int y1, int x2, int y2)
{
    int xk, yk, dx, dy, pk, yflag, flag = 0;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if (dx < dy)
    {
        std::swap(x1, y1);
        std::swap(x2, y2);
        std::swap(dx, dy);
        flag = 1;
    }
    if (x1 > x2)
    {
        xk = x2;
        yk = y2;
        yflag = y1 - y2;
    }

    else
    {
        xk = x1;
        yk = y1;
        yflag = y2 - y1;
    }

    if (flag == 0)
        putpixel(xk, yk, 15);
    else
        putpixel(yk, xk, 15);

    pk = 2 * dy - dx;

    // while(xk<=xEnd)
    int i;
    for (i = 0; i < dx; i++)
    {
        if (pk < 0)
        {
            xk = xk + 1;
            // yk=yk;
            pk = pk + 2 * dy;
        }
        else
        {
            xk = xk + 1;
            if ((yflag) > 0)
            {
                yk = yk + 1;
            }
            else
            {
                yk = yk - 1;
            }
            pk = pk + 2 * dy - 2 * dx;
        }
        if (flag == 0)
        {
            putpixel(xk, yk, 15);
        }
        else
        {
            putpixel(yk, xk, 15);
        }
    }
}
