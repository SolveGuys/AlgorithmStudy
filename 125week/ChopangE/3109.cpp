#include<iostream>
#include<vector>

using namespace std;

int R, C;
int total = 0;

int dy[3] = { -1,0,1 };

bool DFS(vector<vector<bool>> &place, int y, int x) {
	place[y][x] = 1;

	if ( x == C - 1 ) {
		total++;
		return 1;
	}
	for ( int i = 0; i < 3; i++ ) {
		int nextY = y + dy[i];
		if ( nextY < 0 || nextY >= R || place[nextY][x + 1] )continue;
		if ( DFS(place, nextY, x + 1) )return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	vector<vector<bool>> place(R, vector<bool>(C, 0));
	for ( int i = 0; i < R; i++ ) {
		for ( int j = 0; j < C; j++ ) {
			char c;
			cin >> c;
			if ( c == '.' ) {
				place[i][j] = 0;
			}
			if ( c == 'x' ) {
				place[i][j] = 1;
			}
		}
	}
	for ( int i = 0; i < R; i++ ) {
		DFS(place, i, 0);
	}
	cout << total << endl;

	return 0;
}