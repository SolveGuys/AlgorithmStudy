#include <bits/stdc++.h>

using namespace std;

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int n;
  cin >> n;

  vector<int> adj[n + 1];
  vector<int> a(n + 1);

  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    adj[p].push_back(i);
    adj[i].push_back(p);
  }

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  // dp[i][0] = synergy when i is excluded
  // dp[i][1] = synergy when i is a subordinate
  // dp[i][2] = synergy when i is a supervisor
  //
  // dp[i][0] = sum of all max(dp[j][0], dp[j][2]) where j is all the children
  // nodes of i
  //
  // dp[i][1] = (synergy when i is paired with its parent node) + (sum of all
  // max(dp[j][0], dp[j][2]) where j is all the children nodes of i)
  //
  // dp[i][2] = max(dp[i][2], dp[i][0] + dp[j][1] - max(dp[j][0], dp[j][2]))
  // where j is all the children nodes of i
  //
  // Why dp[i][0] + dp[j][1] - max(dp[j][0], dp[j][2])?
  // dp[i][0] contains the sum of the synergy with all its children nodes when i
  // is excluded. However, we want to pair i with exactly one of its children.
  // dp[j][1] is the synergy value when i is paired with j, and dp[i][0] -
  // max(dp[j][0], dp[j][2]) is the synergy value when i is excluded with all
  // the other children nodes except j.
  int dp[n + 1][3];
  memset(dp, 0, sizeof(dp));

  function<void(int, int)> go = [&](int u, int p) {
    for (int v : adj[u]) {
      if (v != p)
        go(v, u);
    }
    if (u != p)
      dp[u][1] = a[u] * a[p];
    for (int v : adj[u]) {
      if (v != p) {
        int x = max(dp[v][0], dp[v][2]);
        dp[u][0] += x;
        dp[u][1] += x;
      }
    }
    for (int v : adj[u]) {
      if (v != p)
        dp[u][2] = max(dp[u][2], dp[u][0] + dp[v][1] - max(dp[v][0], dp[v][2]));
    }
  };

  go(1, 1);

  cout << max(dp[1][0], dp[1][2]);
}
