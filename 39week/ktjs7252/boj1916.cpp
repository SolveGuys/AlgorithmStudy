#include <bits/stdc++.h>

using namespace std;

int n,m;
int from,to,w;
vector<pair<int,int>> adj[1001];
int dist[1001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
const int INF=987654321;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(dist,dist+1001,INF);
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		cin>>from>>to>>w;
		adj[from].push_back(make_pair(w,to));
	}
	cin>>from>>to;
	
	dist[from]=0;
	pq.push(make_pair(0,from));
	
	while(pq.size())
	{
		int here=pq.top().second;
		int here_dist=pq.top().first;
		pq.pop();
		
		if(dist[here]!=here_dist) continue;
		
		for(pair<int,int> there: adj[here])
		{
			int _there=there.second;
			int _there_dist=there.first;
			
			if(dist[_there]>dist[here]+_there_dist)
			{
				dist[_there]=dist[here]+_there_dist;
				pq.push(make_pair(dist[_there],_there));
			}
			
			
		}
	}
	
	cout<<dist[to];
	
	
	
	
	return 0;
}
