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

		// ���� �����ִ� �κ�. 
		for (int s = 0; s < N - 1; s++) {
			for (int e = s + 1; e < N;e++) {
				for (int i = s; i <= e;i++)
					sum[s][e] += sum[i][i];
			}
		}

		// l : idx1 ~ idx2 ������ ����
		// s : ���� idx1
		// m : s ~ s+l (idx1 ~ idx2) �߰� ������ �ΰ� ���ư��鼭 �ּҸ� ���Ѵ�. 
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