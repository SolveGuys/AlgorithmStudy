#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n,m,blankSize;
const int maxi = 8;
int safeCount = 0;//안전지대 개수
int world[maxi][maxi];//지도
int worldCopy[maxi][maxi];//지도 복사본
vector<pair<int, int>> blank;//빈칸
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void Input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> world[i][j];
            if (world[i][j] == 0) blank.push_back({ i,j });
        }
    }
    blankSize = blank.size();
}
//확산
void Spread() {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            worldCopy[i][j] = world[i][j];//맵 복사
            if (world[i][j] == 2) q.push({ i,j });
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
            if (worldCopy[nx][ny] == 0) {//빈칸
                worldCopy[nx][ny] = 2;
                q.push({ nx,ny });
            }
        }
    }
}
//안전지대 개수
int SafeArea() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (worldCopy[i][j] == 0) cnt++;
        }
    }
    return cnt;
}
//벽세우기
void InstallWall(int idx,int cnt) {
    //벽을 다 세움
    if (cnt == 3) {
        Spread();//확산
        safeCount = max(safeCount, SafeArea());//안전지대 개수
        return;
    }
    for (int i = idx; i < blankSize; i++) {
        world[blank[i].first][blank[i].second] = 1;
        InstallWall(i + 1, cnt + 1);
        world[blank[i].first][blank[i].second] = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();//입력
    InstallWall(0,0);//벽세우기
    cout << safeCount;//출력
    return 0;
}
