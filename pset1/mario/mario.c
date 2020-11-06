#include <stdio.h>
#include <cs50.h> // cs50 library ~> https://github.com/cs50/libcs50

void print_bricks(int);
int get_user_input(void);

int main(void)
{
    // Get user input for bricks height
    int height = get_user_input();

    // print the walls
    print_bricks(height);

    return 0;
}

int get_user_input(void)
{
    int user_input;

    do
    {
        user_input = get_int("Height: ");
    }
    while (user_input < 1 || user_input > 8);

    return (user_input);
}

void print_bricks(int user_input)
{
    for (int i = 0; i < user_input; i++)
    {
        // Left Hand Side of bricks
        for (int z = 2; z <= (user_input - i); z++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");

        // Right Hand side of bricks
        for (int z = (user_input - i); z <= 0; z--)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}