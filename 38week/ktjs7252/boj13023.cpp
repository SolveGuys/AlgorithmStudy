#include <bits/stdc++.h>

using namespace std;

vector<int> v[2001];
bool visited[2001];
int sign;
int n,m;

void solve(int x,int tmp)
{
	if(tmp==4)
	{
		sign=1;
		return;
	}
	
	for(int i=0;i<v[x].size();i++)
	{
		int num=v[x][i];
		if(!visited[num])
		{
			visited[num]=1;
			solve(num,tmp+1);
			visited[num]=0;
		}
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i=0;i<n;i++)
	{
		if(v[i].size()==0) continue;
		
		memset(visited,0,sizeof(visited));
		visited[i]=1;
		sign=0;
		solve(i,0);
		if(sign==1)
		{
			cout<<1;
			return 0;
		}
	}
	
	cout<<0;
	
	
	return 0;
}
