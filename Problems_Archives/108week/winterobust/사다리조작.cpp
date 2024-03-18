#include <stdio.h>

int n, m, h, ret;
int map[31][11];

// 사다리 게임의 결과가 올바른지 확인하는 함수
bool check() {
    for (int i = 1; i <= n; ++i) {
        int pos = i;
        for (int j = 0; j <= h; ++j) {
            if (map[j][pos] == 1) {
                ++pos;
            } else if (pos > 1 && map[j][pos - 1] == 1) {
                --pos;
            }
        }
        if (pos != i) {
            return false;
        }
    }
    return true;
}

// dfs를 사용하여 사다리를 놓는 함수
void dfs(int count, int y, int x) {
    if (count >= ret) return; // 이미 최적해보다 더 많은 사다리를 놓으려는 상황이므로 종료
    if (check()) { //사다리 게임 결과가 올바른 경우 ret 값을 count로 받고 종료
        ret = count;
        return;
    }
    if (count == 3) return; //사다리가 3회 놓아진 경우 종료 -> 케이스 return  (3회 초과 놓아진 경우 케이스)

    for (int i = y; i <= h; ++i) {
        for (int j = x; j < n; ++j) {
            if (map[i][j] == 0 && map[i][j - 1] == 0 && map[i][j + 1] == 0) {
                map[i][j] = 1;
                dfs(count + 1, i, j);
                map[i][j] = 0;
            }
        }
        x = 1; // 다음 행의 시작점을 초기화
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &h);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
    }

    ret = 4; // 최대 사다리 수 + 1로 초기화
    dfs(0, 1, 1);
    if (ret == 4) ret = -1; // 사다리를 놓을 수 없는 경우
    printf("%d\n", ret);

    return 0;
}
