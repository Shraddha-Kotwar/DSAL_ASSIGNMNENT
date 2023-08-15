#include<iostream>
#include<stack>
using namespace std;

class node{
	public:
		int data;
		node *left,*right;
}*root;

class BTree{
	public:
		BTree()
		{
			root=NULL;
		}
		node *createBST();
		void inorder(node *root);
		void find_min(node *root);
		void find_max(node *root);
		void search(node *root);
		void mirror(node *root);
};
node *createBST()
{
	int x;
	node *temp,*trav;
	cout<<"\nEnter the data: ";
	cin>>x;
	temp=new node;
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else{
		trav=root;
		while(trav!=NULL)
		{
			if(x<trav->data)
			{
				if(trav->left==NULL)
				{
					trav->left=temp;
					break;
				}
				else{
					trav=trav->left;
				}
			}
			else{
				if(trav->right==NULL)
				{
					trav->right=temp;
					break;
				}
				
				trav=trav->right;
			}
		}
	}
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
void BTree::find_min(node *root)
{
	node *trav;
	trav=root;
	while(trav->left!=NULL)
	{
		trav=trav->left;
	}
	cout<<"\nMinimun value in BST : "<<trav->data;
}

void BTree::find_max(node *root)
{
	node *trav;
	trav=root;
	while(trav->right!=NULL)
	{
		trav=trav->right;
	}
	cout<<"\nMinimun value in BST : "<<trav->data;
}
void BTree::search(node *root)
{
	int key;
	cout<<"Enter the data to search: ";
	cin>>key;
	int flag=0;
	node *trav;
	trav=root;
	while(trav!=NULL)
	{
		if(key==trav->data)
		{
			flag=1;
			break;
		}
		else if(key<trav->data)
		{
			trav=trav->left;
		}else{
			trav=trav->right;
		}
	}
	if(flag==1)
	{
		cout<<"Key found ";
	}
	else{
		cout<<"key not found ";
	}	
}	
void BTree::mirror(node *root)
{
	node *temp;
	if(root!=NULL)
	{
		mirror(root->left);
		mirror(root->right);
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
}
int main()
{
	BTree b;
	int ch;
	node *root,*temp,*trav;
	do{
		cout<<"\n------Menu-------";
		cout<<"\n1.createBST \n2.Inorder Traversal \n3.find min \n4.find max \n5.search \n6.mirror \n7.Quit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				root=createBST();
				break;
			case 2:
				b.inorder(root);
				break;
			case 3:
				b.find_min(root);
				break;
			case 4:
				b.find_max(root);
				break;
			case 5:
				b.search(root);
				break;
			case 6:
				b.mirror(root);
				break;
			case 7:
				break;	
		}
	}while(ch!=7);
	return 0;
}

