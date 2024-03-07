#include<iostream>
#include<algorithm>

using namespace std;

int DP[10002][3];

int amount[10002];

int N;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> amount[i];
	}
	fill(&DP[0][0], &DP[0][0] + 3 * 10002, 0);
	for (int i = 1; i <= N; i++) {
		DP[i][0] = max(DP[i-1][0], DP[i - 1][2]);
		DP[i][0] = max(DP[i - 1][1], DP[i][0]);
		DP[i][1] = DP[i - 1][0] + amount[i];
		DP[i][2] = DP[i - 1][1] + amount[i];
	}

	int res = max(DP[N][0], DP[N][1]);
	res = max(res, DP[N][2]);

	cout<< res;


}