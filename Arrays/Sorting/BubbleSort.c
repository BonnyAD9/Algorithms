#include <stdlib.h>
#include <stdio.h>

// helper function, swaps values of two float pointers
void swap(float* f1, float* f2);

// sorting algorithms
void bubbleSort(float* arr, int length);
void optimizedBubbleSort(float* arr, int length);
void recursiveBubbleSort(float* arr, int length);
void recursiveOptimizedBubbleSort(float* arr, int length);

//======<<Regural Bubble Sort>>======//

/* Time:    O(n^2)
 * Space:   O(1)
 */
void bubbleSort(float* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 1; j < length - i; j++)
        {
            if (arr[j] < arr[j - 1])
                swap(&arr[j], &arr[j - 1]);
        }
    }
}

//=====<<Optimized Bubble Sort>>=====//

/* Worst Time:  O(n^2)
 * Best Time:   O(n)
 * Space:       O(1)
 */
void optimizedBubbleSort(float* arr, int length)
{
    for (int i = length, lastJ = 1; i > 1; i = lastJ, lastJ = 1)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(&arr[j], &arr[j - 1]);
                lastJ = j;
            }
        }
    }
}

//=====<<Recursive Bubble Sort>>=====//

// helper function for recursive bubble sort
void recursiveBubble(float* arr, int length);

/* Time:    O(n^2)
 * Space:   O(1)
 * TCO:     yes
 */
void recursiveBubbleSort(float* arr, int length)
{
    if (length <= 1)
        return;

    recursiveBubble(arr, length);

    recursiveBubbleSort(arr, length - 1);
}

void recursiveBubble(float* arr, int length)
{
    if (length <= 1)
        return;

    if (*arr > arr[1])
        swap(arr, &arr[1]);

    recursiveBubble(arr + 1, length - 1);
}

//==<<Optimized Recursive Bubble Sort>>==//

// helper function for optimized recursive bubble sort
int optimizedRecursiveBubble(float* arr, int length, int lastSwap, int sinceLastSwap);

/* Worst Time:  O(n^2)
 * Best Time:   O(n)
 * Space:       O(1)
 * TCO:         yes
 */
void optimizedRecursiveBubbleSort(float* arr, int length)
{
    if (length > 1)
        optimizedRecursiveBubbleSort(arr, optimizedRecursiveBubble(arr, length, 1, 0));
}

int optimizedRecursiveBubble(float* arr, int length, int lastSwap, int sinceLastSwap)
{
    if (length <= 1)
        return lastSwap;
    
    if (*arr <= arr[1])
        return optimizedRecursiveBubble(arr + 1, length - 1, lastSwap, sinceLastSwap + 1);
    
    swap(arr, &arr[1]);
    return optimizedRecursiveBubble(arr + 1, length - 1, lastSwap + sinceLastSwap, 1);
}

//==<<Testing and implementation of helper functions>>==//

// prints array into stdout
void printArray(float* arr, int length);

int main()
{
    const int length = 10;
    float arr[] = { 5, 6, 8, 2, 3, 7, 9, 4, 0, 1 };

    printf("Befor sorting:\n");
    printArray(arr, length);
    printf("Sorted:\n");

    //bubbleSort(arr, length);
    //optimizedBubbleSort(arr, length);
    //recursiveBubbleSort(arr, length);
    optimizedRecursiveBubbleSort(arr, length);

    printArray(arr, length);

    return EXIT_SUCCESS;
}

void swap(float *f1, float *f2)
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