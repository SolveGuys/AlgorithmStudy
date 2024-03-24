#include <stdio.h>
#include <stdbool.h>

int N;
bool grid[101][101];
int dx[4] = {1, 0, -1, 0};  
int dy[4] = {0, -1, 0, 1};

int turn(int d) {
    return (d + 1) % 4;
}

void draw_curve(int x, int y, int d, int g) {
    int directions[1024] = {d}; 
    int count = 1; 

    for (int i = 0; i < g; i++) {
        int prevCount = count;
        for (int j = prevCount - 1; j >= 0; j--) {
            directions[count++] = turn(directions[j]);
        }
    }
    
    grid[y][x] = true;

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
