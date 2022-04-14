#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED

#include <stdio.h>

// swaps two numbers
void swap(float* f1, float* f2);
// returns the index of the first occurence of the given character, -1 if not found
int indexOf(char* str, const char c);
// prints the given array of floats into stdout
void printArray(float *arr, const int length, const char *sep, const char *append);
// prints the given array of ints into stdout
void printArrayI(int* arr, const int length, const char* sep, const char* append);

void swap(float *f1, float *f2)
{
    float h = *f1;
    *f1 = *f2;
    *f2 = h;
}

int indexOf(char* str, const char c)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == c)
            return i;
    }

    return -1;
}

void printArray(float* arr, const int length, const char* sep, const char* append)
{
    if (length <= 0 || !arr)
        return;

    if (!sep)
        sep = " ";
    
    if (!append)
        append = "\n";

    for (int i = 0; i < length - 1; i++)
        printf("%f%s", arr[i], sep);

    printf("%f%s", arr[length - 1], append);
}

void printArrayI(int* arr, const int length, const char* sep, const char* append)
{
    if (length <= 0 || !arr)
        return;

    if (!sep)
        sep = " ";
    
    if (!append)
        append = "\n";

    for (int i = 0; i < length - 1; i++)
        printf("%d%s", arr[i], sep);

    printf("%d%s", arr[length - 1], append);
}

#endif // HELPERS_H_INCLUDED