# Sorting

## Bubble sort
```[C]
void bubbleSort(float* arr, int length);
void optimizedBubbleSort(float* arr, int length);
void recursiveBubbleSort(float* arr, int length);
void recursiveOptimizedBubbleSort(float* arr, int length);
```

- `bubbleSort` basic bubble sort algorithm that has always the same time complexity
- `optimizedBubbleSort` tracks position of the last swap so it doesn't need to check after it
- `recursiveBubbleSort` `bubbleSort` implemented recursively with TCO
- `recursiveOptimizedBubbleSort` `optimizedBubbleSort` implemented recursively with TCO

## Select sort
```[C]
void selectSort(float* arr, int length);
```

- `selectSort` simple select sort algorithm

## Merge sort
```
bool mergeSort(float* arr, int length);
```

Returns false if the input is invalid or if the memory allocation failed,
otherwise returns true.

- `mergeSort`
    - wrapper for `_mergeSort`
    - Time: O(n*log(n))
    - Space: O(n)
    - TCO: no
    - Depth: o(log(n))