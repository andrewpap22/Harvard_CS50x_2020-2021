#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x,y;

    x = get_int("x: ");
    y = get_int("y: ");

    printf("%i\n", (x + y));
    return 0;
}