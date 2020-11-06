#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get numbers from user
    int x = get_int("x: ");
    int y = get_int("y: ");

    // typecast x and y into floats to get correct results
    float z = ((float) x / (float) y);

    printf("%f\n", z);
    return 0;
}