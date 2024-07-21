#include <iostream>
#include <cstdio>

using namespace std;

int a[4][4], n, m, ret;

int main() {
    // 입력
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    // 2*2 라고 했을 때 
    // s < 10000 (2진수)
    // 00000
    for (int s = 0; s < (1 << (n * m)); s++) {
        // 0을 체크 : 0은 가로
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < m; j++) {
                // k는 번호, 0~3까지 
                int k = i * m + j;
                // 0 0 0 0 0 
                if ((s & (1 << k)) == 0) {
                    cur = cur * 10 + a[i][j];
                }
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        // 1 :세로 찾기. 
        for (int j = 0; j < m; j++) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                int k = i * m + j;
                if ((s & (1 << k)) != 0) {
                    cur = cur * 10 + a[i][j];
                }
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ret = max(ret, sum);
    }
    cout << ret << '\n';
    return 0;
}