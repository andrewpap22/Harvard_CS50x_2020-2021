#include <stdio.h>
#include <cs50.h>

/* ---------- Function Declarations ------------- */

long get_credit_card(void);
int checksum(long);
int card_length(long);
void card_type(long);

/* ------------- Main ------------------ */

int main(void)
{
    // Get user's credit card
    long credit_card = get_credit_card();

    // Validate Checksum Algorithm
    int valid_card = checksum(credit_card);

    // If credit card is valid print its type else show error msg.
    if (valid_card != 0)
    {
        // printf("Your card is not a valid credit card!\n");
        // printf("Please check your credit card number and try again!\n");
        printf("INVALID\n");
    }
    else
    {
        card_type(credit_card);
    }

    return 0;
}

/* -------------- Function Implementations ----------------- */

long get_credit_card(void)
{
    long credit_card_number;
    do
    {
        credit_card_number = get_long("Card Number: ");
    }
    while (credit_card_number < 12); // not accepting less than 13 digits

    return (credit_card_number);
}

// return user's credit card length
int card_length(long credit_card_number)
{
    int length = 0;
    long calculated_length = credit_card_number;

    while (calculated_length != 0)
    {
        calculated_length /= 10;
        length++;
    }

    return (length);
}

/* If it returns 0, ~> credit card is valid
 * else, returning non zero value means credit card is invalid
 */
int checksum(long credit_card_number)
{
    // get credit card length
    int length = card_length(credit_card_number);

    int mult_digits = 0;
    int sum = 0;

    for (int i = 1; i <= length; i++)
    {
        // get last credit card number
        int last_digit = credit_card_number % 10;

        // move 1 digit to the left
        credit_card_number /= 10;

        /* mult every other digit by 2
         * starting with second-to-last digit
         * and moving from right to left
         * and then add those product's digits.
         */


        if (i % 2 == 0)
        {
            mult_digits = (last_digit * 2);
            sum += mult_digits % 10;
            sum += mult_digits / 10;
        }

        // Add the product's digits sum to the leftover digits
        if (i % 2 != 0)
        {
            sum += last_digit;
        }
    }

    // if total's sum last digit == 0, then credit card is valid
    int total_sum_last_digit = (sum % 10);
    if (total_sum_last_digit == 0)
    {
        return (total_sum_last_digit);
    }
    else
    {
        return (1); // for error handling
    }
}

void card_type(long credit_card_number)
{
    /* Check if card == American Express
     * 15 digits long and
     * first 2 digits are 34 || 37
     *
     * Check if card == Master Card
     * 16 digits long and
     * starts with 51 to 55
     *
     * Check if card == Visa
     * 13 || 16 digits long and always starts with 4
     */

    long first_two_digits = (credit_card_number / 10000000000000);
    long two_digits_mastercard = (credit_card_number / 100000000000000);

    if (first_two_digits == 34 || first_two_digits == 37)
    {
        printf("AMEX\n");
    }
    else if (two_digits_mastercard >= 51 && two_digits_mastercard <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if ((credit_card_number / 1000000000000000 == 4) || (credit_card_number / 1000000000000 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}