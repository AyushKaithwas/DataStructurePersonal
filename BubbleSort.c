#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int* arr, int len){
    int i=0, j=0;
    for(i=0; i<len; i++){
        for(j=i+1; j<len; j++){
            if(arr[j]<arr[i]){
                swap(&arr[i], &arr[j]);
            }
        }
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
    bubbleSort(arr, len);
    displayArray(arr, len);
    return 0;
}