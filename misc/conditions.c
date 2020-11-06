#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Promp user for x and y
    int x = get_int("x: ");
    int y = get_int("y: ");

    // Compare x and y
    if (x < y)
    {
        printf("x is les than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x and y are equal!\n");
    }
    return 0;
}