#include<stdio.h>
#define MAX 20;
#define E 0.00001;
#define f(x) (x*x-4*x-10)
int main(){
int coutn =0;
float x0,x1,x2;
printf("enter the initial guess values x1 and x2\n");
scanf("%f%f",&x1,&x2);
if (f(x1)*f(x2)>0){
	printf("guess value dont bracket root, try other guesses\n");
	}else{
		begin:
			x0=(x1+x2)/2;
			if(fabs(f(x0))<E){
				printf("\n the root is %f",x0);
				printf("\n No of iterations is %d",count)
			}
			else{
				if(f(X0)>0){
					x2=x0;
					count++;
					else if(f(x0)<0){
						x1=x0;
						count++;
					}
					
				}
				if (count<MAX)goto begin;
				else print("\n the process doesnt converge");
			}
	}
	
}

return 0;
}
