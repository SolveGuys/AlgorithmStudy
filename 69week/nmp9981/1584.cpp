#include <iostream>
#include <deque>
using namespace std;

//위치 정보
struct Pos {
    int x,y,life;
};
int n, m;
const int maxi = 501;
int world[maxi][maxi];//지도
bool visit[maxi][maxi];//방문 여부
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//max
inline int max(int x, int y) {
    return x > y ? x : y;
}

//입력
void input() {
    //위험 지역
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int minX = min(x1, x2);
        int maxX = max(x1, x2);
        int minY = min(y1, y2);
        int maxY = max(y1, y2);
        for (int i = minX; i <= maxX; i++) {
            for (int j = minY; j <= maxY; j++) world[i][j] = 1;
        }
    }
    //죽음 지역(더 강한 지역이므로 더 나중에 설정한다.)
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int minX = min(x1, x2);
        int maxX = max(x1, x2);
        int minY = min(y1, y2);
        int maxY = max(y1, y2);
        for (int i = minX; i <= maxX; i++) {
            for (int j = minY; j <= maxY; j++) world[i][j] = 2;
        }
    }
}

//플레이
void Play() {
    visit[0][0] = true;
    deque<Pos> dq;
    dq.push_back({ 0,0,0 });

    while (!dq.empty()) {
        int x = dq.front().x;
        int y = dq.front().y;
        int life = dq.front().life;
        dq.pop_front();

        if (x == 500 && y == 500) {//도착
            cout << life;
            return;
        }

        //다음 지점
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= maxi || ny < 0 || ny >= maxi) continue;//범위 초과
            if (visit[nx][ny] == true) continue;//이미 방문
            if (world[nx][ny] == 2) continue;//죽음 지역

            visit[nx][ny] = true;
            if (world[nx][ny] == 1) dq.push_back({ nx,ny,life + 1 });//위험
            else dq.push_front({ nx,ny,life });//안전(더 작은 life가 앞에)
        }
    }
    cout<<-1;//도착 불가
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Play();//게임 플레이
    return 0;
}
