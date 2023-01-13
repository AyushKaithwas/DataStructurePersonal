#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct stack{
	char arr[MAX];
	int top;	
}st;

st createEmptyStack(){
	st stack;
	stack.top = -1;
	return stack;
}

void push(st* stack, int d){
	if(stack->top==MAX-1){
		printf("Stack is full\n");
	}
	else{
		(stack->top)++;
		(stack->arr)[stack->top] = d;
	}
}

void pop(st* stack){
	if(stack->top == -1){
		printf("Stack is empty\n");
	}
	else{
		(stack->top)--;
	}
}

int isEmpty(st* stack){
	if(stack->top == -1){
		return 1;
	}
	else{
		return 0;
	}
}

void printStack(st* s){
    int i=0, tempTop = s -> top;
    
    for(i=tempTop; i>=0; i--){
        printf("%d\n", (s->arr)[i]);
    }
}

char stackTop(st* stack){
	if(!isEmpty(stack)){
		return (stack->arr)[stack->top];
	}
	else{
		printf("Stack empty, can't show top\n");
	}
}

int precedence(char op){
	int pre=0;
	
	switch(op){
		case '^':
			pre = 5;
			break;
		case '/':
		case '*':
			pre = 4;
			break;
		case '+':
		case '-':
			pre = 3;
			break;
		case '(':
			pre = 2;
			break;
		default:
			printf("Error in precedence\n");
			break;
	}
	return pre;
}

int isOperator(char o){
	if(o == '+' || o == '-' || o == '*' || o == '/' 
		|| o == '^' || o == ')' || o == '(')
	{
		return 1;
	}
	else{
		return 0;
	}
}

void infixToPrefix(char* exp){
	st stack1 = createEmptyStack();
	int i=0, len = strlen(exp);
	
	for(i=0; i<len; i++){
		if(isOperator(exp[i])){
			if(isEmpty(&stack1)){
				push(&stack1, exp[i]);
			}
			else{
				if(exp[i] == '('){
					push(&stack1, exp[i]);
				}
				else if(exp[i] == ')'){
					while(stackTop(&stack1) != '('){
						printf("%c", stackTop(&stack1));
						pop(&stack1);
					}
					pop(&stack1);
				}
				else{
					int curr_preced = precedence(exp[i]);
					int top_preced = precedence(stackTop(&stack1));
					if(curr_preced>top_preced){
						push(&stack1, exp[i]);
					}
					else if(curr_preced<top_preced){
						while(curr_preced<top_preced && !isEmpty(&stack1)){
							printf("%c", stackTop(&stack1));
							pop(&stack1);
							top_preced = precedence(stackTop(&stack1));
						}
						if(isEmpty(&stack1) || curr_preced>top_preced){
							push(&stack1, exp[i]);
						}
						else{
							printf("%c", stackTop(&stack1));
							pop(&stack1);
							push(&stack1, exp[i]);
						}
					}
					else{
						printf("%c", stackTop(&stack1));
						pop(&stack1);
						push(&stack1, exp[i]);
					}
				}
				
			}
		}
		else{
			printf("%c", exp[i]);
		}
	}
	if(!isEmpty(&stack1)){
		while(!isEmpty(&stack1)){
			printf("%c", stackTop(&stack1));
			pop(&stack1);
		}
	}
}

int main() {
	char exp[] = "x^y/(5*z)+2";
	infixToPrefix(exp);

	return 0;
}
