# Searching

## Search
These algorithms search for an item in a array.

```[C]
int search(int* arr, int length, int item);
int recursiveSearch(int* arr, int length, int item);
```

Returns index of the item in the array if it is present, otherwise -1.

- `search`
    - starts at the first item
    - worst time: O(n)
    - best time: O(1)
    - space: O(1)
- `recursiveSearch`
    - starts at the last item
    - implemented recursively with TCO
    - worst time: O(n)
    - best time: O(1)
    - space: O(1)

## Sorted Search
These algorithms search for an item in a sorted array.
The optimization is that they can exit without comparing every item even
if the searched item is not present in the array.

```
int sortedSearch(int* arr, int length, int item);
int recursiveSortedSearch(int* arr, int length, int item);
```

Returns index of the item in the array if it is present, otherwise -1.

- `sortedSearch`
    - starts at the first item
    - worst time: O(n)
    - best time: O(1)
    - space: O(1)
- `recursiveSearch`
    - starts at the last item
    - implemented recursively with TCO
    - worst time: O(n)
    - best time: O(1)
    - space: O(1)

## Binary Search
These algorithms search for an item in a sorted array.

```
int recursiveBinarySearch(int* arr, int length, int item);
```

Returns index of the item in the array if it is present, otherwise -1.

- `recursiveBinarySearch`
    - implemented recursively with TCO
    - worst time: O(log(n))
    - best time: O(1)
    - space: O(1)