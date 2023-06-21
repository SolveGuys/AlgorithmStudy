#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int x, y, cnt;
};

int n,w,h;
const int maxi = 201;
int world[maxi][maxi];//월드
int visit[maxi][maxi][31];//각 지점에서 k번 했을때의 방문 횟수
//12방 탐색
int dx[12] = { 0,0,1,-1,-2,-2,-1,-1,1,1,2,2};
int dy[12] = { 1,-1,0,0,-1,1,-2,2,-2,2,-1,1 };

//초기화
void init() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k <= n; k++) visit[i][j][k] = -1;
        }
    }
}
//입력
void input() {
    cin >> n>>w>>h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cin >> world[i][j];
    }
}

//이동
int Move() {
    queue<Point> q;
    q.push({ 0,0,0 });
    visit[0][0][0] = 0;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();

        if (x == h - 1 && y == w - 1) return visit[x][y][cnt];//도착

        for (int i = 0; i < 12; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;//범위 조건
            if (world[nx][ny] == 1) continue;//장애물

            if (i < 4) {//그냥 이동
                if (visit[nx][ny][cnt] != -1) continue;//이미 방문
                visit[nx][ny][cnt] = visit[x][y][cnt]+1;
                q.push({ nx,ny,cnt });
            }
            else {//기술 사용
                if (cnt < n) {
                    if (visit[nx][ny][cnt+1] != -1) continue;//이미 방문
                    visit[nx][ny][cnt+1] = visit[x][y][cnt]+1;
                    q.push({ nx,ny,cnt+1 });
                }
            }
        }
    }
    return -1;//도달 불가
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    init();//초기화
    cout<<Move();//이동
    return 0;
}
