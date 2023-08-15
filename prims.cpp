#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int n,visit[10],min,cost[10][10],s,ne=1,u,v,total=0;
	cout<<"\nEnter the no of nodes: ";
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		visit[i]=0;
	}
	
	cout<<"\nWeighted Graph : ";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<"\nWeight from "<<i<<j<<"= ";
			cin>>cost[i][j];
			if(cost[i][j]==0)
			{
				cost[i][j]=999;
			}
		}
	}
	cout<<"\nEnter the source: ";
	cin>>s;
	visit[s]=1;
	while(ne<n)
	{
		min=999;
		for(int i=1;i<=n;i++)
		{
			if(visit[i]==1)
			{
				for(int j=1;j<=n;j++)
				{
					if(cost[i][j]<min && visit[j]==0)
					{
						min=cost[i][j];
						u=i;
						v=j;
					}
				}
			}
		}
		if(u!=v)
		{
			ne++;
			cout<<"Edge from "<<u<<" to "<<v<<" = "<<min;
			visit[u]=visit[v]=1;
			total+=min;
		}
		cout<<"\nMinimum cost: "<<total;
	}
	return 0;
}
