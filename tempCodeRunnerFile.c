#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* arr, int key, int s, int l){
    int mid = (s+l)/2;
    while(s<l){
        if(arr[mid] == key) return mid;
        else if(arr[mid] > key){
            l = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 3, 5, 7, 12};
    int last = sizeof(arr)/sizeof(arr[0]);
    int index = binarySearch(arr, 7, 0, last);
    if(index == -1) printf("Key not found\n");
    else{
        printf("Index of key is %d\n", index);
    }
}