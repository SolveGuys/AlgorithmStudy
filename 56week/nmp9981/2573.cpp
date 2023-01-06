#include <iostream>
#include <queue>
using namespace std;

int n,m;
const int maxi = 301;
int year = 0;
int world[maxi][maxi];//지도
int melt[maxi][maxi];//녹는양
int visit[maxi][maxi];//방문 여부
int dx[4] = { -1,1,0,0 };//축 이동
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//초기화
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = false;
            melt[i][j] = 0;
        }
    }
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> world[i][j];
    }
}
//다 녹았는가?
bool isAllMelt() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] != 0) return false;//안 녹은게 있다
        }
    }
    return true;
}
//bfs탐색
void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i,j });
    visit[i][j] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
            if (visit[nx][ny] == true) continue;//방문 조건
            if (world[nx][ny] == 0) continue;//물 지역

            q.push({ nx,ny });
            visit[nx][ny] = true;//방문체크
        }
    }
}
//덩어리 개수 세기
int lump() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 0) continue;//물 지역
            if (!visit[i][j]) {
                bfs(i, j);//bfs탐색
                cnt++;
            }
        }
    }
    return cnt;
}
//얼음 녹이기
void MeltIce() {
    //녹이는 양
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 0) continue;//물 지역
            //주위 바닷물 개수
            int seaCnt = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
                if (world[nx][ny] == 0) seaCnt++;//주위에 바닷물이 있다.
            }
            melt[i][j] = seaCnt;
        }
    }
    //녹이기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) world[i][j] = max(0, world[i][j] - melt[i][j]);
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    while (true) {
        init();//초기화
        if (isAllMelt()) {//모두 녹았는가?
            cout << 0;
            break;
        }
        if (lump() >= 2) {//두 덩어리 이상으로 분리 가능
            cout << year;//출력
            break;
        }
        MeltIce();//얼음 녹이기
        year++;
    }
    return 0;
}
