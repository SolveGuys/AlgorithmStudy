#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
using ll = long long;

int n, k;
int dp[1004][1004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    if (n / 2 < k) { // 색을 n/2이상 선택할 때 경우의 수 0개
        cout << 0 << "\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        dp[i][1] = i; // i번째에서 1개만 선택할 경우
    }
    dp[n - 3][0] = 1;
    for (int i = 3; i < n; i++) {
        for (int j = 2; j <= k; j++) {
            if (j > i / 2 + 1) break; // n=5, k=3일 때 가능
            // i번째까지 j개를 선택하는 경우의 수 = (i번째 선택) + (i번째 선택 안함) = (i-2번째에서 j-1번째 선택) + (i-1번째에서 j개 선택)
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % 1000000003;
        }
    }

    // 원형 모양이라 마지막은 (i번째 선택) + (i번째 선택 안함) = (i-3개에서 j-1번째 선택) + (i-1번째에서 j개 선택)
    cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % 1000000003 << "\n"; 

    return 0;
}
