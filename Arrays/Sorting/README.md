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