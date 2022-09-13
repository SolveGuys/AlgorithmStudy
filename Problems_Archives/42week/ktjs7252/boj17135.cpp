#include <bits/stdc++.h>

using namespace std;

int n,m,d;
int arr[17][17];
int arr_copy[17][17];
int arr_visited[17][17];
int visited[17];
vector<int> v;
int counting;
int answer;
int dx[]={0,-1,0};
int dy[]={-1,0,1};
vector<pair<int,int>> k;

void bfs(int a,int b)
{
	memset(arr_visited,-1,sizeof(arr_visited));
	queue<pair<int,int>> q;
	q.push({a,b});
	arr_visited[a][b]=0;
	
	while(q.size())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int i=0;i<3;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx<0 || ny<0 || nx>n || ny>m) continue;
			
			if(arr_visited[x][y]+1>d) return;
			
			if(arr_copy[nx][ny]==1 && arr_visited[nx][ny]==-1)
			{
				k.push_back({nx,ny});
				return;
			}
			
			if(arr_copy[nx][ny]==0 && arr_visited[nx][ny]==-1)
			{
				q.push({nx,ny});
				arr_visited[nx][ny]=arr_visited[x][y]+1;
			}
		}
	}
}

void solve(int tmp,int idx)
{
	if(tmp==3)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				arr_copy[i][j]=arr[i][j];
			}
		}
		counting=0;
		for(int i=n;i>0;i--)
		{
			for(int j=0;j<m;j++)
			{
				arr_copy[i][j]=0;
			}
			k.clear();
			for(int j=0;j<v.size();j++)
			{
				bfs(i,v[j]);
			}
			sort(k.begin(),k.end());
			k.erase(unique(k.begin(),k.end()),k.end());
			for(int j=0;j<k.size();j++)
			{
				arr_copy[k[j].first][k[j].second]=0;
				counting++;
			}
		}
		
		answer=max(answer,counting);
		return;
	}
	
	for(int i=idx;i<m;i++)
	{
		if(visited[i]==0)
		{
			visited[i]=1;
			v.push_back(i);
			solve(tmp+1,i+1);
			v.pop_back();
			visited[i]=0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m>>d;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	solve(0,0);
	
	cout<<answer;
	
	
	
	
	
	
	return 0;
}
