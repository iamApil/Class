//Caser Cipher Increption and Decryption
#include<stdio.h>
int main(){
	char string[100];
	int key;
	printf("Enter a String to be Encrypted: ");
	scanf("%s",string);
	printf("Enter a Key: ");
	scanf("%d",&key);
	
	int encryption() {
		for(int i=0;string[i]!='\0';i++) {
		if(string[i] >= 'a' && string[i]<='z')
		{
			string[i] = (string[i]-'a'+key) %26 + 'a';
		}
		else if(string[i]>='A' && string[i]<='Z') {
			string[i] = (string[i]-'A'+key) %26 + 'A';
		}
		}
		printf("Encrypted string: %s\n",string);
	}
		return 0;
}


