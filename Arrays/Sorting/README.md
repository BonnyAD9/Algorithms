# Sorting

## Bubble sort
These algorithms sort array using bubble sort.

```[C]
void bubbleSort(float* arr, int length);
void optimizedBubbleSort(float* arr, int length);
void recursiveBubbleSort(float* arr, int length);
void recursiveOptimizedBubbleSort(float* arr, int length);
```

- `bubbleSort`
    - Time: O(n^2)
    - Space: O(1)
- `optimizedBubbleSort`
    - Optimized version of `bubbleSort` (tracks last swap)
    - Worst time: O(n^2)
    - Best time: O(n)
    - Space: O(n)
- `recursiveBubbleSort`
    - recursive implementation of `bubbleSort`
    - Time: O(n^2)
    - Space: O(1)
    - TCO: yes
- `recursiveOptimizedBubbleSort`
    - recursive implementation of `optimizedBubbleSort`
    - Worst time: O(n^2)
    - Best time: O(n)
    - Space: O(1)
    - TCO: yes

## Select sort
This algorithm sorts array using select sort.

```[C]
void selectSort(float* arr, int length);
```

- `selectSort`
    - Time: O(n^2)
    - Space: O(n)

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