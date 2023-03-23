#include <bits/stdc++.h>

using namespace std;

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<pair<int, int>> pos(n + 2);

    for (auto &[x, y] : pos)
      cin >> x >> y;

    vector<int> adj[n + 2];

    for (int i = 0; i < n + 2; i++) {
      for (int j = i + 1; j < n + 2; j++) {
        auto [x1, y1] = pos[i];
        auto [x2, y2] = pos[j];
        int dist = abs(x1 - x2) + abs(y1 - y2);

        if (ceil(1.0 * dist / 50) <= 20) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    vector<bool> vis(n + 2);

    function<void(int)> dfs = [&](int x) {
      if (vis[x])
        return;

      vis[x] = true;

      for (auto nxt : adj[x])
        dfs(nxt);
    };

    dfs(0);

    cout << (vis[n + 1] ? "happy" : "sad") << '\n';
  }
}
