#include<bits/stdc++.h>
using namespace std;
struct node{
	int key;
	node *left, *right;
};

node *newNode(int item){
	node *temp = new node;
	temp->key=item;
	temp->left=temp->right=NULL;
	return temp;
}
void inorder(node *root){
	if(root !=NULL){
		inorder(root->left);
		cout<<root->key<<endl;
		inorder(root->right);
	}
}

node* insert( node* node, int key){
	if(node == NULL) return newNode(key);

	if(key<node->key) node->left=insert(node->left,key);
	else if(key>node->key) node->right=insert(node->right,key);
	
	return node;
}

node *minbst(node* root){
	while(root->left!=NULL){
	root = root->left;
	}
	return root;
}
node* deleteNode(node *root, int key){
	//If Empty Tree
	if(root==NULL) return root;
	//If the current node ain't the node to be deleted
	else if(key<root->key) root->left=deleteNode(root->left,key);
	else if(key>root->key) root->right=deleteNode(root->right,key);
	//If the current node is the node to be deleted
	else{
		//If node has 0/1 child
		if(root->left==NULL){
			node *temp = root->right;
			return temp;
		}
		else if(root->right==NULL){
			node *temp = root->left;
			return temp;
		}

		//If node has 2 children find the inorder successor of the right subtree and replace root with it

		node *temp = minbst(root->right);
		root->key=temp->key;
		root->right = deleteNode(root->right,temp->key);
	}
	return root;
}
int main(){
	int c;
	cin>>c;
	int y;
	// initializing first node as the root of the tree
	cin>>y;
	node *root= newNode(y);
	for(int i=0;i<c-1;i++){
		int x;
		cin>>x;
		insert(root,x);
		}
	cout<<"\nInorder Traversal of the BST is: \n";
	inorder(root);
	cout<<"\nMin Value in BST is:"<<minbst(root)->key<<endl;
	cout<<"\nEnter a node value to delete: ";
	int x;
	cin>>x;
	deleteNode(root,x);
	cout<<"node deleted\n";
	cout<<"Inorder Traversal of modified BST is: \n";
	inorder(root);

	
	return 0;

}


