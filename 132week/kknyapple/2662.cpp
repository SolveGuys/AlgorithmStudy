#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;

int n, m;
int money;
int a[304][24];
int dp[304][24]; // n만원으로 m번째 회사까지 최대 이익
int ans[304][24];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> money;
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }


    for (int j = 1; j <= m; j++) {
        for (int i = 0; i <= n; i++) {
            for (int k = 0; k <= n - i; k++) {
                if (dp[i + k][j] < dp[i][j - 1] + a[k][j]) {
                    dp[i + k][j] = dp[i][j - 1] + a[k][j];
                    ans[i + k][j] = k;
                }
            }
        }
    }

    // 각 회사에 투자한 금액 추적 및 출력
    vector<int> investment(m + 1);
    int remaining = n;
    for (int j = m; j >= 1; j--) {
        investment[j] = ans[remaining][j];
        remaining -= investment[j];
    }

    cout << dp[n][m] <<"\n";
    for (int i = 1; i <= m; i++) {
        cout << investment[i] << " ";
    }

    return 0;
}
