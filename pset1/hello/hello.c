#include <stdio.h>
#include <cs50.h> // get_string function inside there, also string data type

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("Hello, %s\n", answer);
    return 0;
}