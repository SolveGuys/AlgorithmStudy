#include<iostream>
#include<vector>

using namespace std;

int cnt = 0;


int TreeDFS(vector<vector<int>> &adj, int cur, int parent) {
	// 0 : EA , 1 : Not EA
	int isEA = 1;
	for ( int child : adj[cur] ) {
		if ( child == parent )continue;
		if ( TreeDFS(adj, child, cur) ) isEA = 0;

	}

	if ( isEA == 0 )cnt++;
	return isEA;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;

	cin >> N;
	vector<vector<int>> adj(N + 1, vector<int>());
	for ( int i = 0; i < N - 1; i++ ) {
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	
	TreeDFS(adj, 1, -1);
	cout << cnt << endl;

	return 0;
}