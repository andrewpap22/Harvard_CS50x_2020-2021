#include <stdio.h>
#include <cs50.h>

// Prototype of function
void meow(int);

int main(void)
{
    // need the cat to meow 3 times

        // Call of function
        meow(3);
    return 0;
}

// Implementation of function
void meow(int times)
{
    for (int i = 0; i < times; i++)
    {
        printf("meow!\n");
    }
}