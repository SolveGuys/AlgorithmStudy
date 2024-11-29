/*
지점이 도로나 웜홀로 연결되어 있는데, 웜홀은 시간이 거꾸로 간다
출발했을 때보다 시간이 ( - )인 경우가 있으면 YES, 아니면 NO

2 // 테스트개수
3 3 1 // 지점수, 도로개수, 웜홀개수
1 2 2 // 도로정보 (연결된두지점-방향X, 이동시간)
1 3 4
2 3 1
3 1 3 // 웜홀정보 (시작지점/도착지점-방향O, 줄어드는시간)
3 2 1 // 지점수, 도로개수,웜홀개수
1 2 3 // 도로정보
2 3 4
3 1 8 //웜홀정보
*/
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
            if (d[i][i] < 0) { // 음수 사이클 감지
                flag = true;
                break;
            }
        }

        if (flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0;
}
