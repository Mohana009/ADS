#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int data;
	int height;
	TreeNode *left;	
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
		
		if(balanceFactor > 1 && val < root->left->data){		//lh - rh > 1 --> left skew tree(left-left)
			root = rightRotate(root);
		}
		if(balanceFactor > 1 && val > root->left->data){	//left-right
			root->left = leftRotate(root->left);
			root = rightRotate(root);
		}
		if(balanceFactor < -1 && val > root->right->data){	//right-right -> right skwe tree
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
	TreeNode* FindMin(TreeNode *node){
		if(node == NULL)	return NULL;
		if(node->left == NULL)	return node;
		return FindMin(node->left);
	}
	
	TreeNode* Remove(TreeNode *root, int val){
		if(root == NULL)	return NULL;
		if(root->data > val){
			root->left = Remove(root->left, val);
		}
		else if(root->data < val){
			root->right = Remove(root->right, val);
		}
		//element found
		else{	
			//0 child case
			if(root->left == NULL && root->right == NULL){
				free(root);
				return NULL;
			}
			//1 child case
			else if(root->left == NULL || root->right == NULL){
				TreeNode *temp;
				if(root->left == NULL){
					temp = root->right;
					free(root);
					return temp;
				}
				else if(root->right == NULL){
					temp = root->left;
					free(root);
					return temp;
				}
			}
			//2 child case
			else{
				TreeNode *temp = FindMin(root->right);
				root->data = temp->data;
				root->right = Remove(root->right, temp->data);
				
				//balance factor
				int balanceFactor = Height(root->left) - Height(root->right); 
		
				//height
				root->height = max(Height(root->left), Height(root->right)) + 1;
		
				//rotations
				if(balanceFactor > 1){
					int bf = Height(root->left->left) - Height(root->left->right);
					if(bf > 0){		//left - left
					root = rightRotate(root);
					}
					else if(bf < 0){	//left-right
						root->left = leftRotate(root->left);
						root = rightRotate(root);
					}
				}
				else if(balanceFactor < -1){
					int bf = Height(root->left->left) - Height(root->left->right);
					if(bf > 0){		//right-left
						root->right = rightRotate(root->right);
						root = leftRotate(root);
					}
					else if(bf < 0){	//right-right
						root = leftRotate(root);
					}
				}
			}
		}
		
		return root;
	}
	
	void Delete(int val){
		root = Remove(root, val);
	}
	
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
	cout << "Enter no. of nodes: ";
	cin >> n;
	
	//To store the values of tree in dyanamic array
	vector<int>A(n);	
	cout << "\nEnter values: ";
	for(int i = 0; i < n; i++)	cin >> A[i];
	
	//70 20 10 50 80 100 7
	
	//Creating an AVLTree object (Creating an AVLTree)
	AVLTree AVL;
	
	//Inserting data into AVL tree
	for(int i = 0; i < n; i++)	AVL.Insert(A[i]);
	
	//Printing root value
	cout << "\nRoot value: " << AVL.root->data << endl;
	//Inorder traversal on AVL tree
	cout << "\nInorder: ";
	AVL.printInorder();
	cout << endl;
	
	//Performing deletion
	int val;
	cout << "\nEnter value to delete: ";
	cin >> val;
	
	AVL.Delete(val);
	cout << "\nInorder after deletion: ";
	AVL.printInorder();
	
}
