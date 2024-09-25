#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<map>
#include<stack>

using namespace std;

typedef pair<int, int> ii;


int N;

vector<vector<int>> adj;

bool cmp(int& a, int& b)
{
	return a > b;
}

int DFS(int cur)
{
	vector<int> res;
	for (int next : adj[cur])
	{
		int t = DFS(next);
		res.push_back(t);
	}

	sort(res.begin(), res.end(), cmp);

	int _res = 0;

	int k = 0;

	for (int i = 0; i < res.size(); i++)
	{
		_res = max(_res, res[i] + i);
	}
	return _res + 1;

}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	adj.resize(N, vector<int>());
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		if (t == -1)continue;
		adj[t].push_back(i);
	}
	cout << DFS(0) - 1 << endl;

	return 0;
}