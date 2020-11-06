#include <stdio.h>
#include <cs50.h> // for string data type
#include <string.h> // for strlen()
#include <math.h> // for round()

/* Computes the approximate grade level needed to comprehend some text
 * per Coleman-Liau index formula.
 */

/* --- Specification:  ---
 * 1. prompt user for a string of text
 * 2. count the number of letters, words, sentences in the text
 * 3. print out Grade X, X = grade level computed by coleman-liau formula
 * 4. if x = 16 or higher output Grade "16+"
 *    if x < 1 output "Before Grade 1"
 */

int count_letters(string);
int count_words(string);
int count_sentences(string);
int index_formula(int, int, int);

int main(void)
{
    // Get text from user
    string user_text = get_string("Text: ");
    //printf("%s\n", user_text);


    // Count and Print the characters from user's input
    int no_of_letters = count_letters(user_text);

    //printf("%i letter(s)", no_of_letters);
    //printf("\n");

    // Count and Print the number of words from user's input text.
    int no_of_words = count_words(user_text);

    //printf("%i word(s)", no_of_words);
    //printf("\n");

    // Count and Print the number of sentences from user's text input.
    int no_of_sentences = count_sentences(user_text);

    //printf("%i sentences(s)", no_of_sentences);
    //printf("\n");

    int rounded_index = index_formula(no_of_letters, no_of_words, no_of_sentences);

    // Print text grading results
    if (rounded_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (rounded_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", rounded_index);
    }
    return 0;
}


/* Counts the characters of a given string
 * and returns an integer representing the number
 * of characters of the given string
 */
int count_letters(string user_text)
{
    int count = 0;
    for (int i = 0, n = strlen(user_text); i < n; i++)
    {
        if (user_text[i] >= 'A' && user_text[i] <= 'z')
        {
            count++;
        }
    }
    return (count);
}

/* Counts the number of words of the given text
 * a word is a set of character(s) seperated by a single space.
 * for example: "sister-in-law" is 1 word but
 * "sister in law" is 3 words.
 * we assume that a sentence will not start or end with space,
 * and we assume that a sentence will not have multiple spaces in a row.
 * Finally it returns the number of words in the given text as an integer.
 */
int count_words(string user_text)
{
    int word = 0;
    for (int i = 0, n = strlen(user_text); i < n; i++)
    {
        if (user_text[i] == 32) // 32 is the ASCII code for a single spacebar
        {
            word++;
        }
    }
    // Count the last word
    if (strlen(user_text) > 2)
    {
        word += 1;
    }
    return (word);
}

/* Counts and returns the number of sentences
 * of the user given text
 */
int count_sentences(string user_text)
{
    int sentence = 0;
    for (int i = 0, n = strlen(user_text); i < n; i++)
    {
        if (user_text[i] == '.' || user_text[i] == '!' || user_text[i] == '?')
        {
            sentence++;
        }
    }
    return (sentence);
}


/* Coleman-liau's index formula:
 * index = 0.0588 * L - 0.296 * S - 15.8
 * where L = average no_of_letters per 100 words
 *       S = average no_of_sentences per 100 words
 */
int index_formula(int letters, int words, int sentences)
{
    double avg_letters = (double) letters / (double) words * 100;
    double avg_sentences = (double) sentences / (double) words * 100;

    double index = ((0.0588 * avg_letters) - (0.296 * avg_sentences) - 15.8);

    // round the above index to nearest whole number
    int rounded_index = (int) round(index);
    //printf("index: %f and roundex_index: %i\n", index, rounded_index);
    return (rounded_index);
}