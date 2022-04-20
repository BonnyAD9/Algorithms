#include <stdio.h> // printf
#include <stdlib.h> // EXIT_SUCCESS, malloc, free
#include <stdbool.h> // bool, false, true

#include "../../helpers.h" // printArray

// algorithms
bool mergeSort(float* arr, int length);

//===========<<Merge Sort>>==========//

void _mergeSort(float* arr, float* harr, int length, bool toSame);

/* Time:    O(n*log(n))
 * Space:   O(n)
 * TCO:     no
 * Depth:   O(log(n))
 */
// wrapper for _mergeSort
bool mergeSort(float* arr, int length)
{
    if (!arr || length < 0)
        return false;
    
    if (length <= 1)
        return true;

    float* harr = malloc(length * sizeof(float));
    if (!harr)
        return false;

    _mergeSort(arr, harr, length, true);

    free(harr);

    return true;
}

void _mergeSort(float *arr, float *harr, int length, bool toSame)
{
    if (length == 1)
    {
        if (toSame)
            return;
        *harr = *arr;
        return;
    }

    int ll = length / 2;
    int rl = length - ll;

    _mergeSort(arr, harr, ll, !toSame);
    _mergeSort(arr + ll, harr + ll, rl, !toSame);

    float* lin;
    float* rin;
    if (toSame)
    {
        lin = harr;
        rin = harr + ll;
    }
    else
    {
        lin = arr;
        rin = arr + ll;
        arr = harr;
    }

    for (int li = 0, ri = 0; li + ri < length;)
    {
        if (li < ll && (ri >= rl || lin[li] < rin[ri]))
        {
            arr[li + ri] = lin[li];
            li++;
            continue;
        }
        arr[li + ri] = rin[ri];
        ri++;
    }
}


//============<<Testing>>============//

int main()
{
    const int length = 10;
    float arr[] = { 5, 6, 8, 2, 3, 7, 9, 4, 0, 1 };

    printf("array:\n");
    printArray(arr, length, NULL, NULL);

    mergeSort(arr, length);

    printf("sorted:\n");
    printArray(arr, length, NULL, NULL);
}