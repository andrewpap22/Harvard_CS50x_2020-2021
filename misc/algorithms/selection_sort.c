#include <stdio.h>

/* --- Selection Sort ---
 *
 * Algorithm:
 * ----------
 *              For i from 0 to n-1
 *                find smallest item between i'th item and last item
 *                swap smallest item with i'th item.
 *
 * In simple words: So basically we have an array of values unsorted and the goal is to
 * sort those values in the array, what the above algorithm does is, it starts from the 1st position in the array index 0
 * and keeps track of the smallest item it has seen thus far, and if it finds a smaller one, it swaps positions,
 * and it keeps doing that until all the elemets are finally sorted.
 *
 * How much time does this algorithm take for n elements?
 * Well we start iterating n elemets, and then n-1 and then n-2 and so on... so:
 * total time = n + (n-1) + (n-2) + ... + 1
 *            = n(n + 1) / 2
 *            = (n^2 + n) / 2
 *            = (n^2 / 2) + (n / 2)
 *            = O(n^2)
 */

int main(void)
{

    return (0);
}