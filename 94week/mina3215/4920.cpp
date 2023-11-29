#include<iostream>
#include<algorithm>
#include<vector>
#include<climits> // INT_MIN 사용을 위해 추가
using namespace std;

int board[100][100];
int visited[100][100];

int T;
int N;

int dy[] = { 0,1,0,-1  };
int dx[] = { 1,0,-1,0 };

int maxV = INT_MIN;
int find_DFS(int y, int x, vector<int> v, int n, int ans) {
	if(n==4){
		if (v[0] == 1 && v[1] == 2) {
			return 0;
		}
		maxV = max(maxV, ans);
		return 0;
	}

	int ny, nx;
	for (int i = 0; i < 3; i++) {
		
		if (v[2] && i == 2) break;
		v[i]++;
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny>=0&&nx>=0&&ny<N&&nx<N&&!visited[ny][nx]) {
			visited[ny][nx] = 1;
			find_DFS(ny, nx, v , n+1, ans+board[ny][nx]);
			visited[ny][nx] = 0;
		}
		v[i]--;
	}
	return 0;
}

int find_BFS(int y, int x, int ans) {
	int nx, ny;
	int n =0;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x+dx[i];
		if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
			ans += board[ny][nx];
			n+=1;
		}
	}
	if (n == 3) {
		maxV = max(maxV, ans);
	}else if(n>3){
		for (int i = 0; i < 4; i++) {
			maxV = max(maxV, ans - board[y + dy[i]][x + dx[i]]);
		}
	}
	return 0;

}


int main() {
	int t = 1;
	while(true){
		cin >> N;

		if (N==0) return 0; // 0이면 멈춰라

		fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);

		for (int i = 0; i < N;i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
			}
		}
		for (int i = 0; i < N;i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = 1;
				vector<int> v(3);
				v = { 0,0,0 };
				find_DFS(i, j, v, 1,board[i][j]);
				find_BFS(i, j,board[i][j]);
				visited[i][j] = 0;
			}
		}
		cout << t << ". "<< maxV << '\n';
		t++;
		maxV = INT_MIN;
	}
	return 0;
}