#include <stdio.h> // printf
#include <stdlib.h> // EXIT_SUCCESS

#include "../../helpers.h" // printArrayI

// algorithms
int search(int* arr, int length, int item);
int recursiveSearch(int* arr, int length, int item);


//=============<<Search>>============//

/* Worst time:  O(n)
 * Best time:   O(1)
 * Memory:      O(1)
 */
int search(int* arr, int length, int item)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == item)
            return i;
    }

    return -1;
}


//========<<Recursive search>>=======//

/* Worst time:  O(n)
 * Best time:   O(1)
 * Space:       O(1)
 * TCO:         yes
 */
int recursiveSearch(int* arr, int length, int item)
{
    length--;

    if (length < 0)
        return -1;
    
    if (arr[length] == item)
        return length;

    return recursiveSearch(arr, length, item);
}


//===========<<Testing>>===========//

int main()
{
    const int length = 10;
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const int toFind = 6;

    printf("Array:\n");
    printArrayI(arr, length, NULL, NULL);

    //int index = search(arr, length, toFind);
    int index = recursiveSearch(arr, length, toFind);

    printf("%d is at index: %d\n", toFind, index);
}