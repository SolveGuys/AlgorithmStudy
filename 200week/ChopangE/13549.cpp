#include<iostream>
#include<vector>
#include<queue>
#include<deque>

using namespace std;

typedef pair<int, int> ii;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	int max_num = max(N + 1, 2 * K + 1);
	vector<bool> visit(max_num, 0);
	deque<ii> que;
	que.push_front({ N,0 });
	
	while ( !que.empty() ) {
		int x, t;
		x = que.front().first;
		t = que.front().second;
		que.pop_front();
		if ( visit[x] )continue;
		if ( x == K ) {
			cout << t << endl;
			return 0;
		}
		visit[x] = 1;
		if ( x < K ) {
			if ( 2 * x < max_num ) que.push_front({ 2 * x,t });
			que.push_back({ x + 1, t + 1 });
			if ( x - 1 >= 0 ) que.push_back({ x - 1,t + 1 });
		}
		else {
			if ( x - 1 >= 0 ) que.push_back({ x - 1,t + 1 });
		}
	}

	return 0;
}