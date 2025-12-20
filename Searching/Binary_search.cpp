/*
Binary Search :- checking key by dividing the array into two parts
                 Array needed to be sorted

Time Complexity : O(logn)
Space Complexiry :- O(1) if iterative method
                    O(logn) if recursive method
*/
int BinarySearch(int arr[],int size, int key){
    int start = 0;
    int end = size -1;

    int mid = start + ( end - start ) / 2; // calculating the mid point 

    while ( start <= end){
        if( arr[mid] == key){   // check if the key is at mid 
            return mid; // return the position of key 
        }
        else if(arr[mid] > key){   // if key is in left part from mid
            end = mid - 1;
        }
        else {   // if key is in right part from mid
            start = mid + 1;
        }
        mid = start + (end - start) / 2; // updating the mid
    }
    return -1; // return -1 if key is not found
}
