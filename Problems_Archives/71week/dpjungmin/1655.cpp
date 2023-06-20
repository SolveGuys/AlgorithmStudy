#include <bits/stdc++.h>

using namespace std;

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int n;
  cin >> n;

  priority_queue<int> left;                             // max heap
  priority_queue<int, vector<int>, greater<int>> right; // min heap

  while (n--) {
    int x;
    cin >> x;

    if (!left.empty() && x <= left.top())
      left.push(x);
    else if (!right.empty() && x >= right.top())
      right.push(x);
    else
      left.push(x);

    if (left.size() > right.size() + 1) {
      right.push(left.top());
      left.pop();
    } else if (left.size() < right.size()) {
      left.push(right.top());
      right.pop();
    }

    assert(left.size() == right.size() || left.size() == right.size() + 1);

    cout << left.top() << '\n';
  }
}
