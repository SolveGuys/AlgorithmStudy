#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct tri {
	int y, x, k;
};

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int ndx[] = { -2,-2,-1,-1,1,1,2,2 };
int ndy[] = { -1,1,-2,2,-2,2,-1,1 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int k,W, H;
	cin >> k;
	cin >> W >> H;
	vector<vector<int>> place(H, vector<int>(W));
	vector<vector<vector<int>>> kplace(k + 1, vector<vector<int>>(H, vector<int>(W, 0)));
	for ( int i = 0; i < H; i++ ) {
		for ( int j = 0; j < W; j++ ) {
			cin >> place[i][j];
		}
	}
	queue<tri> que;
	que.push({ 0, 0, 0 });
	int res = -1;
	while ( !que.empty() ) {
		tri &cur = que.front();
		int cy = cur.y;
		int cx = cur.x;
		int ck = cur.k;
		que.pop();
		if ( cy == H - 1 && cx == W - 1 ) {
			res = kplace[ck][cy][cx];
			break;
		}
		for ( int i = 0; i < 4; i++ ) {	//k À¯Áö
			int nextY = cy + dy[i];
			int nextX = cx + dx[i];
			if ( nextY < 0 || nextY >= H || nextX < 0 || nextX >= W || place[nextY][nextX] )continue;
			if ( kplace[ck][nextY][nextX] > 0 )continue;
			kplace[ck][nextY][nextX] = kplace[ck][cy][cx] + 1;
			que.push({ nextY,nextX,ck });
		}
		if ( ck < k ) {
			for ( int i = 0; i < 8; i++ ) {
				int nextY = cy + ndy[i];
				int nextX = cx + ndx[i];
				if ( nextY < 0 || nextY >= H || nextX < 0 || nextX >= W || place[nextY][nextX] )continue;
				if ( kplace[ck + 1][nextY][nextX] > 0 )continue;
				kplace[ck + 1][nextY][nextX] = kplace[ck][cy][cx] + 1;
				que.push({ nextY,nextX,ck + 1 });
			}
		}
	}
	cout << res << endl;


	return 0;
}