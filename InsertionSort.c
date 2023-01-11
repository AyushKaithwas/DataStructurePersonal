#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int* arr, int len){
    int i=0, j=0, key;
    for(i=1; i<len; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void displayArray(int* arr, int len){
    int i=0;
    for(i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {123,23,1,23,12,3,12,3};
    // int arr[] = {123,1,15,23,5};
    // int arr[] = {1,5,15,4,3};
    int len = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, len);
    displayArray(arr, len);
    return 0;
}