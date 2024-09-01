#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int n, a[2004];
int res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int s = lower_bound(a, a + n, a[i] - a[j]) - a;
            if (s == i || s == j) continue;

            if (a[s] + a[j] == a[i]) {
                res++;
                break;
            }
        }
    }

    cout << res << "\n";

    return 0;
}
