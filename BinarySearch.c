#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* arr, int key, int s, int l){
    int mid;
    while(s<l){
        mid = (s+l)/2;
        if(arr[mid] == key) 
            return mid;
        else if(arr[mid] > key){
            l = mid;
        }
        else{
            s = mid;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 3, 5, 7, 12};
    int last = sizeof(arr)/sizeof(arr[0]);
    int index = binarySearch(arr, 3, 0, last-1);
    if(index == -1) 
        printf("Key not found\n");
    else{
        printf("Index of key is %d\n", index);
    }
}