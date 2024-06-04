#include <cs50.h>
#include <math.h>
#include <stdio.h>

int find(long x, int y);

int main(void)
{
    // Prompt for input
    long n = get_long("Number: ");

    // Count the Luhn's Algorithm
    int sum = 0;
    int length = 0;
    long num = n;
    while (num > 0)
    {
        int digit = num % 10;
        if (length % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            int doubled = digit * 2;
            sum += doubled / 10 + doubled % 10;
        }
        num /= 10;
        length++;
    }

    // Check starting digits and print result
    if (sum % 10 == 0)
    {
        if ((int) (n / (long) pow(10, length - 2)) == 34 ||
            (int) (n / (long) pow(10, length - 2)) == 37)
        {
            printf("AMEX\n");
        }
        else if ((int) (n / (long) pow(10, length - 2)) >= 51 &&
                 (int) (n / (long) pow(10, length - 2)) <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if ((int) (n / (long) pow(10, length - 1)) == 4 ||
                 (int) (n / (long) pow(10, length - 2)) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int find(long x, int y)
{
    int digit = (x / (long) pow(10, y - 1)) % 10;
    return digit;
}
