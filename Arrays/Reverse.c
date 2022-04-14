#include <stdio.h> // printf
#include <stdlib.h> // EXIT_SUCCESS

#include "../helpers.h" // swap, printArray

// algorithms
void reverse(float* arr, int length);
void recursiveReverse(float* arr, int length);


//============<<Reverse>>============//

/* Time:    O(n)
 * Memory:  O(1)
 */
void reverse(float* arr, int length)
{
    for (int i = 0; i < length / 2; i++)
        swap(&arr[i], &arr[length - i - 1]);
}


//=======<<Recursive Reverse>>=======//

/* Time:    O(n)
 * Memory:  O(1)
 * TCO:     yes
 */
void recursiveReverse(float* arr, int length)
{
    if (length < 2)
        return;
    
    swap(arr, &arr[length - 1]);
    recursiveReverse(arr + 1, length - 2);
}


//============<<Testing>>============//

int main()
{
    const int length = 10;
    float arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    printf("Before:\n");
    printArray(arr, length, NULL, NULL);

    //reverse(arr, length);
    recursiveReverse(arr, length);

    printf("After:\n");
    printArray(arr, length, NULL, NULL);

    return EXIT_SUCCESS;
}