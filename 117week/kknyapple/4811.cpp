#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <stack>
#include <queue>
#include <string>
using namespace std;

long long dp[32][32]; // 알약을 먹을 수 있는 가지 수 저장
int n;

int main() {
  /*
    w: 한 개, h; 반 개
    dp[w][0] = dp[w - 1][1]
    dp[0][h] = 1
    dp[w][h] = dp[w - 1][h + 1] + dp[w][h - 1] // 한 개를 먹을 경우(반 개가 생김) + 반 개를 먹을 경우

    dp[2][0] = dp[1][1]
             = dp[1][0] + dp[0][2]
             = 1 = 1 
             = 2

    1 -> 1
    2 -> 2
    3 -> 5
    4 -> 14
    6 -> 132
*/

  
	for (int i = 1; i <= 30; i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i <= 30; i++) {
		for (int j = 0; j <= 30; j++) {
			if (j == 0)dp[i][0] = dp[i - 1][1];
			else dp[i][j] = dp[i - 1][j + 1] + dp[i][j - 1];
		}
	}

	while (1) {
		cin >> n;
		if (n == 0) break;

		cout << dp[n][0] << "\n";
	}

	return 0;
}
