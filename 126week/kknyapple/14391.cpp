#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
char a[5][5];
bool check[5][5]; // false: 세로 true:가로
bool visited[5][5];
string s;
int res;

int cal() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }

    int sum = 0;
    bool dir = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) continue;

            int ny = i;
            int nx = j;
            string cur = "";
            dir = check[i][j];

            while (1) {
                if (ny >= n || nx >= m || dir != check[ny][nx]) {
                    break;
                }

                visited[ny][nx] = true;
                cur += a[ny][nx];

                if (dir) nx++;
                else ny++;
            }

            sum += stoi(cur);
        }
    }

    return sum;
}

void make(int y, int x) {
    if (y == n) {
        res = max(res, cal());
        return;
    }

    check[y][x] = true;
    if (x + 1 < m) make(y, x + 1);
    else make(y + 1, 0);

    check[y][x] = false;
    if (x + 1 < m) make(y, x + 1);
    else make(y + 1, 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    make(0, 0);

    cout << res << "\n";

    return 0;
}
