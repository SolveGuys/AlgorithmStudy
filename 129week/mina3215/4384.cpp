#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

int N;
int tot[100];

int main() {
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> tot[i];
		sum += tot[i];
	}

	int avg = floor(sum / 2);
	int half = N % 2 ? int(N / 2) + 1 : int(N / 2);

	vector<vector<int>> DP(avg+1, vector<int>(half+1));

	for (int i = 0; i < avg; i++) {
		fill(DP[i].begin(), DP[i].end(), 0);
	}

	DP[0][0] = 1;

	for (int k = 0; k < N; k++) {
		for (int i = avg; i >= 0; i--) {
			for (int j = half; j >= 0;j--) {
				if (DP[i][j]) {
					if (i + tot[k] > avg || j + 1 > half)
						continue;
					DP[i + tot[k]][j + 1] = 1;
				}

			}
		}
	}
	int ans = 0;

	for (int j = 0; j < 2; j++) {
		for (int i = avg ; i >= 0; i--) {
			if (DP[i][half - j]) {
				cout << i << ' ' << sum - i;
				return 0;
			}
		}
	}
}