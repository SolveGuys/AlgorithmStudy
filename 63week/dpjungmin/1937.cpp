#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int n;
  cin >> n;

  vector<vector<int>> a(n, vector<int>(n));

  for (auto &r : a) {
    for (auto &c : r) {
      cin >> c;
    }
  }

  // dp[i][j] = max movements that are possible when panda starts from (i, j)
  vector<vector<int>> dp(n, vector<int>(n));

  auto inside = [&](int r, int c) {
    return 0 <= r and r < n and 0 <= c and c < n;
  };

  function<int(int, int)> go = [&](int r, int c) {
    int &ret = dp[r][c];
    if (ret)
      return ret;
    ret = 1;
    for (auto [dr, dc] : dirs) {
      int nr = r + dr;
      int nc = c + dc;
      if (!inside(nr, nc) or a[r][c] >= a[nr][nc])
        continue;
      ret = max(ret, go(nr, nc) + 1);
    }
    return ret;
  };

  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans = max(ans, go(i, j));
    }
  }

  cout << ans;
}
