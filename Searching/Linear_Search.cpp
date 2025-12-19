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

#include<iostream>

using namespace std;

int main(){
    int arr[8] = {23, 54, 67, 53, 98, 67, 94, 59};
    int key = 98;
    int size = sizeof(arr)/sizeof(arr[0]);

    int ans = LinearSearch(arr, size, key);
    if( ans >= 0){
        cout << "Key Found! at position: " << ans << endl;
    }
    else{
        cout << "key not found!" << endl;
    }
}