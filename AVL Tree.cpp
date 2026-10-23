#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int data;
	int height;
	TreeNode *left;	//struct TreeNode *left -> in C
	TreeNode *right;
	
	//Constructor to create node
	TreeNode(int val){
		data = val;
		height = 0;
		right = left = NULL;
	}
};

struct AVLTree{
	
	TreeNode *root = NULL;
	
//	AVLTree(){
//		root = NULL;
//	}
	
	int Height(TreeNode *node){
		if(node == NULL)	return 0;
		return node->height;
	}
	
	//left rotate
	TreeNode* leftRotate(TreeNode *P){
		
		TreeNode *X = P->right;
		TreeNode *Y = X->left;
		
		// changing connections
		
		X->left = P;
		P->right = Y;
		
		//Changing heights after rotation
		X->height = max(Height(X->left), Height(X->right)) + 1;
		P->height = max(Height(P->left), Height(P->right)) + 1;
		
		return X;
		
	}
	
	//right rotate
	TreeNode* rightRotate(TreeNode *P){
		
		TreeNode *X = P->left;
		TreeNode *Y = X->right;
		
		//Changing Conncetions
		
		X->right = P;
		P->left = Y;
		
		//Changing heights after rotation
		X->height = max(Height(X->left), Height(X->right)) + 1;
		P->height = max(Height(P->left), Height(P->right)) + 1;
		
		return X;
		
	}
	
	//insert
	
	TreeNode* Add(TreeNode *root, int val){			//updates and returns new root
		if(root == NULL)	return new TreeNode(val);
		
		if(val > root->data){
			root->right = Add(root->right, val);
		}
		else{
			root->left = Add(root->left, val);
		}
		
		
		//need to check balance factor
		//To know balance factor we need right height and left height
		//Balance factor = (lh- rh)
		
		int balanceFactor = Height(root->left) - Height(root->right);
		root->height = max(Height(root->left), Height(root->right)) + 1;
		
		//Rotations
		
		if(balanceFactor > 1 && val < root->left->data){	//lh - rh > 1 --> left skew tree(left-left)
			root = rightRotate(root);
		}
		if(balanceFactor > 1 && val > root->left->data){	//left-right
			root->left = leftRotate(root->left);
			root = rightRotate(root);
		}
		if(balanceFactor < -1 && val > root->right->data){	//right-right
			root = leftRotate(root);
		}
		if(balanceFactor < -1 && val < root->right->data){	//right-left
			root->right = rightRotate(root->right);
			root = leftRotate(root);
		}
		
		return root;
		
		
	}		
	
	void Insert(int val){
		root = Add(root, val);
	}	
	
	//delete
	
	//search
	
	void Inorder(TreeNode *root){
		if(root == NULL)	return;
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}
	
	void printInorder(){
		Inorder(root);
	}
	
};
int main(){
	int n;
	cin >> n;
	vector<int>A(n);	//To store the values of tree in dyanamic array
	for(int i = 0; i < n; i++)	cin >> A[i];
	//70 20 10 50 80 100 7
	
	AVLTree AVL;
	
	for(int i = 0; i < n; i++){
		AVL.Insert(A[i]);
	}
	cout << AVL.root->data << endl;
	AVL.printInorder();
}