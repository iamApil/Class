#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#define NOV 3
void drawpolygon(int VT[NOV][2], int color);
void scale(int VT[NOV][2], int IT[NOV][2], float sx, float sy);
int main()
{

  int gd = DETECT, gm;
  float sx = 100, sy = 100;
  int VT[NOV][2] /*={{100,150},{150,100},{200,200} }*/, IT[NOV][2], i; // NO.OF VERTICES//
  printf("please enter x & y co-ordinates \n");
  for (i = 0; i < NOV; i++)
  {

    printf("x%d=", i);
    scanf("%d", &VT[i][0]);
    printf("y%d=", i);
    scanf("%d", &VT[i][1]);
  }

  printf("please enter x-scaling factor sx:");
  scanf("%f", &sx);

  printf("please enter y-scaling factor sy:");
  scanf("%f", &sy);

  initgraph(&gd, &gm, "");
  drawpolygon(VT, 15);
  getch();
  scale(VT, IT, sx, sy);
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
void scale(int VT[NOV][2], int IT[NOV][2], float sx, float sy)
{

  int i;
  for (i = 0; i < NOV; i++)
  {

    IT[i][0] = (float)VT[i][0] * sx;
    IT[i][1] = (float)VT[i][1] * sy;
  }
}
