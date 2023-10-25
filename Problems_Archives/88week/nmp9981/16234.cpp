#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//인구 정보
struct People {
    int x, y, people;
};

int n,L,R;
const int maxi = 51;
bool isMove;//이동이 일어났는가?
int world[maxi][maxi];//월드
bool visit[maxi][maxi];//방문 여부
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
    cin >> n >> L >> R;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> world[i][j];
    }
}
//초기화
void Init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)visit[i][j] = false;
    }
    isMove = false;
}
//연합
void Union(int x, int y) {
    vector<pair<int,int>> share;//공유하는 국가 위치
    share.push_back({ x,y });
    queue<People> q;
    q.push({ x,y,world[x][y] });
    visit[x][y] = true;
    int total = world[x][y];

    while (!q.empty()) {
        int curX = q.front().x;
        int curY = q.front().y;
        int human = q.front().people;
        q.pop();

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = curX + dx[k];
            int ny = curY + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;//범위 조건
            if (visit[nx][ny]) continue;//이미 방문
            if (abs(human - world[nx][ny]) >= L && abs(human - world[nx][ny]) <= R) {//인구 조건
                isMove = true;//이동이 일어남
                total += world[nx][ny];
                visit[nx][ny] = true;
                share.push_back({ nx,ny });
                q.push({ nx,ny,world[nx][ny] });
            }
        }
    }
    //월드 갱신
    if (share.size() >= 2) {
        int newPeople = total / share.size();
        for (int k = 0; k < share.size(); k++) {
            int newX = share[k].first;
            int newY = share[k].second;
            world[newX][newY] = newPeople;
        }
    }
}
//인구이동
void Move() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j]) Union(i, j);//연합
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int day = 0;
    input();//입력
    while (true) {
        Init();//초기화
        Move();//인구이동
        if (!isMove) break;//이동이 일어나지 않으면 종료
        day++;//시간 흐름
    }
    cout << day;//출력
    return 0;
}
