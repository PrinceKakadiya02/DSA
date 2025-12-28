/*
Quick Sort (Pivot = First Element):

Quick Sort is a divide-and-conquer based sorting algorithm.
In this version, the first (lower bound) element is chosen as the pivot.

Algorithm Steps:
1. Choose the first element (lb) as the pivot.
2. Move elements smaller than or equal to pivot to the left side.
3. Move elements greater than pivot to the right side.
4. Place the pivot in its correct sorted position.
5. Recursively apply Quick Sort to the left subarray.
6. Recursively apply Quick Sort to the right subarray.

Time Complexity:
- Best Case:    O(n log n)
- Average Case: O(n log n)
- Worst Case:   O(n^2) → When the array is already sorted or nearly sorted

Space Complexity:
- O(log n) → Due to recursion stack (in-place sorting)

*/

// Partition function using lb (start) as pivot
int partition(int arr[], int lb, int ub){
    int pivot = arr[lb];
    int start = lb + 1;
    int end = ub;

    while(start <= end){
        while(start <= ub && arr[start] <= pivot){
            start++;
        }
        while(arr[end] > pivot){
            end--;
        }
        if(start < end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }

    // Place pivot at correct position
    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end;
}

// Quick Sort function
void quick_sort(int arr[], int lb, int ub){
    if(lb < ub){
        int loc = partition(arr, lb, ub);

        quick_sort(arr, lb, loc - 1);
        quick_sort(arr, loc + 1, ub);
    }
}
