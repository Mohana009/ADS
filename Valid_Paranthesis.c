#include<stdio.h>
#define max 100
char stack[max];
int top = -1;
int is_empty(){
	if(top == -1)	return 1;
	return 0;
}
void push(char val){
	if(top == max-1){
		printf("Stack is filled\n");
		return;
	}
	stack[++top] = val;
}
void pop(){
	if(top == -1)	return;
	top--;
}
int peek(){
	if(top == -1)	return 0;
	return stack[top];
}
int main(){
	char *str;	//{}()[]
	scanf("%[^\n]s", str);
	int flage = 1;
	for(int i = 0; str[i] != '\0'; i++){
		
		if(str[i] == '{' || str[i] == '[' || str[i] == '('){
			push(str[i]);
		}
		else{
			if(str[i] == '}' && !is_empty() && peek() =='{'){
				pop();
			}
			else if(str[i] == ')' && !is_empty() && peek() == '('){
				pop();
			}
			else if(str[i] == ']' && !is_empty() && peek() == '['){
				pop();
			}
			else{
				flage = 0;
				break;
			}
		}		
	}
	if(flage == 1)	printf("Valid\n");
	else	printf("Not Valid\n");
}