#include<stdio.h>
#define max 1000
int Queue[max];
int rear = -1;
int front = 0;
void Enqueue(int val){
	if(rear == max - 1)	printf("Queue is filled\n");
	else	Queue[++rear] = val;
}
void Dequeue(){
	if(rear == -1)	printf("Queue is empty\n");
	else	front++;
}
int is_empty(){
	if(rear == -1)	return 1;
	else	return 0;
}
int is_full(){
	if(rear == max - 1)	return 1;
	else	return 0;
}
void Get_front(){
	if(!is_empty())	printf("Front element is: %d\n", Queue[front]);
}
void Get_rear(){
	printf("Rear(last) element is: %d\n", Queue[rear]);
}
void Display_Queue(){
	int temp = front;
	while(temp <= rear){
		printf("%d ", Queue[temp++]);
	}
	printf("\n");
}

int main(){
	Enqueue(10);
	Enqueue(20);
	Enqueue(30);
	Enqueue(40);
	Dequeue();
	Dequeue();
	Display_Queue();
	Get_front();
}