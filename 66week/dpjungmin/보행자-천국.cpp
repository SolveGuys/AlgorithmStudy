#include <bits/stdc++.h>

using namespace std;

int solution(int m, int n, vector<vector<int>> city_map) {
  const int MOD = 20170805;
  int dp[m][n][2];
  memset(dp, 0, sizeof(dp));

  dp[0][0][0] = 1;
  dp[0][0][1] = 1;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (city_map[i][j] == 1)
        continue;

      if (i > 0) {
        int &x = dp[i][j][0];
        x = dp[i - 1][j][0];
        if (j and !city_map[i - 1][j])
          x += dp[i - 1][j][1];
        x %= MOD;
      }

      if (j > 0) {
        int &x = dp[i][j][1];
        x = dp[i][j - 1][1];
        if (i and !city_map[i][j - 1])
          x += dp[i][j - 1][0];
        x %= MOD;
      }
    }
  }

  int ans = (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;

  return ans;
}
