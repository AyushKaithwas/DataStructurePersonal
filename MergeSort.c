#include<stdio.h>
#include<stdlib.h>

void merge(int *arr, int s, int mid, int l){
    int s1 = mid - s + 1;
    int s2 = l - mid;
    int arr1[s1]; 
    int arr2[s2];
    int i=0, j=0, k=s;

    for(i=0;i<s1;i++){
        arr1[i] = arr[k];
        k++;
    }
    k=mid+1;
    for(i=0;i<s2;i++){
        arr2[i] = arr[k];
        k++;
    }
    k=s;
    while(i<s1 && j<s2){
        if(arr1[i]<arr2[j]){
            arr[k] = arr1[i];
            i++;
        }
        else if(arr1[i]>arr2[j]){
            arr[k] = arr2[j];
            j++;
        }
        else{
            arr[k] = arr1[i];
            k++;
            arr[k] = arr2[j];
            i++;
            j++;
        }
        k++;
    }

    while(i<s1){
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while(j<s2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, int s, int l){

    if(s<l){
        int mid = (s+l)/2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, l);
        merge(arr, s, mid, l);
    }
}

void displayArray(int* arr, int len){
    int i=0;
    for(i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
}

int main(){

    int arr[] = {12,2,3,214,5,1,23,5,35,14,4};
    int len = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, len-1);
    displayArray(arr, len);

    return 0;
}