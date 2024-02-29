#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 5
#deffine E 0.00001
#define f(x)(x*x-4*x-10)

int main()
{
    int c=0;
    float x1,x2,x0;
    printf( "enter the initial guess value x1 and x2\n");
    scanf("%f%f", &x1,&x2);
     if( f(x1)*f(x2)>0)
     printf("damm! shit bro, change the given value");
     else
     {
         begin:
               x0= (x1+x2)/2;
               if(fabs(f(x0))<E)
               {
               printf("\nNumber of iteration is %d, count");
               }
               else{
                    if(f(x0)>0){
                                x2=x0;
                                c++;}
                                 else if(f(x0)<0){
                                      x1=x0;
                                      c++;}
                                      if(count<MAX) goto begin;
                                      else printf("\n the process doesnt converse.");
                                      }
                                      } return 0;
                                      getch();
                                      }
