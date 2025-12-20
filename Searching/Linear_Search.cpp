/*
Linear Search :- checking every element one by one

Time Complexity : O(n)
Space Complexiry :- O(1)
*/

int LinearSearch(int arr[], int size, int key){
    for(int i = 0; i < size; i++){
        if(arr[i] == key){ // cheking if the element is the key
            return i;  // returning the position of the key
        }
    }
    return -1;  //  return -1 if key is not found
}
