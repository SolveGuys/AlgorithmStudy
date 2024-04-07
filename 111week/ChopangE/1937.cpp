#include<iostream>
#include<vector>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int DFS(vector<vector<int>> &place, vector<vector<int>> &cnt, int &n, int r, int c) {
	int tmp = 0;
	int num = place[r][c];
	for ( int i = 0; i < 4; i++ ) {
		int rr = r + dy[i];
		int cc = c + dx[i];
		if ( rr >= n || rr < 0 || cc >= n || cc < 0 )continue;
		if ( place[rr][cc] > num ) {
			if ( cnt[rr][cc] < 0 ) tmp = max(tmp, DFS(place, cnt, n, rr, cc) + 1);
			else tmp = max(tmp, cnt[rr][cc] + 1);
		}
	}
	cnt[r][c] = tmp;
	return tmp;

}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> place(n, vector<int>(n));
	vector<vector<int>> cnt(n, vector<int>(n, -1));
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			cin >> place[i][j];
		}
	}
	int ans = -1;
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			if ( cnt[i][j] < 0 ) ans = max(ans, DFS(place, cnt, n, i, j));
		}
	}
	cout << ans + 1 << endl;

	return 0;
}