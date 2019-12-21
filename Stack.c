#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

/*
Applications of stack:

    Balancing of symbols
    Infix to Postfix /Prefix conversion
    Redo-undo features at many places like editors, photoshop.
    Forward and backward feature in web browsers
    Used in many algorithms like Tower of Hanoi, tree traversals, stock span problem, histogram problem.
    Other applications can be Backtracking, Knight tour problem, rat in a maze, N queen problem and sudoku solver
    In Graph Algorithms like Topological Sorting and Strongly Connected Components


	peek push pop are all O(1)
*/

typedef struct Stack{
	int top;
	unsigned int capacity;
	int *array;
}Stack;


Stack* create_stack(int cap){
	Stack* ret = (Stack*)malloc(sizeof(Stack));
	ret->top=-1;
	ret->capacity=cap;
	ret->array=(int *)malloc(sizeof(cap));
	return ret;
}

int isFULL(Stack *st){
	return st->top==st->capacity-1;
}

int isEMPTY(Stack *st){
	return st->top==-1;
}


int push(Stack *st,int n){
	if(isFULL(st)){
		int *tmp=(int *)realloc(st->array,sizeof(int)*2*st->capacity);
		
		if(tmp) {
			st->array=tmp;
			st->capacity=2*st->capacity;
				
		}
		else{
			printf("__MEMORY FULL__\n");
			return INT_MIN;
		}
	}
	st->array[++st->top]=n;
	printf("%d was pushed\n",n);
	return 1;
	
}

int pop(Stack *st){
	if(isEMPTY(st)){
		printf("__UNDERFLOW__\n");
		return INT_MIN;
	}	
	--st->top;
	return 1;
}



int peek(Stack *st){
	if(isEMPTY(st)){
		printf("Nothing\n");
		return INT_MIN;
	}
	else return st->array[st->top];
	
}


int main(){
	int n=3; // length of stack which is created
	Stack* stack=create_stack(n);
	push(stack,19);
	push(stack,20);
	push(stack,21);
	printf("%d",stack->capacity);
	printf("%d\n",peek(stack));
	pop(stack);
	printf("%d\n",peek(stack));
	pop(stack);
	printf("%d\n",peek(stack));
	pop(stack);
	
	
}
