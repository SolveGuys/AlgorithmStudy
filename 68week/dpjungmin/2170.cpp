#include <bits/stdc++.h>

using namespace std;

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int n;
  cin >> n;

  vector<pair<int, int>> a(n);

  for (auto &[x, y] : a)
    cin >> x >> y;

  sort(begin(a), end(a));

  vector<pair<int, int>> b;

  for (auto [start, end] : a) {
    if (b.empty()) {
      b.push_back({start, end});
      continue;
    }

    auto &[_, prev_end] = b.back();

    if (prev_end < start)
      b.push_back({start, end});
    else
      prev_end = max(prev_end, end);
  }

  int ans = 0;

  for (auto [x, y] : b)
    ans += y - x;

  cout << ans;
}
