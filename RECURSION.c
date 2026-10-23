#include <stdio.h>
#include<math.h>
void Fun(int n){ // 9
    //base case
    if(n == 0)return; // 9 == 0
    printf("%d ",n); // 10 , 9
    //recursive call -> which is working towards base case
    Fun(n-1); // 8
}
//backtracking 

int Fact(int n){
    //base case 
    if(n == 1)return n;
    
    //finding sub problem
    int sub = Fact(n-1); // n = 2 sub = 1
    
    //with the help of sub problem find current sloution
    int cur = sub * n; // 1*2
    return cur;//2
}
int Fib(int n){
    //base case
    if(n <= 1)return n; // n = 0 -> 0 n = 1 -> 1
    
    //sub-problem
    int sub1 = Fib(n-1);
    int sub2 = Fib(n-2);
    
    //cur solution using sub problem 
    int cur = sub1 + sub2;
    
    return cur;
}
int Count_Digits(int n){
    //base case
    if(n == 0) return 0;
    
    //sub problem 
    int sub = Count_Digits(n/10);
    
    //cur 
    return 1 + sub;
}
int Reverse(int n, int d){// 1 , 1
    //base case
    if(n == 0) return 0;
    
    //sub 
    int last = n % 10;
    return last * d + Reverse(n / 10, d/10); //  10
   
}
void Array_Reverse(int A[], int i, int j){
    //base case 
    if(i >= j)return;
    
    //cur 
    int temp = A[j];
    A[j] = A[i];
    A[i] = temp;
    Array_Reverse(A,i+1,j-1);
    
    //sub problem 
    
}
int FindFirstOcc(int *A, int n, int key){
    
    //base case 
    if(n == 0)return -1;
    
    if(A[0] == key){
        return 0;
    }
    int sub = FindFirstOcc(A+1,n-1,key);
    if(sub == -1) return -1;
    else return sub+1;
    
}
int main() {
	// your code goes here
// 	int n;
// 	scanf("%d",&n);
	
	int A[] = {7,6,5,18,4,18,9};
	int n = sizeof(A)/sizeof(int);
	int key = 8;
	int idx = FindFirstOcc(A,n,key);
	printf("%d",idx);
	//87346578 count how many digits are there in a number 
	
	//reverse a number using recursion
	
	//reverse an array using recursion 
	
	//reverse an string using recursion 
	
	//find the first occurence of key in array 
	//[1,5,8,2,13,8,11] key = 8 --> output -> 2
	
	//find the last occurence of key in array 
	//[1,5,8,2,13,8,11] key = 8 --> output -> 5 
	
	
	

}









