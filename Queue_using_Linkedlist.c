#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
struct Node* Create_a_node(int val){
	struct Node *nn;
	nn = (struct Node*)malloc(sizeof(struct Node));
	nn->data = val;
	nn->next = NULL;
	return nn;
}
void Enqueue(int val){
	struct Node *nn = Create_a_node(val);
	if(rear == 0 && front == 0){
		rear = nn;
		front = nn;
	} 
	else{
		rear->next = nn;
		rear = nn;
	}
}
void Dequeue(){
	if(rear == 0 && front == 0){
		printf("Queue is empty\n");
		return;
	}
	else if(rear == front){
		rear = 0;
		front = 0;
	}
	else{
		struct Node *temp = temp;
		temp = front;
		front = front->next;
		free(temp);
	}
}
void Display(){
	if(rear == 0 && front == 0){
		printf("Queue is empty\n");
		return;
	}
	else{
		struct Node *temp = front;
		while(temp){
			printf("->%d", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}
void Get_rear(){
	if(rear == 0){
		printf("Queue is empty\n");
		return;
	}
	else{
		printf("%d\n", rear->data);
	}
}
void Get_front(){
	if(front == 0){
		printf("Queue is empty\n");
		return;
	}
	else{
		printf("%d\n", front->data);
	}
}
void Get_size(){
	if(rear == NULL){
		printf("Queue is empty\n");
		return;
	}
	else{
		int s = 1;
		struct Node *temp = front;
		while(temp != rear){
			s++;
			temp = temp->next;
		}
		printf("Size of the Queue is: %d\n", s);
	}
	
}
int main(){
	Enqueue(10);
	Enqueue(20);
	Enqueue(30);
	Display();
//	Dequeue();
//	Dequeue();
	Display();
	Get_rear();
	Get_front();
	Get_size();
}