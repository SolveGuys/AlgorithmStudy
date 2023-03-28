#include <bits/stdc++.h>

using namespace std;

int sudoku[9][9];
bool row[9][10], col[9][10], box[9][10];

void go(int n) {
  if (n == 81) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++)
        cout << sudoku[i][j] << ' ';
      cout << '\n';
    }
    exit(0);
  }
  int r = n / 9;
  int c = n % 9;
  if (sudoku[r][c]) {
    go(n + 1);
    return;
  }
  for (int k = 1; k <= 9; k++) {
    int x = (r / 3) * 3 + c / 3;
    if (!row[r][k] && !col[c][k] && !box[x][k]) {
      sudoku[r][c] = k;
      row[r][k] = true;
      col[c][k] = true;
      box[x][k] = true;
      go(n + 1);
      sudoku[r][c] = 0;
      row[r][k] = false;
      col[c][k] = false;
      box[x][k] = false;
    }
  }
}

int main(void) {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(ios::badbit | ios::failbit);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> sudoku[i][j];
      int k = sudoku[i][j];
      if (k) {
        row[i][k] = true;
        col[j][k] = true;
        box[(i / 3) * 3 + j / 3][k] = true;
      }
    }
  }

  go(0);
}
