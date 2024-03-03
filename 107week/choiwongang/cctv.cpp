#include <stdio.h>

int n, m, ret = 100;
int map[8][8], backup[8][8];
int dx[] = {0, 1, 0, -1}; // 우, 하, 좌, 상
int dy[] = {1, 0, -1, 0};

typedef struct {
    int y, x, type;
} CCTV;
CCTV cctvs[8];
int cctv_count = 0;

void copy_map(int dest[8][8], int src[8][8]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dest[i][j] = src[i][j];
        }
    }
}

void fill(int y, int x, int dir) {
    dir %= 4;
    while (1) {
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x >= m || y < 0 || y >= n || map[y][x] == 6) break;
        if (map[y][x] != 0) continue; // 다른 CCTV를 만나면 계속 진행
        map[y][x] = -1; // 감시 영역 표시
    }
}

void dfs(int idx) {
    if (idx == cctv_count) {
        int candi = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (map[i][j] == 0) ++candi;
            }
        }
        if (ret > candi) ret = candi;
        return;
    }

    int backup[8][8];
    int type = cctvs[idx].type;
    int x = cctvs[idx].x, y = cctvs[idx].y;

    for (int dir = 0; dir < 4; ++dir) {
        copy_map(backup, map);
        
        if (type == 1) {
            fill(y, x, dir);
        } else if (type == 2) {
            fill(y, x, dir);
            fill(y, x, dir + 2);
        } else if (type == 3) {
            fill(y, x, dir);
            fill(y, x, dir + 1);
        } else if (type == 4) {
            fill(y, x, dir);
            fill(y, x, dir + 1);
            fill(y, x, dir + 2);
        } else if (type == 5) {
            fill(y, x, dir);
            fill(y, x, dir + 1);
            fill(y, x, dir + 2);
            fill(y, x, dir + 3);
        }

        dfs(idx + 1);
        copy_map(map, backup); // 맵 상태 복원
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &map[i][j]);
            if (map[i][j] != 0 && map[i][j] != 6) {
                cctvs[cctv_count].y = i;
                cctvs[cctv_count].x = j;
                cctvs[cctv_count].type = map[i][j];
                cctv_count++;
            }
        }
    }

    dfs(0);
    printf("%d\n", ret);
    return 0;
}
