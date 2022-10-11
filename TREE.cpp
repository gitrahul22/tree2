#include<stdio.h>
#include<stdlib.h>
// BINary TREE CODE
struct node{
	struct node*left;
	struct node*right;
	int data;	
};
//struct node*root=NULL;
struct node* create_node(int data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
struct node*insert(struct node*root,int data){
	struct node*temp=create_node(data);
	if(root==NULL){
		root=temp;
		return root;
	}
else{
	if(root->data>data)
	{	printf(" \nINserted l ");
		return (root->left=insert(root->left,data));
		
	}
	else{ 
	printf(" \nINserted R");
		return (root->right=insert(root->right,data));
	}
  
}
	
}
//traversal
//inorder traversal (LDR)
void inorder(struct node*root){
	if(root==NULL){
		return ;}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

//POSTORDER (LRD)
struct node* postorder(struct node* root){
	if(root==NULL)
	return root;
	postorder(root->left);
	postorder(root->right);
	printf("%d",root->data);
}
//PREORDER (DLR)
struct node* preorder(struct node*root){
	if(root==NULL)
	return root;
	printf("%d",root->data);
	preorder(root->left);
	preorder(root->right);
}
struct node* search(struct node*root,int key){
	int flag=0;
	if(root->data==key){
	flag=1;
	}
	else{
	 if(key<root->data)
	root=root->left;
	else
	root=root->right;}
	if(flag==0)
	printf("Not found");
	else
	printf("Found but dont know where ");
}
struct node* search_right(struct node*root){
	root=root->right;
	while(root->left!=NULL){
		root=root->left;
	}
	return root;
}
struct node* search_left(struct node*root){
	root=root->left;
	while(root->right!=NULL){
		root=root->right;
	}
	return root;
}
struct node* deleter(struct node*root,int key){
	if(root->data==key)
	return root;
	else{
		if(root->left!=NULL)
			root=search_left(root->left);
			else
			root=search_right(root->right);
	}
	
}
int main(){
	int i,n,data,key;
	struct node*root=NULL;
	printf("How many node syou want you insert ");
	scanf("%d",&n);
	root=insert(root,20);
	for(i=0;i<n;i++){
		printf("Enter the data");
		scanf("%d",&data);
		insert(root,data);
	}
		inorder(root);
		preorder(root);
}

