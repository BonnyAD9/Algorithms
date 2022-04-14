#include <stdio.h>
#include <stdlib.h>

// helper functions
void swap(float* f1, float* f2);

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

//==<<Tests and implementation of helper functions>>==//

void printArray(float* arr, int length);

int main()
{
    const int length = 10;
    float arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    printf("Before:\n");
    printArray(arr, length);

    //reverse(arr, length);
    recursiveReverse(arr, length);

    printf("After:\n");
    printArray(arr, length);

    return EXIT_SUCCESS;
}

void swap(float* f1, float* f2)
{
    float h = *f1;
    *f1 = *f2;
    *f2 = h;
}

void printArray(float* arr, int length)
{
    for (int i = 0; i < length; i++)
        printf("%f ", arr[i]);
    printf("\n");
}