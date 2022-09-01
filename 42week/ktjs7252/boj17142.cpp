#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[51][51];
vector<pair<int,int>> v;
int visited[11];
int arr_visited[51][51];
vector<pair<int,int>> k;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int answer=987654321;

void solve(int tmp,int idx)
{
	if(tmp==m)
	{
		memset(arr_visited,-1,sizeof(arr_visited));
		queue<pair<int,int>> q;
		
		for(int i=0;i<k.size();i++)
		{
			q.push({k[i].first,k[i].second});
			arr_visited[k[i].first][k[i].second]=0;
		}
		
		while(q.size())
		{
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			
			for(int i=0;i<4;i++)
			{
				int nx=x+dx[i];
				int ny=y+dy[i];
				
				if(nx<0 || ny<0 || nx>=n || ny>=n || arr_visited[nx][ny]!=-1) continue;
				
				if(arr[nx][ny]!=1 )
				{
					q.push({nx,ny});
					arr_visited[nx][ny]=arr_visited[x][y]+1;
				}
			}
		}
		int counting=0;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(arr_visited[i][j]==-1 && arr[i][j]==0)
				{
					return;
				}
				if(arr[i][j]==0)
				{
					counting=max(counting,arr_visited[i][j]);
				}
			}
		}
		
		answer=min(counting,answer);
		
		return;
	}
	//if(idx==v.size()) return;
	for(int i=idx;i<v.size();i++)
	{
		if(visited[i]==0)
		{
			visited[i]=1;
			k.push_back({v[i].first,v[i].second});
			solve(tmp+1,i+1);
			k.pop_back();
			visited[i]=0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]==2)
			{
				v.push_back({i,j});
			}
		}
	}
	
	solve(0,0);
	
	if(answer==987654321)
	{
		cout<<"-1";
		
	}
	else{
		cout<<answer;
	}
	

	
	
	
	return 0;
}
