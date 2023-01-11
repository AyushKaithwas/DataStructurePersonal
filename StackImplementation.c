#include <stdio.h>
#include <stdlib.h>

#define MAX 10
struct stack{
    int items[MAX];
    int top;
};
typedef struct stack st;

void createEmptyStack(st* s){
    s -> top = -1;
}

int isFull(st* s){
    if(s -> top == MAX - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(st* s){
    if(s -> top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(st* s, int data){
    if(isFull(s)){
        printf("Stack Overflow\n");
    }
    else{
        (s->top)++;
        (s->items)[(s->top)] = data;
    }
}

void pop(st* s){
    if(isEmpty(s)){
        printf("Stack Empty");
    }
    else{
        (s->top)--;
    }
}

void printStack(st* s){
    int i=0, tempTop = s -> top;
    
    for(i=tempTop; i>=0; i--){
        printf("%d\n", (s->items)[i]);
    }
}

int main() {
    st* s = (st* )malloc(sizeof(st));
    createEmptyStack(s);
    
    printStack(s);
    
	return 0;
}