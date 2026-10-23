#include<stdio.h>
#include<stdlib.h>
struct Node{
	int coefficient;
	int power;
	struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
struct Node* Create_a_node(int c, int p){
	struct Node *nn = (struct Node*)malloc(sizeof(struct Node));
	nn->coefficient = c;
	nn->power = p;
	nn->next = NULL;
	return nn;
}
void Insert(int c, int p){
	struct Node *nn = Create_a_node(c, p);
	if(head == NULL){
		head = nn;
		tail = nn;
	}
	else{
		tail->next = nn;
		tail = nn;
	}
}
void Display_polynomial(struct Node *head){
	struct Node *temp = head;
	while(temp){
		printf("%dx^%d+", temp->coefficient, temp->power);
		temp = temp->next;
	}
	
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int c, p;
		scanf("%d%d", &c, &p);
		Insert(c, p);
	}
	Display_polynomial(head);
}