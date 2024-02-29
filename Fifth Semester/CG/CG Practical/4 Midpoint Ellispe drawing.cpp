#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void ellipse(int xc, int yc, int a, int b);

int main(){
    int gdriver = DETECT, gmode;
int xc, yc, a, b;
int h,k;

printf("Enter (h,k)");
    scanf("%d%d",&h,&k);
    printf("Enter (a,b)");
    scanf("%d%d",&a,&b);

    initgraph(&gdriver, &gmode, "");
    
ellipse(100, 100, 70, 80);
    getch();
    closegraph();
    return 0;
}

void ellipse(int xc, int yc, int a, int b){
    int xk, yk, pk;
    xk = 0;
    yk = b;
    pk = (b*b) - (a*a*b) + ((a*a) / 4);

    while ((xk*b*b) < (yk*a*a)){
        putpixel(xc + xk, yc - yk, 15);
        putpixel(xc - xk, yc + yk, 15);
        putpixel(xc + xk, yc + yk, 15);
        putpixel(xc - xk, yc - yk, 15);

        if (pk < 0){
            xk = xk + 1;
            pk = pk + b * b * (2*xk+1);
        }
else{
            xk = xk + 1;
            yk = yk - 1;
            pk = pk + b * b * (2*xk+1) - (a*a*2*yk);
        }
    }

    pk = ((float)xk + 0.5) * ((float)xk + 0.5) * b * b 		+ (yk-1) * (yk-1) * a * a - a * a * b * b;

    while (yk >= 0){
        putpixel(xc + xk, yc - yk, 15);
        putpixel(xc - xk, yc + yk, 15);
        putpixel(xc + xk, yc + yk, 15);
        putpixel(xc - xk, yc - yk, 15);

        if (pk > 0){
            yk = yk - 1;
            pk = pk - a * a * (2 * yk - 1);
        }
else{
            yk = yk - 1;
            xk = xk + 1;
            pk = pk - a * a * (2*yk-1) + b * b * 2 * xk;
        }
    }
    getch();
    closegraph();
}

