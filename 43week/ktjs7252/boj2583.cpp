#include <bits/stdc++.h>

using namespace std;

int m,n,k;
int arr[101][101];
int visited[101][101];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int a,b,c,d;
int answer;
vector<int> v;
int counting;


void dfs(int x,int y)
{
	counting++;
	visited[x][y]=1;
	
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(nx>=0 && nx<m && ny>=0 && ny<n)
		{
			if(visited[nx][ny]==0 && arr[nx][ny]==0)
			{
				dfs(nx,ny);
			}
		}
	}
}

int main()
{
	cin>>m>>n>>k;
	
	for(int idx=0;idx<k;idx++)
	{
		cin>>a>>b>>c>>d;
		for(int i=b;i<d;i++)
		{
			for(int j=a;j<c;j++)
			{
				arr[i][j]=1;
			}
		}
	}
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==0 &&  visited[i][j]==0)
			{
				counting=0;
				answer++;
				dfs(i,j);
				v.push_back(counting);
			}
		}
	}
	
	sort(v.begin(),v.end());
	
	cout<<answer<<"\n";
	
	for(int i=0;i<v.size();i++)
	{
		printf("%d ",v[i]);
	}
	
	
	return 0;
}
