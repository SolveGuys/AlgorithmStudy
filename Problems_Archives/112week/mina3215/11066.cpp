#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T;
int sum[501][501];
int DP[501][501];

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		fill(&DP[0][0], &DP[0][0] + 501 * 501, 2e9);
		fill(&sum[0][0], &sum[0][0] + 501 * 501, 0);
		for (int i = 0; i < N; i++) {
			cin >> DP[i][i];
			DP[i][i] = 0;
		}

		// 합을 구해주는 부분. 
		for (int s = 0; s < N - 1; s++) {
			for (int e = s + 1; e < N;e++) {
				for (int i = s; i <= e;i++)
					sum[s][e] += sum[i][i];
			}
		}

		// l : idx1 ~ idx2 까지의 길이
		// s : 시작 idx1
		// m : s ~ s+l (idx1 ~ idx2) 중간 지점을 두고 돌아가면서 최소를 구한다. 
		for (int l = 1; l < N; l++) {
			for (int s = 0; s < N - l; s++) {
				for (int m = 0; m < l; m++) {
					DP[s][s + l] = min(DP[s][s + l], DP[s][s + m] + DP[s + m + 1][s + l] + sum[s][s + l]);
				}
			}
		}


		cout << DP[0][N - 1] << '\n';

	}
}