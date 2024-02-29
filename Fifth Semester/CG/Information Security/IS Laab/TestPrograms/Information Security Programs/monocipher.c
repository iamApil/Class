#include <stdio.h>
#include <string.h>

void tolower_case(char *text);
char monocipher_encr(char);
char monocipher_decr(char);
char alpha[27][3] = { { 'a', 'f' }, { 'b', 'a' }, { 'c', 'g' }, { 'd', 'u' }, {
        'e', 'n' }, { 'f', 'i' }, { 'g', 'j' }, { 'h', 'k' }, { 'i', 'l' }, {
        'j', 'm' }, { 'k', 'o' }, { 'l', 'p' }, { 'm', 'q' }, { 'n', 'r' }, {
        'o', 's' }, { 'p', 't' }, { 'q', 'v' }, { 'r', 'w' }, { 's', 'x' }, {
        't', 'y' }, { 'u', 'z' }, { 'v', 'b' }, { 'w', 'c' }, { 'x', 'd' }, {
        'y', 'e' }, { 'z', 'h' } };
char str[20];

int main() {
    char str2[20];
    int i,j;
    
    printf("\nCharacter Replace:\n");
    printf("\nabcdefghijklmnopqrstuvwxyz\n");
      printf("||||||||||||||||||||||||||\n");
    for(i=0;i<27;i++){
    	printf("%c",alpha[i][1]);
	}
    
    printf("\n\n\nEnter String: ");
    fgets(str, sizeof(str), stdin);
    tolower_case(str);

    for (i = 0; str[i]; i++) {
        str2[i] = monocipher_encr(str[i]);
    }
    str2[i] = '\0';

    printf("Before Encryption: %s\n", str);
    printf("After Encryption: %s\n", str2);

    // Decryption
    for (i = 0; str2[i]; i++) {
        str[i] = monocipher_decr(str2[i]);
    }
    str[i] = '\0';

    printf("After Decryption: %s\n", str);

    return 0;
}

char monocipher_encr(char a) {
    int i;
    for (i = 0; i < 27; i++) {
        if (a == alpha[i][0])
            break;
    }
    return alpha[i][1];
}

char monocipher_decr(char a) {
    int i;
    for (i = 0; i < 27; i++) {
        if (a == alpha[i][1])
            break;
    }
    return alpha[i][0];
}

void tolower_case(char *text) {
    char *ch = text;
    while (*ch != '\0') {
        if (*ch >= 'A' && *ch <= 'Z') {
            *ch = *ch + 32;
        }
        ch++;
    }
}
