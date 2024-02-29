#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#define NOV 3
void drawpolygon(int VT[NOV][2], int color);
void rotate(int VT[NOV][2], int IT[NOV][2], float theta);
int main()
{

    int gd = DETECT, gm;
    float theta = 0;
    int VT[NOV][2] /*={{100,150},{150,100},{200,200} }*/, IT[NOV][2], i; // NO.OF VERTICES//
    printf("please enter x & y co-ordinates \n");
    for (i = 0; i < NOV; i++)
    {

        printf("x%d=", i);
        scanf("%d", &VT[i][0]);
        printf("y%d=", i);
        scanf("%d", &VT[i][1]);
    }

    printf("please enter theta(Degree):");
    scanf("%f", &theta);

    theta = ((theta) * 3.14) / 180;

    initgraph(&gd, &gm, "");
    drawpolygon(VT, 15);
    getch();
    rotate(VT, IT, theta);
    drawpolygon(IT, 15);

    getch();
    closegraph();
    return 0;
}
void drawpolygon(int VT[NOV][2], int color)
{

    int i;
    for (i = 0; i < (NOV - 1); i++)
    {
        setcolor(color);
        line(VT[i][0], VT[i][1], VT[i + 1][0], VT[i + 1][1]);
    }
    setcolor(color);
    line(VT[i][0], VT[i][1], VT[0][0], VT[0][1]);
}
void rotate(int VT[NOV][2], int IT[NOV][2], float theta)
{

    int i;
    for (i = 0; i < NOV; i++)
    {

        IT[i][0] = VT[i][0] * cos(theta) - VT[i][1] * sin(theta);
        IT[i][1] = VT[i][0] * sin(theta) + VT[i][1] * cos(theta);
    }
}
