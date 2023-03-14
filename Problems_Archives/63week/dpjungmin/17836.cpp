#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int n, m, t;
  cin >> n >> m >> t;

  vector<vector<int>> a(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  int ans = INT_MAX;
  queue<tuple<int, int, int>> q;

  q.push({0, 0, 0});
  a[0][0] = -1;

  while (!q.empty()) {
    auto [r, c, cnt] = q.front();
    q.pop();

    if (r == n - 1 and c == m - 1) {
      ans = min(ans, cnt);
      break;
    }

    for (auto [dr, dc] : dirs) {
      int nr = r + dr;
      int nc = c + dc;
      if (0 <= nr and nr < n and 0 <= nc and nc < m) {
        if (a[nr][nc] == -1 or a[nr][nc] == 1)
          continue;
        if (a[nr][nc] == 2)
          ans = cnt + 1 + (n - 1 - nr) + (m - 1 - nc);
        q.push({nr, nc, cnt + 1});
        a[nr][nc] = -1;
      }
    }
  }

  if (ans > t)
    cout << "Fail";
  else
    cout << ans;
}
