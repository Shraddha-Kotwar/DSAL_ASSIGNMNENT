#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int cost[10][10],min,source,visit[10],total=0,n,ne=1,u,v;
	cout<<"Enter the no of cities: ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		visit[i]=0;
	}
	cout<<"Weighted graph: ";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<"Edge from "<<i<<" to "<<j<<"weight = ";
			cin>>cost[i][j];
			if(cost[i][j]==0)
			{
				cost[i][j]=999;
			}
		}
	}
	cout<<"Enter the source: ";
	cin>>source;
	visit[source]=1;
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
			cout<<"Edge from "<<u<<" to "<<v<<"="<<min;
			visit[u]=visit[v]=1;
			total+=min;
		}
		cout<<"Minimum cost "<<total;
	}
	return 0;
}
