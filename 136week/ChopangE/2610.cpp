#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<string>
#include<limits>


using namespace std;

int N, M;

vector<vector<int>> adj;
vector<int> s;
map<int, vector<int>> maps;

int Find(int x)
{
	if ( s[x] == -1 ) return x;
	return s[x] = Find(s[x]);
}

void Union(int x, int y)
{
	int s_x = Find(x);
	int s_y = Find(y);
	if ( s_x == s_y ) return;
	if ( s_x < s_y ) s[s_y] = s_x;
	else s[s_x] = s_y;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	adj.resize(N + 1, vector<int>(N + 1, 101));
	s.resize(N + 1, -1);
	for ( int i = 0; i < M; i++ )
	{
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
		Union(a, b);
	}
	for ( int k = 1; k <= N; k++ )
	{
		for ( int i = 1; i < N + 1; i++ )
		{
			for ( int j = 1; j < N + 1; j++ )
			{
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]); //플로이드 워셔
			}
		}
	}

	for ( int i = 1; i <= N; i++ )
	{
		int x = Find(i);				//대표값 찾기
		maps[x].push_back(i);			//해당 map에 push
	}
	int k = maps.size();
	vector<int> res;
	
	for ( auto iter = maps.begin(); iter != maps.end(); iter++ )
	{
		vector<int>& tmp = iter->second;	
		int total = 101;
		int key;
		for ( int i = 0; i < tmp.size(); i++ )
		{
			int tmp_total = 0;
			for ( int j = 0; j < tmp.size(); j++ )
			{
				if ( i == j )continue;						//자기랑 자기는 비교 X
				tmp_total = max(tmp_total, adj[tmp[i]][tmp[j]]);		//거리가 가장 먼것 찾기
			}
			if ( tmp_total < total )									//최대 거리가 최소라면 업데이트
			{
				key = tmp[i];
				total = tmp_total;
			}
		}
		res.push_back(key);												//해당 값을 결과 벡터에 삽입
	}
	cout << k << endl;
	sort(res.begin(), res.end());
	for ( int i = 0; i < res.size(); i++ )
	{
		cout << res[i] << endl;
	}

	return 0;
}