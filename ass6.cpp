#include<iostream>
#include<queue>
using namespace std;

int graph[10][10];
void DFS(int start,int n,int v[])
{
	cout<<start<<" ";
	v[start]=1;
	for(int i=1;i<=n;i++)
	{
		if(graph[start][i]==1 && !v[i])
		{
			DFS(i,n,v);
		}
	}
}
void BFS(int s,int n)
{
	queue<int> q;
	int visit[n];
	int v;
	for(int i=1;i<=n;i++)
	{
		visit[i]=0;
	}
	if(!visit[s])
	{
		q.push(s);
		visit[s]=1;
		while(!q.empty())
		{
			
			v=q.front();
			for(int i=1;i<=n;i++)
			{
				if(graph[v][i]==1 && !visit[i])
				{
					visit[i]=1;
					q.push(i);
						
				}
				
			}
			q.pop();
			cout<<v<<" ";
		}
		
	}
}
int main()
{
	int ch;
	int visit[10];
	int source;
	int n;
	cout<<"Enter the no of nodes: ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<"Edge from "<<i<<" to "<<j<<" = ";
			cin>>graph[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		visit[i]=0;
	}
	cout<<"\nEnter the source: ";
	cin>>source;
	do{
		cout<<"\n-------Menu-------";
		cout<<"\n1.DFS \n2.BFS \n3.Quit ";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				DFS(source,n,visit);
				break;
			case 2:
				BFS(source,n);
				break;
			case 3:
				break;
		}
	}while(ch!=3);
}
