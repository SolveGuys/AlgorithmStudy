#include <bits/stdc++.h>

using namespace std;
int home[16][16];
int N;
int DP[16][16][3];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> home[i][j];
		}
	}
	//[���� ���� �밢��]
	DP[0][1][0] = 1;
	// ���θ� x +1, (x+1, y+1)
	// ���θ� y+1, (y+1, x+,1)
	// �밢�� x+1, y+1, (y+1, x+,1)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!home[i][j]) {
				// ���� = ��ĭ ���� + �밢��
				// ���� = ��ĭ ���� + �밢��
				if(j > 0)DP[i][j][0] += DP[i][j - 1][0] + DP[i][j-1][2];
				if(i > 0)DP[i][j][1] += DP[i - 1][j][1]+DP[i-1][j][2];
			}
			if (i < 1 || j < 1) continue;
			if (!home[i][j] && !home[i - 1][j] && !home[i][j - 1]){
				DP[i][j][2] += DP[i-1][j - 1][0] + DP[i-1][j - 1][1] + DP[i-1][j - 1][2];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 3; i++) {
		ans += DP[N - 1][N - 1][i];
	}
	cout << ans;
}