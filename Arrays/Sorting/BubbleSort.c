#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h> // printf

#include "../../helpers.h" // swap, printArray

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
int recursiveOptimizedBubble(float* arr, int length, int lastSwap, int sinceLastSwap);

/* Worst Time:  O(n^2)
 * Best Time:   O(n)
 * Space:       O(1)
 * TCO:         yes
 */
void recursiveOptimizedBubbleSort(float* arr, int length)
{
    if (length > 1)
        recursiveOptimizedBubbleSort(arr, recursiveOptimizedBubble(arr, length, 1, 0));
}

int recursiveOptimizedBubble(float* arr, int length, int lastSwap, int sinceLastSwap)
{
    if (length <= 1)
        return lastSwap;
    
    if (*arr <= arr[1])
        return recursiveOptimizedBubble(arr + 1, length - 1, lastSwap, sinceLastSwap + 1);
    
    swap(arr, &arr[1]);
    return recursiveOptimizedBubble(arr + 1, length - 1, lastSwap + sinceLastSwap, 1);
}


//============<<Testing>>============//

int main()
{
    const int length = 10;
    float arr[] = { 5, 6, 8, 2, 3, 7, 9, 4, 0, 1 };

    printf("Befor sorting:\n");
    printArray(arr, length, NULL, NULL);
    printf("Sorted:\n");

    //bubbleSort(arr, length);
    //optimizedBubbleSort(arr, length);
    //recursiveBubbleSort(arr, length);
    recursiveOptimizedBubbleSort(arr, length);

    printArray(arr, length, NULL, NULL);

    return EXIT_SUCCESS;
}