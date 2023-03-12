#include <bits/stdc++.h>

using namespace std;

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int n;
  cin >> n;

  vector<int> a(n);

  unordered_map<int, int> seen;

  for (auto &x : a) {
    cin >> x;
    seen[x]++;
  }

  unordered_set<int> good;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int sum = a[i] + a[j];

      if (!seen[sum])
        continue;

      if (sum == a[i] and sum == a[j] and seen[sum] <= 2)
        continue;

      if (sum == a[i] and seen[sum] == 1)
        continue;

      if (sum == a[j] and seen[sum] == 1)
        continue;

      good.insert(sum);
    }
  }

  int ans = 0;

  for (auto x : a) {
    if (good.count(x))
      ans++;
  }

  cout << ans;
}
