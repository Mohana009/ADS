#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *prev;
};
struct Node *top = NULL;
struct Node* Create_a_node(int val){
	struct Node *nn;
	nn = (struct Node*)malloc(sizeof(struct Node));
	nn->data = val;
	nn->prev = NULL;
	return nn;
}
void Push(int val){
	struct Node *nn = Create_a_node(val);
	if(top == NULL){
		top = nn;
	}
	else{
		nn->prev = top;
		top = nn;
	}
}
void Pop(){
	if(top == NULL){
		printf("Stack is filled\n");
		return;
	}
	top = top->prev;
}
int is_empty(){
	if(top == 0)	return 1;
	else	return 0;
}
int Get_size(){
	if(is_empty()){
		printf("Stack is empty\n");
	}
	else{
		struct Node* temp = top;
		int s = 0; 
		while(temp){
			s++;
			temp = temp->prev;
			
		}
	free(temp);
	return s;
	}
}
void Display(){
	if(top == 0){
		printf("Stack is empty\n");
		return;
	}
	else{
		struct Node *temp = top;
		while(temp){
			printf("->%d", temp->data);
			temp = temp->prev;
		}
		printf("\n");
		free(temp);
	}
}
void Peek(){
	if(is_empty()){
		printf("Stack is empty\n");
		return;
	}
	else{
		printf("%d\n", top->data);
	}
}



int main(){
	Push(10);
	Push(20);
	Push(30);
	Push(40);
	Display();
	Pop();
	Display();
	Peek();
	printf("%d\n", Get_size());
	printf("%d\n", is_empty());
}