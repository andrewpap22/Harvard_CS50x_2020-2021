/* convert an input word to uppercase */

#include <stdio.h>
#include <cs50.h>
#include <string.h>

/* -- Explanation of how s[i] - 32 converts all lowercase to uppercase letters:
 * From the ASCII table we can see that lowercase a is equivalent to 97 and uppercase A is 65
 * well their difference is 32 = 97 - 65 and that is true for all the english alphabet characters,
 * so with our code bellow subtracting for each of the characters from a to z 32 will give us their
 * uppercase equivalents! Because they are 32 positions back on the ASCII table!
 -- */

 /* or we can use built in functions that do the exactly upper work that we described  */

 #include <ctype.h> // we'll need this for the islower and toupper functions

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");

    for (int i = 0, n = strlen(s); i < n; i++) // we can init multiple vars in the first part of for loop
    {
        //if (s[i] >= 'a' && s[i] <= 'z')
        //{
            //printf("%c", (s[i] - 32));
        //}
        //else
        //{
            //printf("%c", s[i]);
        //}

        //if (islower(s[i]))
        //{
            //printf("%c", toupper(s[i]));
        //}
        //else
        //{
            //printf("%c", s[i]);
        //}

        /* or we can simply use toupper without the if - else
         * because it has a build in mechanism to make the above checks automatically
         * and we know this if we check it's documentaton
         */

         printf("%c", toupper(s[i]));
    }
    printf("\n");
    return 0;
}