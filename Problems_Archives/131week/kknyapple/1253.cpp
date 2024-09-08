#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int n, a[2004];
bool b[2004];
int res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n); // 이분 탐색을 위한 정렬

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int s = lower_bound(a, a + n, a[i] + a[j]) - a; // a[i] + a[j]의 처음 위치
            int e = upper_bound(a, a + n, a[i] + a[j]) - a; // a[i] + a[j] 마지막 위치

            for (int k = s; k < e; k++) {
                if (b[k]) break; // 이미 true인 경우
                if (k == i || k == j) continue; // 다른 숫자가 아닌 경우
                b[k] = true; // 다른 수 두 개의 합으로 나타낼 수 있는 숫자
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (b[i]) {
            res++; // 좋은 수의 개수
        }
    }

    cout << res << "\n";

    return 0;
}
