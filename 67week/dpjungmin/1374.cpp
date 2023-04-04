#include <bits/stdc++.h>

using namespace std;

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int n;
  cin >> n;

  vector<pair<int, int>> a(n);

  for (auto &[s, e] : a)
    cin >> s >> s >> e;

  sort(begin(a), end(a));
  priority_queue<int, vector<int>, greater<int>> mnh;

  for (auto [s, e] : a) {
    if (!mnh.empty() and mnh.top() <= s)
      mnh.pop();
    mnh.push(e);
  }

  cout << mnh.size();
}
