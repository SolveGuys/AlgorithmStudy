#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int times = 0;//시간
const int maxi = 101;
int restCheese = 0;
int world[maxi][maxi];//맵
bool visit[maxi][maxi];//방문 여부
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//초기화
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = false;
            if(world[i][j]==2) world[i][j] = 0;//원래대로
        }
    }
}
//입력
void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> world[i][j];
            if (world[i][j] == 1) restCheese++;//처음 치즈량
        }
    }
}
//모서리와 연결 여부
void EdgeConnect(int i, int j) {
    queue<pair<int, int>> q;
    q.push({ i,j });
    visit[i][j] = true;
    vector<pair<int, int>> connect;//연결 위치
    connect.push_back({ i,j });
    bool isEdge = false;//모서리에 닿는가?

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) isEdge = true;//바깥쪽과 연결?
        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 초과
            if (visit[nx][ny]) continue;//방문 조건
            if (world[nx][ny] == 1) continue;//치즈

            visit[nx][ny] = true;
            q.push({ nx,ny });
            connect.push_back({ nx,ny });
        }
    }
    //모서리와 연결된 부분은 2로 표시
    if (isEdge == true) {
        for (int k = 0; k < connect.size(); k++) {
            int x = connect[k].first;
            int y = connect[k].second;
            world[x][y] = 2;
        }
    }
}
//홀 탐색
void Hole() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 0 && !visit[i][j]) EdgeConnect(i, j);
        }
    }
}
//공기 접촉
void AirTouch() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 1) {
                bool isOut = false;//바깥쪽과 연결?
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (world[nx][ny] == 2) isOut = true;//바깥쪽과 연결
                }
                if(isOut) world[i][j] = 0;//녹음
            }
        }
    }
}
//치즈 양
int CheeseAmount() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] == 1) cnt++;
        }
    }
    if (cnt > 0) restCheese = cnt;//녹기 전 치즈양
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    while (true) {
        times++;//시간 흐름
        init();//초기화
        Hole();//홀 탐색
        AirTouch();//공기 접촉
        if (CheeseAmount() == 0) break;//치즈 양
    }
    //출력
    cout << times << "\n";
    cout << restCheese << "\n";
    return 0;
}
