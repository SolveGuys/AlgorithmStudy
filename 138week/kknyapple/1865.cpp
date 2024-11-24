#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;
const int INF = 0x3f3f3f3f;

int tc;
int n, m, w;
int s, e, t;
int d[504][504];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m >> w;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = INF;
            }
        }
        while(m--){
            cin >> s >> e >> t;
            d[s][e] = min(d[s][e], t);
            d[e][s] = min(d[e][s], t);
        }
        while (w--) {
            cin >> s >> e >> t;
            d[s][e] = min(d[s][e], -t);
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
                }
            }
        }

        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (d[i][i] < 0) {
                flag = true;
                break;
            }
        }

        if (flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0;
}
