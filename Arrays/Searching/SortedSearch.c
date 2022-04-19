#include <stdio.h> // printf
#include <stdlib.h> // EXIT_SUCCESS

#include "../../helpers.h" // printArrayI

// Algorithms
int sortedSearch(int* arr, int length, int item);
int recursiveSortedSearch(int* arr, int length, int item);


//=========<<Sorted Search>>=========//

/* Worst time:  O(n)
 * Best time:   O(1)
 * Space:       O(1)
 */
int sortedSearch(int* arr, int length, int item)
{
    int i;
    for (i = 0; i < length && arr[i] < item; i++) ;
    return arr[i] == item ? i : -1;
}


//====<<Recursive Sorted Search>>====//

/* Worst time:  O(n)
 * Best time:   O(1)
 * Space:       O(1)
 * TCO:         yes
 */
int recursiveSortedSearch(int* arr, int length, int item)
{
    length--;
    if (length < 0 || arr[length] < item)
        return -1;
    
    return arr[length] == item ? length : recursiveSortedSearch(arr, length, item);
}


//============<<Testing>>============//

int main()
{
    const int length = 10;
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const int toFind = 7;

    printf("array:\n");
    printArrayI(arr, length, NULL, NULL);

    //int index = sortedSearch(arr, length, toFind);
    int index = recursiveSortedSearch(arr, length, toFind);

    printf("%d is at index %d\n", toFind, index);

    return EXIT_SUCCESS;
}