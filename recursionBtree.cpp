#include<iostream>
#include<string>
using namespace std;

class node
{
	public:
		int data;
		node *root;
		node *left,*right;
};
class BTree
{
	public:
		node *createTree();
		void inorder(node *root);
		void preorder(node *root);
		void postorder(node *root);
		
};

node *createTree()
{
	node *root;
	int x;
	cout<<"\nEnter the data: ";
	cin>>x;
	if(x==-1)
	{
		return NULL;
	}
	root=new node();
	root->data=x;
	cout<<"Enter the left data: ";
	root->left=createTree();
	cout<<"Enter the right data: ";
	root->right=createTree();
}
void BTree::inorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}
void BTree::preorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data;
	preorder(root->left);
	preorder(root->right);
}
void BTree::postorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data;
	
}

int main()
{
	node *root;
	BTree b;
	int ch;
	do{
		cout<<"------Menu---------";
		cout<<"\n1.Create Tree \n2.Inorder \n3.Preorder \n4.Postorder \n5.Quit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				root=createTree();
				break;
			case 2:
				b.inorder(root);
				break;
			case 3:
				b.preorder(root);
				break;
			case 4:
				b.postorder(root);
				break;
		}
	}while(ch!=5);
	return 0;
}

