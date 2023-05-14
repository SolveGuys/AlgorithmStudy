#include <bits/stdc++.h>

using namespace std;

// 'J' = 0, 'O' = 1, 'I' = 2
int psum[1001][1001][3];

int gsum(int x1, int y1, int x2, int y2, int idx) {
  int ret = psum[x2][y2][idx];
  ret -= x1 > 0 ? psum[x1 - 1][y2][idx] : 0; // remove top
  ret -= y1 > 0 ? psum[x2][y1 - 1][idx] : 0; // remove left
  ret +=
      x1 > 0 && y1 > 0 ? psum[x1 - 1][y1 - 1][idx] : 0; // add overlapping area
  return ret;
}

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  int m, n, k;
  cin >> m >> n >> k;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;

      for (auto [ch, idx] :
           vector<pair<char, int>>{{'J', 0}, {'O', 1}, {'I', 2}}) {
        psum[i][j][idx] = psum[i][j - 1][idx] + psum[i - 1][j][idx] -
                          psum[i - 1][j - 1][idx] + (c == ch);
      }
    }
  }

  while (k--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for (int i = 0; i < 3; i++)
      cout << gsum(x1, y1, x2, y2, i) << ' ';
    cout << '\n';
  }
}
