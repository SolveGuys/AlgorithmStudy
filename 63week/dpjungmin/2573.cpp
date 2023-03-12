#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n + 2, vector<int>(m + 2));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  auto connected_components = [&]() {
    int cnt = 0;
    vector<vector<bool>> vis(n + 2, vector<bool>(m + 2));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (!a[i][j] or vis[i][j])
          continue;
        cnt++;
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        while (!q.empty()) {
          auto [r, c] = q.front();
          q.pop();
          for (auto [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;
            if (a[nr][nc] and !vis[nr][nc]) {
              q.push({nr, nc});
              vis[nr][nc] = true;
            }
          }
        }
      }
    }
    return cnt;
  };

  auto tick = [&]() {
    vector<vector<int>> b(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (!a[i][j])
          continue;
        int cnt = 0;
        for (auto [dr, dc] : dirs) {
          int nr = i + dr;
          int nc = j + dc;
          if (!a[nr][nc])
            cnt++;
        }
        b[i][j] = max(a[i][j] - cnt, 0);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        a[i][j] = b[i][j];
      }
    }
  };

  int ans = 0;
  int cnt = connected_components();

  while (cnt == 1) {
    tick();
    cnt = connected_components();
    if (!cnt) {
      ans = 0;
      break;
    }
    ans++;
  };

  cout << ans;
}
