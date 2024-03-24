#include <stdio.h>
#include <stdbool.h>
// 총 동작 횟수 1+ 2+ 4+ ... + 1024 = 2047
int N;
bool grid[101][101];
int dx[4] = {1, 0, -1, 0};  
int dy[4] = {0, -1, 0, 1};
//동,북,서,남
int turn(int d) {
    //90도 회전을 위해서
    return (d + 1) % 4;
}

void draw_curve(int x, int y, int d, int g) {
    //세대 10개 90 도 회전 -> 2배씩 방향이 증가 2^10 = 1024
    int directions[1024] = {d}; 
    //count 현재까지의 방향의 수를 의미
    int count = 1; 
    
    for (int i = 0; i < g; i++) {
        //현재 세대의 방향의 총수를 저장
        int prevCount = count;
        //역수로 for문을 돔 
        for (int j = prevCount - 1; j >= 0; j--) {
            directions[count++] = turn(directions[j]);
        }
    }
    
    grid[y][x] = true;
    //실제 이동 구현 mapping
    for (int i = 0; i < count; i++) {
        x += dx[directions[i]];
        y += dy[directions[i]];
        grid[y][x] = true;
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x, y, d, g;
        scanf("%d %d %d %d", &x, &y, &d, &g);
        draw_curve(x, y, d, g);
    }

    int result = 0;
    // 정사각형 갯수 세기
    for (int i = 0; i < 101 - 1; i++) {
        for (int j = 0; j < 101 - 1; j++) {
            if (grid[i][j] && grid[i+1][j] && grid[i][j+1] && grid[i+1][j+1]) {
                result++;
            }
        }
    }

    printf("%d\n", result);
    return 0;
}
