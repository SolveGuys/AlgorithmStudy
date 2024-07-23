#include<iostream>
#include<vector>

using namespace std;

int T;
int DP[21][10001];

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {

		fill(&DP[0][0], &DP[0][0] + 21 * 10001, 0);
		int N, M;
		cin >> N;
		vector<int> coin;
		coin.push_back(0);
		for (int n = 1; n <= N; n++) {
			int c;
			cin >> c;
			DP[n][0] = 1;
			coin.push_back(c);
		}
		cin >> M;

		for (int i = 1;i <= N; i++) {
			for (int price = 1; price <= M; price++) {
				if (price < coin[i]) {
					DP[i][price] = DP[i - 1][price];
				}
				else DP[i][price] = DP[i - 1][price] + DP[i][price - coin[i]];
			}
		}
		cout << DP[N][M]<<'\n';
	}
}