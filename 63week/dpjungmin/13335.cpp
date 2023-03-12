#include <bits/stdc++.h>

using namespace std;

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int n, len, limit;
  cin >> n >> len >> limit;

  vector<int> weight(n);

  for (auto &x : weight)
    cin >> x;

  int ans = 0;
  queue<int> q;

  for (int i = 0, w_sum = 0; i < n; ans++) {
    // A truck has passed the bridge!
    if ((int)q.size() == len) {
      int w = q.front();
      q.pop();
      w_sum -= w;
    }

    // Can we send the ith truck?
    if (int w = weight[i]; w_sum + w <= limit) {
      q.push(w);
      w_sum += w;
      i++;
      continue;
    }

    // If not, lets simulate by sending a truck that weighs 0.
    q.push(0);
  }

  // We don't care how many trucks are on the bridge.
  // The last truck takes 'len' to pass the bridge.
  cout << ans + len;
}
