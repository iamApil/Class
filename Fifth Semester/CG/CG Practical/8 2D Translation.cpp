#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main(){
int tx=20,ty=50,tz=0;
int gd=DETECT, gm;
int left=50,top=200,right=150,bottom=300,depth=50;
printf("enter the coordinates of left,top,right,bottom and depth \n");
scanf("%d%d%d%d%d",&left,&top,&right,&bottom, &depth);
printf("enter the value of tx,ty \n");
scanf("%d%d",&tx, &ty);
initgraph(&gd,&gm,"");
bar3d(left,top,right,bottom,depth,1);
getch();
setcolor(5);
bar3d(left+tx,top+ty,right+tx,bottom+ty,depth+tz,1);
getch();
return 0;
}

