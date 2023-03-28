#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int n, m;
  cin >> m >> n;

  int cnt = 0;
  vector<vector<int>> a(n, vector<int>(m));
  queue<pair<int, int>> q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int &x = a[i][j];
      cin >> x;
      if (!x)
        cnt++;
      else if (x == 1)
        q.push({i, j});
    }
  }

  int ans = 0;

  auto inside = [&](int r, int c) {
    return 0 <= r and r < n and 0 <= c and c < m;
  };

  while (!q.empty()) {
    auto sz = q.size();
    bool updated = false;

    while (sz--) {
      auto [r, c] = q.front();
      q.pop();

      for (auto [dr, dc] : dirs) {
        int nr = r + dr;
        int nc = c + dc;

        if (inside(nr, nc) and a[nr][nc] == 0) {
          q.push({nr, nc});
          a[nr][nc] = 1;
          updated = true;
          cnt--;
        }
      }
    }

    if (updated)
      ans++;
  }

  cout << (!cnt ? ans : -1);
}
