/*
Merge Sort (Array Version):

Merge Sort is a comparison-based, divide-and-conquer sorting algorithm.
It works by recursively dividing the array into two halves, sorting each half,
and then merging the sorted halves into a single sorted array.

Algorithm Steps:
1. If the array has 0 or 1 element, it is already sorted.
2. Find the middle index of the array.
3. Recursively sort the left half of the array.
4. Recursively sort the right half of the array.
5. Merge the two sorted halves into a temporary array.
6. Copy the merged elements back to the original array.
7. Repeat until the whole array is sorted.

Time Complexity:
- Best Case:    O(n log n)
- Average Case: O(n log n)
- Worst Case:   O(n log n)

Space Complexity: O(n) → temporary array is used during merging
*/

void mergesort(int arr[], int start, int end){
    if(start >= end) return; // base case

    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;  // length of left side array
    int len2 = end - mid;  // length of right side array

    // creating temporary arrays
    int *left = new int[len1]; // intialitiaing left array
    int *right = new int[len2];  //  intialitiaing right array

    // copying the elements in left and right array
    for(int i = 0; i < len1; i++) left[i] = arr[start + i];  
    for(int i = 0; i < len2; i++) right[i] = arr[mid + 1 + i];

    // merging the two arrays
    int index1 = 0, index2 = 0, mainIndex = start;
    while(index1 < len1 && index2 < len2){
        if(left[index1] <= right[index2])
            arr[mainIndex++] = left[index1++];
        else
            arr[mainIndex++] = right[index2++];
    }

    // copying th remaining parts
    while(index1 < len1) arr[mainIndex++] = left[index1++];
    while(index2 < len2) arr[mainIndex++] = right[index2++];

    // deleting the temporary arrays
    delete[] left;
    delete[] right;
}

void partition(int arr[], int start, int end){
    if(start >= end) return; // base case
    int mid = start + (end - start) / 2;

    // divide the array from the mid
    partition(arr, start, mid);
    partition(arr, mid + 1, end);

    // merge the both array
    mergesort(arr, start, end);
}

// doing the sorting without left and right array

void mergesort(int arr[], int start, int mid, int end){
    int n = end - start + 1;
    int temp[n];  // temporary array

    int i = start, j = mid + 1, k = 0;

    // merge elements into temp
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    // copy remaining elements from left half
    while (i <= mid) temp[k++] = arr[i++];

    // copy remaining elements from right half
    while (j <= end) temp[k++] = arr[j++];

    // copy merged elements back to original array
    for (int p = 0; p < n; p++) {
        arr[start + p] = temp[p];
    }
}


void partition(int arr[], int start, int end){
    if(start >= end) return; // base case
    int mid = start + (end - start) / 2;

    // divide the array from the mid
    partition(arr, start, mid);
    partition(arr, mid + 1, end);

    // merge the both array
    mergesort(arr, start, mid, end);
}