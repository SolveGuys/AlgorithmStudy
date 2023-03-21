#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n + 4, vector<int>(m + 4));

  for (int i = 2; i <= n + 1; i++) {
    for (int j = 2; j <= m + 1; j++) {
      cin >> a[i][j];
    }
  }

  int ans = 0;
  vector<vector<bool>> vis(n + 4, vector<bool>(m + 4));

  auto inside = [&](int r, int c) {
    return 2 <= r and r <= n + 1 and 2 <= c and c <= m + 1;
  };

  function<int(int, int, int)> go = [&](int r, int c, int cnt) {
    if (cnt == 4)
      return a[r][c];

    int sum = 0;

    for (auto [dr, dc] : dirs) {
      int nr = r + dr;
      int nc = c + dc;

      if (!inside(nr, nc) or vis[nr][nc])
        continue;

      vis[nr][nc] = true;
      sum = max(sum, a[r][c] + go(nr, nc, cnt + 1));
      vis[nr][nc] = false;
    }

    return sum;
  };

  for (int i = 2; i <= n + 1; i++) {
    for (int j = 2; j <= m + 1; j++) {
      vis[i][j] = true;
      ans = max({
          ans,
          go(i, j, 1),
          a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i][j - 1],
          a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i][j + 1],
          a[i][j] + a[i][j - 1] + a[i][j + 1] + a[i - 1][j],
          a[i][j] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j],
      });
      vis[i][j] = false;
    }
  }

  cout << ans;
}
