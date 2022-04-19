#include <stdio.h> // printf
#include <stdlib.h> // EXIT_SUCCESS

#include "../../helpers.h" // printArrayI

//algorithms
int recursiveBinarySearch(int* arr, int length, int item);


//====<<Recursive Binary Search>>====//

int _recursiveBinarySearch(int* arr, int length, int item, int si);

/* Worst time:  O(log(n))
 * Best time:   O(1)
 * Space:       O(1)
 * TCO:         yes
 */
// Wrapper for _recursiveBinarySearch
int recursiveBinarySearch(int* arr, int length, int item)
{
    return _recursiveBinarySearch(arr, length, item, 0);
}

int _recursiveBinarySearch(int* arr, int length, int item, int si)
{
    if (length == 0)
        return -1;

    int piv = length / 2;

    if (arr[piv] == item)
        return si + piv;

    return item > arr[piv]
        ? _recursiveBinarySearch(arr + piv + 1, length - piv, item, si + piv + 1)
        : _recursiveBinarySearch(arr, piv, item, si);
}


//============<<Testing>>============//

int main()
{
    const int length = 10;
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const int toFind = 7;

    printf("array:\n");
    printArrayI(arr, length, NULL, NULL);

    int index = recursiveBinarySearch(arr, length, toFind);

    printf("%d is at index %d\n", toFind, index);
}