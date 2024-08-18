#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

int n, a[104];
int total;
bool d[104][45004];
int res1, res2;
int diff = 500;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    // i명의 사람을 선택해 j 무게를 만들 수 있는지
    d[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = n / 2; j > 0; j--) {
            for (int k = total; k >= a[i]; k--) {
                d[j][k] = d[j][k] || d[j - 1][k - a[i]];
            }
        }
    }

    for (int i = 0; i <= total; i++) {
        if (d[n / 2][i] == true) {
            int a = i;
            int b = total - i;
            if (a < b) swap(a, b);

            if (diff > a - b) {
                diff = a - b;
                res1 = b;
                res2 = a;
            }
        }
    }
    cout << res1 << " " << res2 << "\n";

    return 0;
}
