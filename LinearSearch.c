#include<stdio.h>
#include<stdlib.h>

int linearSearch(int* arr, int len, int key){
    int i=0;
    for(i=0; i<len; i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 4, 623, 21, 12, 5};
    int len = sizeof(arr)/sizeof(arr[0]);
    int index = linearSearch(arr, len, 12);

    if(index == -1){
        printf("Key not found\n");
    }
    else{
        printf("Index of key is %d\n", index);
    }

}