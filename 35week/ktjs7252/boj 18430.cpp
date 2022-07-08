#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[6][6];
int dx[]={1,-1,-1,1};
int dy[]={-1,-1,1,1};
bool visited[6][6];
int answer=-1;
//vector<pair<int,int>> v;

void solve(int x,int y,int sum)
{
	if(y==m)
	{
		x++;
		y=0;
	}
	
	if(x==n)
	{
	    answer=max(answer,sum);
		return;
	}
	
	
	if(!visited[x][y])
	{
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
				
			if(nx<0 || ny<0 || nx>=n || ny>=m || visited[x][ny] || visited[nx][y]) continue;
				
			visited[x][y]=true;  visited[nx][y]=true;  visited[x][ny]=true;
				
			solve(x,y+1,sum+(arr[x][y]*2)+arr[nx][y]+arr[x][ny]);
				
			visited[x][y]=false;  visited[nx][y]=false;  visited[x][ny]=false;
		}
	}
	
	solve(x,y+1,sum);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int idx=0;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
			//v.push_back({i,j});
		}
	}
	
	
	solve(0,0,0);
	
	cout<<answer;
	
	
	return 0;
}
