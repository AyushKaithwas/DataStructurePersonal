#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

typedef struct{
	int arr[MAX];
	int top;
}st;

st* createEmptyStack(){
	st* newStack = (st*) malloc (sizeof(st));
	newStack->top = -1;
	return newStack;
}

void push(st* s1, int data){
	if(s1->top<MAX-1){
		(s1->top)++;
		(s1->arr)[s1->top] = data;
	}
	else{
		printf("stack overflow\n");
	}
}

void pop(st* s1){
	if(s1->top>=0){
		(s1->top)--;
	}
	else{
		printf("stack already empty\n");
	}
}

int peek(st* s1){
	return (s1->arr)[s1->top];
}

void display(st* s1){
	int i=0;
	for(i=0; i<s1->top; i++){
		printf("%d ", (s1->arr)[i]);
	}
	printf("\n");
}

//a^b
int exponent(int a, int b){ 
	int i=0, pow=1;
	for(i=0; i<b; i++){
		pow *= a;
	}
	return pow;
}

int isOperand(char op){
	if(op=='+' || op=='-' || op=='*' || op=='/' || op=='^'){
		return 1;
	}
	else{
		return 0;
	}
}

int postfixValue(char *str){
	int len = strlen(str);
	st* stackNew = createEmptyStack();
	int i=0;
	for(i=0; i<len; i++){
		if(isOperand(str[i])){
			int op1 = peek(stackNew);
			pop(stackNew);
			int op2 = peek(stackNew);
			pop(stackNew);
			int result = 0;
			switch(str[i]){
				case '+': 
						result = op2+op1;
						break; 
				case '-': 
						result = op2-op1;
						break; 
				case '*': 
						result = op2*op1;
						break; 
				case '/': 
						result = op2/op1;
						break; 
				case '^':
						result = exponent(op2, op1);
			}
			push(stackNew, result);
		}
		else{
			push(stackNew, (int)str[i] - 48);
		}
	}
	int eval = peek(stackNew);
	free(stackNew);
	return eval;
}

int main(){
	char postfix[20] = "98-2*582^/+";
	int val = postfixValue(postfix);
	printf("%d", val);
	return 0;
}
