#include <bits/stdc++.h>

using namespace std;

int dist[101][101];
const int INF=987654321;
int n,m;
int a,b,c;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	fill(&dist[0][0],&dist[0][0]+101*101,INF);
	
	
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		dist[a][b]=min(dist[a][b],c);
	}
	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dist[i][j]=min(dist[i][j],dist[k][j]+dist[i][k]);
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dist[i][j]==INF || i==j) cout<<"0 ";
			else cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}



	
	
	
	
	
	
	
	return 0;
}
