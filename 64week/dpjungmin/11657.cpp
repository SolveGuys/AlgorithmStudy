#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> adj[n];

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u - 1].push_back({v - 1, w});
  }

  vector<long long> upper(n, INF);
  bool updated = false;

  upper[0] = 0;

  int it = n;
  while (it--) {
    updated = false;

    for (int u = 0; u < n; u++) {
      for (auto [v, w] : adj[u]) {
        if (upper[u] != INF and upper[v] > upper[u] + w) {
          upper[v] = upper[u] + w;
          updated = true;
        }
      }
    }

    if (!updated)
      break;
  }

  if (updated) {
    cout << -1;
    return 0;
  }

  for (int i = 1; i < n; i++)
    cout << (upper[i] == INF ? -1 : upper[i]) << '\n';
}
