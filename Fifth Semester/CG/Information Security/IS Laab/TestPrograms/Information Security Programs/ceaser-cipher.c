#include <stdio.h>
#include <string.h>
// function prototyping
void encrypt(char *, int);
void decrypt(char *, int);
void tolower_case(char *);
int isAlpha(char);

// main function
int main()
{
    char text[50];
    int shift_by;

    printf("Enter your text: ");
    fgets(text, sizeof(text), stdin);

    fflush(stdin);
    printf("Enter Key/shift: ");
    scanf("%d", &shift_by);

    // max shift is 26
    shift_by = shift_by % 26;

    // encrypting the text
    encrypt(text, shift_by);
    printf("\nEncrypted Text:\n%s\n", text);

    // decrypting the text
    decrypt(text, shift_by);
    printf("\nDecrypted Text:\n%s", text);
    return 0;
}

// function to encrypt the text
void encrypt(char *text, int shift)
{
    char *ch = text;
    int i = 0;
    // convert into lowercase string
    tolower_case(text);

    while (*ch != '\0')
    {
        // encrypt only alphabet characters by shifting their positions
        if (text[i] != ' ' && isAlpha(text[i]))
        {
            text[i] = 'a' + (text[i] - 'a' + shift) % 26;
        }
        i += 1;
        ch++;
    }
}

// function to decrypt the text
void decrypt(char *text, int shift)
{
    char *ch = text;
    int i = 0;
    tolower_case(text);

    while (*ch != '\0')
    {
        // skip the whitespace and non-alphabet characters
        if (text[i] == ' ' || !isAlpha(text[i]))
        {
            text[i] = text[i];
        }
        // if character is reaching to the last alphabet character
        else if (text[i] - shift < 'a')
        {
            text[i] = 'z' - ('a' - (text[i] - shift + 1));
        }
        else
        {
            text[i] = text[i] - shift;
        }

        i += 1;
        ch += 1;
    }
}

// function to check whether the character is alphabet or not
int isAlpha(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return 1;
    }
    if (ch >= 'A' && ch <= 'Z')
    {
        return 1;
    }
    return 0;
}

// function to convert the string into lowercase
void tolower_case(char *text)
{
    char *ch = text;
    while (*ch != '\0')
    {
        if (*ch >= 'A' && *ch <= 'Z')
        {
            *ch = *ch + 32;
        }
        ch++;
    }
}
