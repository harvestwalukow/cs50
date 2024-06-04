#include <cs50.h>
#include <stdio.h>

void space(int a);
void hash(int a);

int main(void)
{
    // Get the input of height
    int x;
    do
    {
        x = get_int("Height: ");
    }
    while (x < 1 || x > 8);

    // Print pyramid of bricks
    for (int y = 1; y < x + 1; y++)
    {
        space(x - y);
        hash(y);
        printf("  ");
        hash(y);
        printf("\n");
    }
}

// Defining function for print out spaces and hashes
void space(int a)
{
    for (int b = 0; b < a; b++)
    {
        printf(" ");
    }
}

void hash(int a)
{
    for (int b = 0; b < a; b++)
    {
        printf("#");
    }
}
