// 백준 14500 - 테트로미노

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;


int map[501][501];
int visit[501][501];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int N, M, res=0;

void GetMaxNum(int x, int y, int depth, int temp) {

    if(depth == 4) { // 깊이가 4가 되면
        if(res < temp) res = temp;
        return;
    }

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > N || ny > M || visit[nx][ny]) 
            continue;

        visit[nx][ny] = 1;
        GetMaxNum(nx, ny, depth+1, temp+map[nx][ny]);
        visit[nx][ny] = 0; // 백트래킹
    }

    // ㅓ
    if(x-1 >= 1 && y-1 >= 1 && x+1 <= N) {
        res = max(res, (map[x-1][y] + map[x][y-1] + map[x][y] + map[x+1][y]));
    }
    // ㅏ
    if(x-1 >= 1 && y+1 <= M && x+1 <= N) { 
        res = max(res, (map[x-1][y] + map[x][y+1] + map[x][y] + map[x+1][y]));
    }
    // ㅗ
    if(y-1 >= 1 && y+1 <= M && x+1 <= N) { 
        res = max(res, (map[x][y] + map[x+1][y] + map[x+1][y-1] + map[x+1][y+1]));
    }
    // ㅜ
    if(y-1 >= 1 && y+1 <= M && x+1 <= N) { 
        res = max(res, (map[x][y-1] + map[x][y] + map[x][y+1] + map[x+1][y]));
    }

}

int main() {

    memset(visit, 0, sizeof(visit));

    cin >> N >> M;
    for(int i=1; i<=N; i++) { 
        for(int j=1; j<=M; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            visit[i][j] = 1;
            GetMaxNum(i, j, 1, map[i][j]);
            visit[i][j] = 0; // 백트래킹
        }
    }
    cout << res;
}
