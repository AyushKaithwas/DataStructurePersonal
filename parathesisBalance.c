#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
struct stack{
    char items[MAX];
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

void push(st* s, char data){
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
        printf("Stack Empty\n");
    }
    else{
        (s->top)--;
    }
}

void printStack(st* s){
    int i=0, tempTop = s -> top;
    
    for(i=tempTop; i>=0; i--){
        printf("%c\n", (s->items)[i]);
    }
}

int first(st* s){
    if(!isEmpty(s)){
        return (s->items)[s->top];
    }
    else{
        return 'e';
    }
}

int main() {
    st* s = (st* )malloc(sizeof(st));
    createEmptyStack(s);
    char str[MAX];
    printf("Enter the paranthesis string: \n");
    scanf("%s", str);
    int i=0;
    push(s, str[0]);
    for(i=1; i<strlen(str); i++){
        if( (first(s) == '[' && str[i] == ']' ) || (first(s) == '{' && str[i] == '}' ) || (first(s) == '(' && str[i] == ')' )){
            pop(s);
        }
        else{
            push(s, str[i]);
        }
    }
    
    if(isEmpty(s)){
        printf("Balanced\n");
    }
    else{
        printf("Not balanced");
    }
    
	return 0;
}