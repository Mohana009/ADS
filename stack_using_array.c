#include<stdio.h>
#define max 100
int stack[max];
int top = -1;
void push(int val){
	if(top == max){
		printf("Stack is filled\n");
		return;
	}
	
	stack[++top] = val;
}
void pop(){
	if(top == -1){
		printf("Stack is empty\n");
		return;
	}
	top--;
}
int peek(){
	if(top == -1)	printf("Stack is empty\n");
	else	printf("%d\n", stack[top]);
}
void is_empty(){
	if(top == -1){
		printf("Stack is empty\n");
		return;
	}	
	printf("Stack is not empty\n");
	return;
}
void is_full(){
	if(top == max -1){
		printf("Stack is full\n");
		return;
	}
	printf("Stack is not full\n");
	return;
}
int size(){
	printf("%d\n", top+ 1);
}
void print_stack(){
	if(top == -1){
		printf("Stack is empty\n");
		return;
	}
	int temp = top;
	while(temp != -1){
		printf("%d ", stack[temp--]);
	}
	printf("\n");
}
int main(){
	int n; // no. of elements in the stack
	scanf("%d", &n);
	int val;
	for(int i = 0; i < n; i++){
		scanf("%d", &val);
		push(val);
	}
	print_stack();
	pop();
	print_stack();
	push(100);
	print_stack();
	is_empty();
	is_full();
	size();
	peek();
	print_stack();
	
}