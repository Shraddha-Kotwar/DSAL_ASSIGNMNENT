#include<iostream>
#include<string>
using namespace std;

string Q[10];
int pr[10];
int f=-1,r=-1,n;

void enqueue(string data,int p)
{
	if(f==0 && r==n-1)
	{
		cout<<"Queue is Full ";
	}
	else{
		if(f==-1)
		{
			f=r=0;
			Q[r]=data;
			pr[r]=p;
		}
		else{
			for(int i=r;i>=f;i--)
			{
				if(p>pr[i])
				{
					Q[i+1]=Q[i];
					pr[i+1]=pr[i];
				}
				else{
					break;
				}
			}
			Q[i+1]=data;
			pr[i+1]=p;
			r++;
		}
	}
}

void print()
{
	for(int i=f;i<=r;i++)
	{
		cout<<"\nPatients name: "<<Q[i];
		cout<<"\nIts priority: ";
		switch(pr[i])
		{
			case 1:
				cout<<"\nPriority is general checkup ";
				break;
			case 2:
				cout<<"\nPriority is non serious ";
				break;
			case 3:
				cout<<"\nPriority serious ";
				break;
			default:
				cout<<"\nPriority not found ";
		}
	}
}

void dequeue()
{
	if(f==-1)
	{
		cout<<"Queue is empty ";
	}
	
	cout<<"Element deleted "<<Q[f];
	cout<<"Its priority "<<pr[f];
	if(f==r)
	{
		f=r=-1;
	}
	else{
		f++;
	}
	
}
int main()
{
	int ch;
	string data;
	int p;
	int n;
	do{
		cout<<"\n-------Menu-------------";
		cout<<"\n1.Insert \n2. Print \n3.Delete \n4.Quit ";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the no of patients:  ";
				cin>>n;
				for(int i=0;i<n;i++)
				{
					cout<<"\nEnter the name of patient: ";
					cin>>data;
					cout<<"\nEnter the priority(3.Serious 2.non-serios 3.checkup) ";
					cin>>p;
					enqueue(data,p);
				}
				break;
			case 2:
				print();
				break;
			case 3:
				dequeue();
				break;
			case 4:
				break;
		}
	
	}while(ch!=4);
	return 0;
}
