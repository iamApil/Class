#include<stdio.h>
#include<conio.h>
int main() 
{
	int i;
	int to, tp, tm;
	float ExpTime, Var;
	for(i=1;i<=9;i++)
	{
		printf("\n Enter to:");
		scanf("%d", &to);
		printf("\n Enter tp: ");
		scanf("%d", &tp);
		printf("\n Enter tm: ");
		scanf("%d", &tm);
		ExpTime = (to + tp + (4*tm))/6;
		Var = (tp - to)/6;
		printf("Expected Time : %f", ExpTime);
		printf("\n Variance: %f", Var);
		
	}
	getch();
}