#include <bits/stdc++.h>

using namespace std;
int n,m,x;
vector<pair<int,int>> adj[1001],adj2[1001];
int dist[1001];
int dist2[1001];
const int INF=987654321;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int from,to,w;
int answer;

void solve(int *dist,vector<pair<int,int>> *adj)
{
	pq.push(make_pair(0, x));
	dist[x] = 0; 
	
	while(pq.size()){ 
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if(dist[here]!=here_dist) continue;
		
		for(pair<int, int> there : adj[here]){
			int _dist = there.first, _there = there.second;  
			if(dist[_there] > dist[here] + _dist){
				dist[_there] = dist[here] + _dist; 
				pq.push(make_pair(dist[_there], _there));  
			}  
		}
	} 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	fill(dist,dist+1001,INF);
	fill(dist2,dist2+1001,INF);
	
	cin>>n>>m>>x;
	
	for(int i=0;i<m;i++)
	{
		cin>>from>>to>>w;
		adj[from].push_back(make_pair(w,to));
		adj2[to].push_back(make_pair(w,from));
	}
	
	solve(dist,adj);
	solve(dist2,adj2);
	
	for(int i = 1; i <= n; i++){
        if(i == x) continue;  
        answer = max(answer, dist[i] + dist2[i]); 
    }  
    cout<<answer;
	
	
	
	
	return 0;
}
