#include <bits/stdc++.h>

using namespace std;

typedef struct tmp{
	int h,x,y;
};
int n,m,h;
int arr[101][101][101];
int visited[101][101][101];
queue<tmp> q;
int answer;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>m>>n>>h;
	
	for(int k=0;k<h;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>arr[k][i][j];
				if(arr[k][i][j]==1)
				{
					q.push({k,i,j});
					visited[k][i][j]=1;
				}
			}
		}
	}
	
	while(q.size())
	{
		int k=q.front().h;
		int x=q.front().x;
		int y=q.front().y;
		q.pop();
		
		if(k-1>=0 && arr[k-1][x][y]==0 && visited[k-1][x][y]==0)
		{
			q.push({k-1,x,y});
			visited[k-1][x][y]=visited[k][x][y]+1;
			arr[k-1][x][y]=1;
		}
		if(k+1<h && arr[k+1][x][y]==0 && visited[k+1][x][y]==0)
		{
			q.push({k+1,x,y});
			visited[k+1][x][y]=visited[k][x][y]+1;
			arr[k+1][x][y]=1;
		}
		
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx<0 || nx>=n || ny<0 || ny>=m || visited[k][nx][ny]!=0) continue;
			
			if(arr[k][nx][ny]==0)
			{
				q.push({k,nx,ny});
				visited[k][nx][ny]=visited[k][x][y]+1;
				arr[k][nx][ny]=1;
			}
		}
	}
	int sign=0;
	for(int k=0;k<h;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(arr[k][i][j]==0)
				{
					sign=1;
					break;
				}
				answer=max(answer,visited[k][i][j]);
			}
		}
	}
	
	
	if(sign==1)
	{
		cout<<"-1";
	}
	else
	{
		cout<<answer-1;
	}
	
	
	return 0;
}
