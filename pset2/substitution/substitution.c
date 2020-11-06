#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

/* TODO:
 * 1. Get key (Details: get it from cmd argument argv[1])
 * 2. Validate Key (Details: i. check key length to be exactly 26 characters
                             ii. make sure there are non-alphabetic characters
                             iii. make sure there are no repeated characters (case-insensitive))
 * 3. Get plaintext (Details: get_string())
 * 4. Encipher (Details: i. for each alphabetic character, determine wha tletter it maps to
                         ii. preserve the case, [lowercase chars stay as is and same for uppercase]
                         iii. Leave non-alphabetical characters as is.)
 * 5. Print ciphertext
 */

int key_validation(string);
string lower_user_input(string);
string text_encryption(string, string);

int main(int argc, string argv[])
{
    if (argc != 2) // arguments must be exactly 2
    {
        printf("Usage: ./substitution key\n");
        return (1);
    }
    else
    {
        string user_input = lower_user_input(argv[1]);
        int valid_key = key_validation(user_input);
        if (valid_key == 0)
        {
            string plaintext = get_string("plaintext: ");
            string ciphertext = text_encryption(plaintext, user_input);
            printf("ciphertext: %s\n", ciphertext);
        }
        else // key is not valid
        {
            printf("Key must contain 26 alphabetical characters!\n");
            return 1;
        }
    }
    return 0;
}

/* Returns 1 if key is not valid otherwise returns 0 */
int key_validation(string user_argument)
{
    int key_length = strlen(user_argument);
    if (key_length != 26) // key length must be exactly 26
    {
        return (1);
    }
    else // if key's length is 26, make further checks
    {
        for (int i = 0, n = key_length; i < n; i++)
        {
            int count = 1;

            if (!isalpha(user_argument[i])) // checking for non-alphabetic characters
            {
                return (1);
            }
            else
            {
                for (int j = i + 1, k = key_length; j < k; j++)
                {
                    if (user_argument[i] == user_argument[j] && user_argument[i] != ' ') // check for repeated characters
                    {

                        count++;
                        user_argument[j] = '0';

                    }
                }
            }

            // a char is considered as duplicate if count > 1.
            if (count > 1 && user_argument[i] != '0')
            {
                return (1);
            }
        }
    }
    return (0); // key is valid!
}

/* we must check for duplicates of lower and uppercase chars as well,
 * to prevent that headache we will simply convert
 * every single character the user inputs to lowercase.
 * The above 'cheat' is working since we want to treat uppercase and lowercase as similar characters.
 */
string lower_user_input(string user_input)
{
    string lowered_user_input = user_input;
    for (int i = 0, n = strlen(user_input); i < n; i++)
    {
        lowered_user_input[i] = tolower(user_input[i]);
    }
    return (lowered_user_input);
}

/* returns the encrypted text per the description number 4. */
string text_encryption(string plaintext, string key)
{
    string ciphertext = plaintext;
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (islower(plaintext[i]))
            {
                int lower_ascii = (plaintext[i] - 97);
                ciphertext[i] = tolower(key[lower_ascii]);
            }
            else
            {
                int upper_ascii = (plaintext[i] - 65);
                ciphertext[i] = toupper(key[upper_ascii]);
            }
        }
        ciphertext[i] = plaintext[i];
    }
    return (ciphertext);
}