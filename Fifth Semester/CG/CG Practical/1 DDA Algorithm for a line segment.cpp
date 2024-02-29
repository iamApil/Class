#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
void DDAline(int x1, int y1, int x2, int y2);
int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    printf("Please enter (x1, y1)\n");
    scanf("%d%d", &x1, &y1);

    printf("Please enter (x2, y2)\n");
    scanf("%d%d", &x2, &y2);

    initgraph(&gd, &gm, (char *)"");
    DDAline(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

void DDAline(int x1, int y1, int x2, int y2)
{
    int dx, dy, steps, i;
    float xinc, yinc, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xinc = (float)dx / steps;
    yinc = (float)dy / steps;

    x = x1;
    y = y1;
    putpixel(x, y, 15);

    for (i = 0; i < steps; i++)
    {
        x = x + xinc;
        y = y + yinc;
        putpixel(round(x), round(y), 15);
    }
}
