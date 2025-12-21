/*
Insertion Sort:

Insertion Sort is a comparison-based sorting algorithm.
It works by taking one element at a time and inserting it
into its correct position in the already sorted part of the array.

Algorithm Steps:
1. Assume the first element is already sorted.
2. Pick the next element from the unsorted part.
3. Compare it with elements in the sorted part.
4. Shift all larger elements one position to the right.
5. Insert the picked element at its correct position.
6. Repeat until the array is sorted.

Time Complexity:
- Best Case:    O(n)   → When the array is already sorted
- Average Case: O(n^2)
- Worst Case:   O(n^2) → When the array is sorted in reverse order

Space Complexity:  O(1) → In-place sorting (no extra memory used)

*/

void insertion_sort(int arr[], int size){
    // Start from the second element
    for(int i = 1; i < size; i++){
        int key = arr[i];   // Element to be inserted
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the key at the correct position
        arr[j + 1] = key;
    }
}
