#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hasDuplicateLetter(const char *s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Use one command-line argument\n");
        return 1;
    }

    string key = argv[1];
    int len = strlen(key);

    if (len != 26)
    {
        printf("Key must contain 26 letters\n");
        return 1;
    }

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }
    }

    if (hasDuplicateLetter(key))
    {
        printf("Key cannot contain duplicate letters\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; i < (int) strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            char plainChar;
            if (islower(plaintext[i]))
            {
                plainChar = 'a';
            }
            else
            {
                plainChar = 'A';
            }

            char keyChar;
            if (islower(key[plaintext[i] - plainChar]))
            {
                keyChar = 'a';
            }
            else
            {
                keyChar = 'A';
            }
            printf("%c", key[plaintext[i] - plainChar] - keyChar + plainChar);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

int hasDuplicateLetter(const char *s)
{
    int len = strlen(s);

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (tolower(s[i]) == tolower(s[j]))
            {
                return 1;
            }
        }
    }

    return 0;
}
