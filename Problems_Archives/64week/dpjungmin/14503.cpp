#include <bits/stdc++.h>

using namespace std;

// 북동남서
vector<pair<int, int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int n, m;
  cin >> n >> m;

  int r, c, d;
  cin >> r >> c >> d;

  vector<vector<int>> a(n, vector<int>(m));

  for (auto &r : a) {
    for (auto &c : r) {
      cin >> c;
    }
  }

  auto inside = [&](int r, int c) {
    return 0 <= r and r < n and 0 <= c and c < m;
  };

  int ans = 0;

  while (1) {
    if (a[r][c] == 0) {
      a[r][c] = 2;
      ans++;
    }

    bool can = false;

    for (auto [dr, dc] : dirs) {
      int nr = r + dr;
      int nc = c + dc;
      if (inside(nr, nc) and a[nr][nc] == 0) {
        can = true;
        break;
      }
    }

    if (!can) {
      auto [dr, dc] = dirs[(d + 2) % 4];
      int nr = r + dr;
      int nc = c + dc;
      if (!inside(nr, nc) or a[nr][nc] == 1)
        break;
      r = nr;
      c = nc;
    } else {
      d = (d + 3) % 4;
      auto [dr, dc] = dirs[d];
      int nr = r + dr;
      int nc = c + dc;
      if (inside(nr, nc) and a[nr][nc] == 0) {
        r = nr;
        c = nc;
      }
    }
  }

  cout << ans;
}
