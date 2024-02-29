#include<stdio.h>
#define pi 3.14
int main()
{
float r,c,a;
printf("Enter the radius:\n");
scanf("%f",&r);

c=2*pi*r;
a=pi*r*r;

printf("\nCircumference=%.1f\nArea=%.1f\n",c,a);
}