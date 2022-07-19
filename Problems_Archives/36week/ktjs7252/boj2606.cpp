#include <bits/stdc++.h>

using namespace std;

vector<int> v[101];
int n,k;
int from,to;
bool visited[101];
int answer;

void solve(int x)
{
	visited[x]=1;
	answer++;
	//cout<<x<<"\n";
	for(int i=0;i<v[x].size();i++)
	{
		if(visited[v[x][i]]==0)
		{
			solve(v[x][i]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>k;
	
	for(int i=0;i<k;i++)
	{
		cin>>from>>to;
		v[from].push_back(to);
		v[to].push_back(from);
		
	}
	

	
	solve(1);
	cout<<answer-1;
	
	
	return 0;
}
