#include <stdio.h>
#include <cs50.h>
#include <ctype.h> // for isdigit()
#include <string.h> // for strlen()
#include <stdlib.h> // for atoi()

int key_validation(string);
void encryption(string, string, int);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return (1);
    }
    else
    {
        int correct_arg = key_validation(argv[1]);
        if (correct_arg == 0) // if user's argument is a numerical character consisting of '0' ... '9'
        {
            int numeric_key = atoi(argv[1]); // convert it to an actual integer
            numeric_key %= 26; // wrap around the 26 alphabetical english characters in ascii table

            string user_text = get_string("plaintext: ");
            string ciphered_text = user_text;

            printf("ciphertext: ");
            encryption(user_text, ciphered_text, numeric_key);
        }
        else // if user input is not numerical character, example: ./caesar qwerty || ./caesar 22x
        {
            printf("Usage: ./caesar k\n");
            return (1);
        }
    }
    return (0);
}

/* validates if the command line argument that user provides is numeric digit or not
 * if it is a numeric digit '0' - '9' it returns 0
 * else it returns 1
 */
int key_validation(string cmd_argument)
{
    for (int i = 0, n = strlen(cmd_argument); i < n; i++)
    {
        if (!isdigit(cmd_argument[i]))
        {
            return (1);
        }
    }
    return (0);
}

/* encryption algorithm based on:
 * https://cs50.harvard.edu/x/2020/psets/2/caesar/
 */
void encryption(string user_text, string ciphered_text, int numeric_key)
{
    for (int i = 0, n = strlen(user_text); i < n; i++)
    {
        if (isalpha(user_text[i]))
        {
            char ciphered_character = user_text[i] + numeric_key;
            if (!isalpha(ciphered_character)) // if it's not an aphabetical character
            {
                ciphered_character -= 26; // make sure it goes there!
            }
            ciphered_text[i] = ciphered_character;
        }
        else
        {
            ciphered_text[i] = user_text[i]; // handle lowercase and uppercase as they are
        }
        printf("%c", ciphered_text[i]);
    }
    printf("\n");
}