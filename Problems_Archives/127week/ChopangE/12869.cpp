#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;

int N;

int total = 30;

int dp[61][61][61];

int DP(int x, int y, int z) {
	if (x < 0) {
		return DP(0, y, z);
	}
	if (y < 0) {
		return DP(x, 0, z);
	}
	if (z < 0) {
		return DP(x, y, 0);
	}
	if (x == 0 && y == 0 && z == 0)return 0;

	if (dp[x][y][z] > 0)return dp[x][y][z];

	int tmp = 30;
	tmp = min(tmp,1 + DP(x - 9, y - 3, z - 1));
	tmp = min(tmp,1 + DP(x - 9, y - 1, z - 3));
	tmp = min(tmp,1 + DP(x - 3, y - 9, z - 1));
	tmp = min(tmp,1 + DP(x - 3, y - 1, z - 9));
	tmp = min(tmp,1 + DP(x - 1, y - 9, z - 3));
	tmp = min(tmp,1 + DP(x - 1, y - 3, z - 9));
	dp[x][y][z] = tmp;
	return tmp;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	memset(dp, -1, sizeof(dp));
	int d[3] = { 0 };
	for (int i = 0; i < N; i++) {
		cin >> d[i];
	}
	total = DP(d[0], d[1], d[2]);
	cout << total << endl;


	return 0;
}