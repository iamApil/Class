#include<stdio.h>
int main()
{
	int i,j,a[3][4];
	printf("Enter values:\n");
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			
			printf("\nEnter element%d%d:",i+1,j+1);
			scanf("%d",&a[i][j]);
			
			
		}
	}
	
for(i=0;i<3;i++){
	for(j=0;j<4;j++){
		printf("%d\t",a[i][j]);
	}
	printf("\n\n");
}
	
	
	
}