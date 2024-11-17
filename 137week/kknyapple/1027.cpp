#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
// using ll = long long;
const int INF = 0x7f7f7f7f;
//const int INF = 0x3f3f3f3f;

int n, h[54];
int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (int k = 0; k < n; k++) {
        int cnt = 0;
        bool flag_left = false;
        bool flag_right = false;
        double plus = INF;
        double minus = INF;

        for (int i = k-1; i >=0; i--) {
            if (k==0)break;
            double l = (1.0 * (h[k] - h[i])) / (k - i);
            if (l <= 0) {
                flag_left = true;
                if (l < minus) {
                    cnt++;
                    minus = l;
                }
            }
            else {
                if (!flag_left && l < plus) {
                    cnt++;
                    plus = l;
                }
            }
        }
       
        plus = -INF;
        minus = -INF;
        for (int i = k + 1; i < n; i++) {
            if (k == n - 1)break;
            double l = (1.0 * (h[i] - h[k])) / (i - k);

            if (l >= 0) {
                flag_right = true;
                if (l > plus) {
                    cnt++;
                    plus = l;
                }
            }
            else {
                if (!flag_right && l > minus) {
                    cnt++;
                    minus = l;
                }
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans << "\n";

    return 0;
}