#include<stdio.h>
#define MAX 40
void create(int set[],int);
void crossproduct(int set1[],int ,int set2[],int);
int main(){
	int set1[MAX],set2[MAX],set3[MAX];
	int n,m;
	printf("\nNo of elements in the set1:");
	scanf("%d",&n);
	printf("\n No of elements in the set2:");
	scanf("%d",&m);
	printf("\n");
	printf("\nEnter elements of set1: ");
	create(set1,n);
	printf("\nEnter elements of set2:");
	create(set2,m);
	printf("\n  finding cross product  \n");
	crossproduct(set1,n,set2,m);
}
	void create(int set[],int n){
	int i;
	printf("Enter set elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&set[i]);
	};
	void crossproduct(int set1[],int n, int set2,int m){
		int i;
		printf("\nCross product of two sets ");
		for (i=0;i<n;i++){
			for (j=0;j<n;j++){
				printf ("%d     %d",set1[i],set2[j]);
			}
		}
	};
		
	}
	\	
	}