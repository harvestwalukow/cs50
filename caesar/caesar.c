#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    int n = atoi(argv[1]);

    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        printf("%c", rotate(plaintext[i], n));
    }

    printf("\n");

    return 0;
}

bool only_digits(string s)
{
    bool type = true;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            type = false;
            break;
        }
    }
    return type;
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        char start, end;
        if (islower(c))
        {
            start = 'a';
            end = 'z';
        }
        else
        {
            start = 'A';
            end = 'Z';
        }

        c = start + (c - start + n) % (end - start + 1);
    }
    return c;
}
