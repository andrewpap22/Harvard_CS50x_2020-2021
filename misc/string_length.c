#include <stdio.h>
#include <cs50.h> // for string data type
#include <string.h> // for strlen()

/* We said that the string data type is a data type inside the cs50 library,
 * and it's not a part of the C datatypes but,
 * it is basically an array of characters which we can access as we can see below,
 * and the computer knows where each "string" ends from the \0 aka nul aka 0 special character.
 * so if we have for example the string: "hi!" we can see that it is 3 bytes total
 * (1 byte for each character 'h', 'i', '!')
 * but actualy it is 4 bytes, because it allocates automatically 1 byte for the \0 character which determines
 * the end of the string and that's how the computer knows where a string actually ends. (by reading the \0 character)
 */

 /* the (s[i] != '\0') bellow basically gives us the length of the string,
  * because it loops the array of characters until it reaches the end of the strring (\0)
  * and thus this way we know the length of that string!
  *
  * but in C there is a built in function which can give us the length of a string that we pass as argument
  * thus we don't need to type the above thing but basically does the same thing, and that function is:
  * strlen() and we can pass to it a string as argument and it will return to us the length of that string!
  * and we need to include string.h to use it.
  */

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");

    int length = strlen(s);

    for(int i = 0; /*(s[i] != '\0')*/ i < length; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}