#include<iostream>
#include<stack>
using namespace std;

class node
{
	public:
	node *root,*left,*right;
	int data;
};

class BTree
{
	node *root;
	public:
	BTree()
	{
		root=NULL;
	}
	node *createtree();
	void inorder(node *root);
	void preorder(node *root);
	void postorder(node *root);	
	void inordernr(node *root);
	void preordernr(node *root);
	void postordernr(node *root);
};
node *createtree()
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
	root->left=createtree();
	cout<<"Enter the right data: ";
	root->right=createtree();
	
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
void BTree::inordernr(node *root)
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
void BTree::preordernr(node *root)
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

void BTree::postordernr(node *root)
{
	int top=-1;
	node *stack[10];
	int flag[1];
	while(root!=NULL || top!=-1)
	{
		if(root!=NULL)
		{
			stack[++top]=root;
			flag[top]=0;
			root=root->left;
		}
		else{
			root=stack[top];
			if(flag[top]==1)
			{
				cout<<root->data;
				top--;
				root=NULL;
			}
			else{
				flag[top]=1;
				root=root->right;
			}
		}
	}
}

int main()
{
	BTree b;
	node *root;
	int ch;
	do{
		cout<<"\n-------Menu------------";
		cout<<"\n1.create tree \n2.inorder \n3.preorder \n4.postorder \n5.inoerder non-recursive \n6.Preordernr \n7.postorder nr \n8.Quit ";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				root=createtree();
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
	return 0;
}
