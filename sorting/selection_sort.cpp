/*
Selection Sort:

Selection Sort is a comparison-based sorting algorithm.
It works by repeatedly selecting the minimum element from the
unsorted part of the array and placing it at the beginning.

Algorithm Steps:
1. Divide the array into sorted and unsorted parts.
2. Find the minimum element from the unsorted part.
3. Swap it with the first element of the unsorted part.
4. Repeat until the array is sorted.

Time Complexity:
- Best Case:    O(n^2)
- Average Case: O(n^2)
- Worst Case:   O(n^2)
(Note: Selection sort always uses nested loops, regardless of input order)

Space Complexity:  O(1) → In-place sorting (no extra memory used)

*/

void selection_sort(int arr[], int size){
    // Loop to move the boundary of the unsorted part
    for(int i = 0; i < size - 1; i++){
        int min_index = i; // Assume the current index has the minimum element

        // Find the minimum element in the unsorted part
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[min_index]){
                min_index = j; // Update minimum index
            }
        }

        // Swap the found minimum element with the first element
        if(min_index != i){
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}
