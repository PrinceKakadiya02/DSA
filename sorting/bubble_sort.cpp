/*
Bubble Sort:

Bubble Sort is a simple comparison-based sorting algorithm.
It works by repeatedly swapping adjacent elements if they
are in the wrong order. After each pass, the largest element
"bubbles up" to its correct position at the end.

Algorithm Steps:
1. Traverse the array from start to end.
2. Compare adjacent elements.
3. Swap them if they are in the wrong order.
4. After each pass, the largest element moves to the end.
5. Repeat until the array is sorted.

Time Complexity:
- Best Case:    O(n)   → When the array is already sorted (with optimization)
- Average Case: O(n^2)
- Worst Case:   O(n^2)

Space Complexity:  O(1) → In-place sorting (no extra memory used)

*/

void bubble_sort(int arr[], int size){
    // Traverse through all array elements
    for(int i = 0; i < size - 1; i++){
        bool swapped = false;

        // Last i elements are already in place
        for(int j = 0; j < size - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                // Swap adjacent elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }

        // If no two elements were swapped, array is already sorted
        if(!swapped)
            break;
    }
}
