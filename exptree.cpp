#include<iostream>
#include<stack>
using namespace std;

class node{
	public:
		char data;
		node *root,*left,*right;
};

class ExpTree{
	public:
		node *root;
		ExpTree()
		{
			root=NULL;
		}
		node *createTree();
		void postorder(node *root);
		void makeempty(node *root);
};

node *createTree()
{
	node *temp1,*temp2,*root;
	stack<node *>st;
	int len=0;
	char exp[10];
	cout<<"Enter the prefix expression: ";
	cin>>exp;
	for(int i=0;exp[i]!='\0';i++)
	{
		len=i;
	}
	for(int i=len;i>=0;i--)
	{
		char ch=exp[i];
		if(ch>='a' && ch<='z')
		{
			temp1=new node;
			temp1->data=ch;
			temp1->left=NULL;
			temp1->right=NULL;
			st.push(temp1);
		}
		else{
			temp2=new node;
			temp2->data=ch;
			temp2->right=NULL;
			temp2->left=NULL;
			temp2->left=st.top();
			st.pop();
			temp2->right=st.top();
			st.pop();
			st.push(temp2);
		}
	}
	root=st.top();
	return root;
}

void ExpTree::postorder(node *root)
{
	//node *root;
	int top=-1;
	int flag[1];
	node *stack[10];
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

void ExpTree::makeempty(node *root)
{
	if(root!=NULL)
	{
		makeempty(root->left);
		makeempty(root->right);
		delete root;
	}
}
int main()
{
	int ch;
	node *root;
	ExpTree E;
	do{
		cout<<"\n------Menu------";
		cout<<"\n1.create expression tree \n2.postorder traversal \n3.Delete entire tree \n4.Quit ";
		cout<<"\nEnter the choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				root=createTree();
				cout<<"Expression tree created ";
				break;
			case 2:
				E.postorder(root);
				break;
			case 3:
				E.makeempty(root);
				break;
			case 4:
				break;
		}
	}while(ch!=4);
	return 0;
}
