#include<stdio.h>
#include<stdlib.h>
struct BinaryTree{
	int data;
	struct BinaryTree *right;
	struct BinaryTree *left;
};
typedef struct BinaryTree BST;
BST* Create_a_node(int val){
	BST *nn;
	nn = (BST*)malloc(sizeof(BST));
	nn->data = val;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}

BST* Insert(BST *root, int val){
	if(root == NULL){
		return Create_a_node(val);
	}
	if(val < root->data){
		root->left = Insert(root->left, val);
	}
	else{
		root->right = Insert(root->right, val);
	}
	return root;
}
void Inorder(BST *root){
	if(root == NULL){
		return;
	}
	
	Inorder(root->left);
	printf("%d ", root->data);
	Inorder(root->right);
	
}
void Postorder(BST *root){
	if(root == NULL){
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	printf("%d ", root->data);
}
void Preorder(BST *root){
	if(root == NULL){
		return;
	}
	printf("%d ", root->data);
	Preorder(root->left);
	Preorder(root->right);
	
}
int main(){
	int n;
	scanf("%d", &n);
	int val;
	scanf("%d", &val);
	BST *root = Create_a_node(val);
	for(int i = 1; i <= n; i++){
		scanf("%d", &val);
		Insert(root, val);
	}
	printf("Inorder of BST: ");
	Inorder(root);
	printf("\n");
	printf("Postorder of BST: ");
	Postorder(root);
	printf("\n");
	printf("Preorder of BST: ");
	Preorder(root);
	printf("\n");

}
