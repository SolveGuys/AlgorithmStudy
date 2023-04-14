#include <bits/stdc++.h>

using namespace std;

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int n, t;
  cin >> n >> t;

  int ans = INT_MAX;
  vector<tuple<int, int, int>> b(n);

  for (auto &[s, d, c] : b) {
    cin >> s >> d >> c;
    vector<int> a(c);

    for (int i = 0; i < c; i++)
      a[i] = s + d * i;

    auto lb = lower_bound(begin(a), end(a), t);

    if (*lb < t)
      continue;

    ans = min(ans, *lb - t);
  }

  cout << (ans == INT_MAX ? -1 : ans);
}
