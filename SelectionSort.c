#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int* arr, int len){
    int i=0, j=0;
    for(i=0; i<len; i++){
        int smallest = arr[i], smallestIndex=i;
        for(j=i+1; j<len; j++){
            if(arr[j]<smallest){
                smallest = arr[j];
                smallestIndex = j;
            }
        }
        swap(&arr[i], &arr[smallestIndex]);
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
    int len = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, len);
    displayArray(arr, len);
    return 0;
}