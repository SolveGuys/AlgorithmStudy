#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int N, M, Hx, Hy,Ex,Ey;
	cin >> N >> M >> Hx >> Hy >> Ex >> Ey;
	vector<vector<int>> place(N + 1, vector<int>(M + 1));
	vector<vector<vector<int>>> level(2, vector<vector<int>>(N + 1, vector<int>(M + 1, 0)));
	for ( int i = 1; i < N + 1; i++ ) {
		for ( int j = 1; j < M + 1; j++ ) {
			cin >> place[i][j];
		}
	}
	queue<iii> que;
	que.push(iii({ Hx,Hy }, 0));
	level[0][Hx][Hy] = 1;
	int time = 1;
	while ( !que.empty() ) {
		int tx = que.front().first.first;
		int ty = que.front().first.second;
		int lev = que.front().second;
		if ( level[lev][tx][ty] == time )time++;
		que.pop();
		for ( int i = 0; i < 4; i++ ) {
			int nextX = tx + dx[i];
			int nextY = ty + dy[i];
			if ( nextX <= 0 || nextX >= N+1 || nextY <= 0 || nextY >= M+1 )continue;
			if ( place[nextX][nextY] == 0 && level[lev][nextX][nextY] == 0 ) {
				que.push(iii({ nextX,nextY }, lev));
				level[lev][nextX][nextY] = time;
			}
			if ( lev == 0 && place[nextX][nextY] == 1 && level[1][nextX][nextY] == 0 ) {
				que.push(iii({ nextX,nextY }, 1));
				level[1][nextX][nextY] = time;
			}
		}
	}
	cout << min(level[0][Ex][Ey],level[1][Ex][Ey]) - 1 << endl;
	return 0;
}