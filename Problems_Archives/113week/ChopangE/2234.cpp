#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> ii;

int dx[] = { -1, 0, 1, 0};
int dy[] = { 0, -1, 0, 1};

int totalMax = 0;
int totalMax2 = 0;
int N, M;

vector<int> roomSpace;

int BFS(vector<vector<int>> &place, vector<vector<int>> &roomNum, int y, int x, int num) {
	queue<ii> que;
	que.push({ y,x });
	roomNum[y][x] = num;
	int cnt = 0;
	while ( !que.empty() ) {
		int t_y = que.front().first;
		int t_x = que.front().second;
		cnt++;
		que.pop();
		int target = place[t_y][t_x];
		int bits = 1;
		for ( int i = 0; i < 4; i++ ) {
			int nextY = t_y + dy[i];
			int nextX = t_x + dx[i];
			int check = target & bits;
			if ( !check && roomNum[nextY][nextX] == -1 ) {
				que.push({ nextY,nextX });
				roomNum[nextY][nextX] = num;
				
			}
			bits = bits << 1;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> M >> N;
	vector<vector<int>> place(N, vector<int>(M));
	vector<vector<int>> roomNum(N, vector<int>(M, -1));

	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < M; j++ ) {
			cin >> place[i][j];
		}
	}
	int num = 0;
	
	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < M; j++ ) {
			if ( roomNum[i][j] == -1 ) {
				int cnt = BFS(place, roomNum, i, j, num);
				roomSpace.emplace_back(cnt);
				totalMax = max(cnt, totalMax);
				num++;
			}
		}
	}
	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < M; j++ ) {
			int target = place[i][j];
			int bits = 1;
			for ( int k = 0; k < 4; k++ ) {
				int nextY = i + dy[k];
				int nextX = j + dx[k];
				if ( nextY >= N || nextY < 0 || nextX >= M || nextX < 0  ) {
					bits = bits << 1;
					continue;
				}
				int check = target & bits;
				int t_num = roomNum[nextY][nextX];

				if ( check && t_num != roomNum[i][j] ) {
					totalMax2 = max(roomSpace[t_num] + roomSpace[roomNum[i][j]], totalMax2);
				}
				bits = bits << 1;
			}
		}
	}

	cout << num << endl << totalMax << endl << totalMax2 << endl;
	return 0;
}