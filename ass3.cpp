#include<iostream>
#include<stack>
using namespace std;

class node{
	public:
		node *root,*left,*right;
		int data;
};
class Btree{
	public:
		node *root;
		Btree()
		{
			root=NULL;
		}
		node *createTree();
		void inorder(node *root);
		void preorder(node *root);
		void postorder(node *root);
		void inordernr(node *root);
		void preordernr(node *root);
		void postordernr(node *root);
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
	root=new node;
	root->data=x;
	cout<<"Enter the left data: ";
	root->left=createTree();
	cout<<"Enter the right data: ";
	root->right=createTree();
}

void Btree::inorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}
void Btree::preorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data;
	preorder(root->left);
	preorder(root->right);
}
void Btree::postorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data;
}
void Btree::inordernr(node *root)
{
	int top=-1;
	node *stack[10];
	while(root!=NULL || top!=-1)
	{
		if(root!=NULL)
		{
			stack[++top]=root;
			root=root->left;
		}
		else{
			root=stack[top--];
			cout<<root->data;
			root=root->right;
		}
	}
}
void Btree::preordernr(node *root)
{
	int top=-1;
	node *stack[10];
	stack[++top]=root;
	while(top!=-1)
	{
		root=stack[top--];
		if(root!=NULL)
		{
			cout<<root->data;
			stack[++top]=root->right;
			stack[++top]=root->left;
		}
	}
}

void Btree::postordernr(node *root)
{
	int top=-1;
	int flag[1];
	node *stack[10];
	while(root!=NULL || top!=-1)
	{
		if(root!=NULL)
		{
			stack[++top]=root;
			flag[top]=1;
			root=root->left;
		}
		else{
			root=stack[top];
			if(flag[top]==1)
			{
				cout<<root->data;
				top--;
				root=NULL;
				
			}else{
				flag[top]=1;
				root=root->right;
			}
		}
	}
}

int main()
{
	Btree b;
	int ch;
	node *root;
	do{
		cout<<"\n------Menu-------";
		cout<<"\n1.createTree \n2.Inorder recursive \n3.Preorder Recursive \n4.Postorder Recursive \n5.Inorder non-recursive \n6.Preorder non-recursive \n7.postorder non-recursive \n8.Quit ";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case  1:
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
			case 5:
				b.inordernr(root);
				break;
			case 6:
				b.preordernr(root);
				break;
			case 7:
				b.postordernr(root);
				break;
			case 8:
				break;
		}	
	}while(ch!=8);
}
