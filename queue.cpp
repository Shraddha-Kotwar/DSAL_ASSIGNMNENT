#include<iostream>
#include<string>
using namespace std;

string Q[10];
int pr[10];
int n;
int f=-1;
int r=-1;

void enqueue(string data,int p)
{
	int i;
	if(f==0 && r==n-1)
	{
		cout<<"Queue is full";
	}else{
		if(f==-1)
		{
			f=r=0;
			Q[r]=data;
			pr[r]=p;
		}else{
			for(i=r;i>=f;i--)
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
		cout<<"\nPatients name "<<Q[i];
		
		switch(pr[i])
		{
			case 1:
			    cout<<"\nPriority is Checkup ";
			    break;
			case 2:
				cout<<"\nPriority is Non Serios";
				break;
			case 3:
				cout<<"\nPriority is Serious";
				break;
			default:
				cout<<"\nPriority not found";
		}
	}
}

void dequeue()
{
	if(f==-1)
	{
		cout<<"Queue is empty ";
	}else{
		cout<<"Element deleted "<<Q[f];
		cout<<"\nIts priority is "<<pr[f];
		if(f==r)
		{
			f=r=-1;
		}else{
			f++;
		}
	}
}

int main()
{
	int choice;
	string data;
	int i,n,p;
	do{
		cout<<"\n=========menu=======";
		cout<<"\n1.Insert data \n2.Show \n3.Delete \n4.Quit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter no of patients ";
				cin>>n;
				for(int i=0;i<n;i++)
				{
					cout<<"\nEnter the patients name: ";
					cin>>data;
					cout<<"\nEnter the priority ";
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
	}while(choice!=4);
	return 0;
}
