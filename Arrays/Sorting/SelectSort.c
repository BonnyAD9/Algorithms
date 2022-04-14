#include <stdio.h> // printf
#include <stdlib.h> // EXIT_SUCCESS

#include "../../helpers.h" // swap, printArray

// algorithms
void selectSort(float* arr, int length);


//==========<<Select Sort>>==========//

/* Time:    O(n^2)
 * Memory:  O(1)
 */
void selectSort(float* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        int min = i;

        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        swap(&arr[i], &arr[min]);
    }
}


//============<<Testing>>============//

int main()
{
    const int length = 10;
    float arr[] = {5, 6, 8, 2, 3, 7, 9, 4, 0, 1};

    printf("Befor sorting:\n");
    printArray(arr, length, NULL, NULL);
    printf("Sorted:\n");

    selectSort(arr, length);

    printArray(arr, length, NULL, NULL);

    return EXIT_SUCCESS;
}