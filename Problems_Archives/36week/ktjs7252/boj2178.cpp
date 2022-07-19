#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[101][101];
int visited[101][101];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int main()
{
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%1d",&arr[i][j]);
		}
	}
	
	queue<pair<int,int>> q;
	q.push({0,0});
	visited[0][0]=1;
	
	while(q.size())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx>=0 && ny>=0 && nx<n && ny<m && visited[nx][ny]==0)
			{
				if(arr[nx][ny]==1)
				{
					q.push({nx,ny});
					visited[nx][ny]=visited[x][y]+1;
				}
			}
		}
	}
	
	cout<<visited[n-1][m-1];
	
	return 0;
}






