//6
//20 18 30 12 19 26 35
#include<stdio.h>
#include<stdlib.h>
struct BinaryTree{
	int data;
	struct BinaryTree *right;
	struct BinaryTree *left;
};
typedef struct BinaryTree SBT;
SBT* Create_A_Node(int val){
	SBT *nn;
	nn = (SBT*)malloc(sizeof(SBT));
	nn->data = val;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}
SBT* Insert(SBT *root, int val){
	if(root == NULL){
		return Create_A_Node(val);
	}
	else if(root->data < val){
		root->right = Insert(root->right, val);
	}
	else if(root->data > val){
		root->left = Insert(root->left, val);
	}
	return root;
}
void Inorder(SBT *root){
	if(root == NULL){
		return ;
	}
	Inorder(root->left);
	printf("%d ", root->data);
	Inorder(root->right);
}
int Search(SBT *root, int key){
	if(root == NULL){
		return 0;
	}
	else if(root->data == key){
		return 1;
	}
	else if(root->data < key){
		Search(root->right, key);
	}
	else if(root->data > key){
		Search(root->left, key);
	}
	
}
int main(){
	int n;	//Without Root
	scanf("%d", &n);
	int val;
	scanf("%d", &val);
	SBT *root = Create_A_Node(val);
	for(int i = 1; i <= n; i++){
		scanf("%d", &val);
		Insert(root, val);
	}
	Inorder(root);
	int key;
	printf("\nEnter element to search: ");
	scanf("%d", &key);
	int res = Search(root, key);
	if(res == 1)	printf("\nElement found.");
	else if(res == 0)	printf("\nElement not found.");
}