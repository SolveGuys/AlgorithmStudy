#include <bits/stdc++.h>

using namespace std;

struct disjoint_set {
  vector<int> p, rank;
  disjoint_set(int n) : p(n), rank(n, 1) { iota(begin(p), end(p), 0); }
  int find(int u) {
    if (u == p[u])
      return u;
    return p[u] = find(p[u]);
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    if (rank[u] > rank[v])
      swap(u, v);
    p[u] = v;
    if (rank[u] == rank[v])
      rank[v]++;
  }
};

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n, k;
    cin >> n >> k;

    disjoint_set s(n);

    while (k--) {
      int u, v;
      cin >> u >> v;
      s.merge(u, v);
    }

    cout << "Scenario " << i << ":\n";

    int m;
    cin >> m;

    while (m--) {
      int u, v;
      cin >> u >> v;
      cout << (s.find(u) == s.find(v)) << '\n';
    }

    cout << '\n';
  }
}
