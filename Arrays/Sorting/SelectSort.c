#include <stdio.h>
#include <stdlib.h>

// helper function
void swap(float* f1, float* f2);

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

//==<<Testing and implementation of helper functions>>==//

// prints array into stdout
void printArray(float *arr, int length);

int main()
{
    const int length = 10;
    float arr[] = {5, 6, 8, 2, 3, 7, 9, 4, 0, 1};

    printf("Befor sorting:\n");
    printArray(arr, length);
    printf("Sorted:\n");

    selectSort(arr, length);

    printArray(arr, length);

    return EXIT_SUCCESS;
}

void swap(float *f1, float *f2)
{
    float h = *f1;
    *f1 = *f2;
    *f2 = h;
}

void printArray(float *arr, int length)
{
    for (int i = 0; i < length; i++)
        printf("%f ", arr[i]);
    printf("\n");
}