#include <stdio.h>
#include <cs50.h>
#include <string.h>

void argument_characters(string []);

/* argc = argument count is an integer that represents
 * the number of words that the users type in the command line
 * after the program's name.
 *
 * argv = argument verctor, vector is a fancy way for saying list
 * it is a variable that's gonna store in an array all of the
 * strings that the human types at the prompt, after the program's name.
 */

int main(int argc, string argv[])
{
    // i want the user to type their name in the command prompt:

    if (argc == 2) // if command line arguments are 2 (name of program and name of user)
    {
        printf("Hello, %s\n", argv[1]); // store the name in the 2nd place of the argv array because in the argv[0] goes the name of the program.
    }
    else
    {
        printf("You must specify 2 arguments!\n");
        printf("Example: ./argv name\n");
    }

    argument_characters(argv);
    return 0;
}

/* prints the 2nd word that the user give as argument in main
 * character by character
 */

void argument_characters(string array[])
{
    for (int i = 0, n = strlen(array[1]); i < n; i++)
    {
        printf("%c\n", array[1][i]); // gets the 2nd argument of main and prints it char by char
    }
}