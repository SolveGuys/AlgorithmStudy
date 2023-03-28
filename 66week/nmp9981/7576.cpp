#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

//토마토 정보
struct TomatoInfo {
    int x,y;
};
int n,m;
const int maxi = 1001;
int day = 0;
int board[maxi][maxi];//판
int Day[maxi][maxi];//날짜
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    memset(Day, -1, sizeof(Day));//초기화
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> board[i][j];
    }
}
//토마토
void Tomato() {
    queue<TomatoInfo> q;
    //맨처음 토마토 넣기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                q.push({ i,j });
                Day[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        //다음 지점
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
            if (Day[nx][ny] != -1) continue;//방문 조건
            if (board[nx][ny] != 0) continue;//장애물

            board[nx][ny] = 1;//익음
            Day[nx][ny] = Day[x][y] + 1;
            q.push({ nx,ny });
        }
    }
}
//확인
void Check() {
    //빈칸 여부
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) {//빈칸이 남아있다면
                cout << -1;
                return;
            }
        }
    }
    //날짜
    int maxDay = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) maxDay = max(maxDay, Day[i][j]);
    }
    cout << maxDay;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Tomato();//토마토
    Check();//확인
    return 0;
}
