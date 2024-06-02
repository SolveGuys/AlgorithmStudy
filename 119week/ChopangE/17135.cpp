#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int total = 0;
int N, M, D;
int dy[] = {0,-1,0,1};
int dx[] = { -1,0,1,0 };

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

void BFS(vector<vector<int>> place, vector<int> &archer_pos) {
	int tmp_sum = 0;
	vector<ii> enemy(3);
	bool isrun = 1;
	while ( isrun ) {
		vector<bool> check(3, 0);
		vector<vector<vector<bool>>> visit(3, vector<vector<bool>>(N + 1, vector<bool>(M, 0)));
		for ( int i = 0; i < 3; i++ ) {
			enemy[i] = { N, archer_pos[i] };
			queue<iii> que;
			que.push({ {N,archer_pos[i]}, 0 });
			visit[i][N][archer_pos[i]] = 1;
			while ( !que.empty() ) {
				int y = que.front().first.first;
				int x = que.front().first.second;
				int t = que.front().second;
				que.pop();
				if ( place[y][x] == 1 && t <= D ) {
					enemy[i] = { y,x };
					check[i] = 1;
					break;
				}
				for ( int j = 0; j < 4; j++ ) {
					int next_x = x + dx[j];
					int next_y = y + dy[j];
					if ( next_x >= M || next_x < 0 || next_y >= N + 1 || next_y < 0 || visit[i][next_y][next_x] )continue;
					visit[i][next_y][next_x] = 1;
					que.push({ {next_y, next_x}, t + 1 });
				}
			}
		}
		for ( int i = 0; i < 3; i++ ) {
			if ( check[i] ) {
				if ( place[enemy[i].first][enemy[i].second] == 1 ) {
					tmp_sum++;
					place[enemy[i].first][enemy[i].second] = 0;
				}
			}
		}
		for ( int i = N - 1; i > 0; i-- ) {
			for ( int j = 0; j < M; j++ ) {
				place[i][j] = place[i - 1][j];
			}
		}
		for ( int i = 0; i < M; i++ ) {
			place[0][i] = 0;
		}
		bool tmpcheck = 0;
		for ( int i = 0; i < N; i++ ) {
			for ( int j = 0; j < M; j++ ) {
				if ( place[i][j] == 1 )tmpcheck = 1;
			}
		}
		if ( tmpcheck == 0 )isrun = 0;
	}
	total = max(total, tmp_sum);
}

void Back(vector<vector<int>> &place, vector<int> &archer_pos, int i, int cnt) {
	if ( cnt == 3 ) {
		BFS(place, archer_pos);
		return;
	}
	for ( ; i < M; i++ ) {
		archer_pos[cnt] = i;
		Back(place, archer_pos, i + 1, cnt + 1);
	}

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> D;
	vector<vector<int>> place(N + 1, vector<int>(M));
	vector<int> archer_pos(3);
	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < M; j++ ) {
			cin >> place[i][j];
		}
	}
	Back(place, archer_pos,0,0);
	cout << total << endl;
	return 0;
}