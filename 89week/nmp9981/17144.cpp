#include <iostream>
#include <vector>
using namespace std;

int r,c,T;
const int maxi = 51;
int world[maxi][maxi];//지도
vector<pair<int, int>> airCleaner;//공기 청정기
int addDust[maxi][maxi];//먼지의 추가량
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//초기화
void Init() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) addDust[i][j] = 0;
    }
}
//입력
void input() {
    cin >> r>>c>>T;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> world[i][j];
            if (world[i][j] == -1) airCleaner.push_back({ i,j });//공기청정기
        }
    }
}
//확산
void Spread() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (world[i][j] <= 0) continue;//공기 청정기, 먼지양 0

            //(i,j)에 대해 확산
            int dir = 0;//확산한 방향의 개수
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;//범위 조건
                if (world[nx][ny] == -1) continue;//공기 청정기

                addDust[nx][ny] += (world[i][j] / 5);//먼지 추가
                dir++;
            }
            world[i][j] -= (world[i][j] / 5 * dir);//남은 먼지
        }
    }
    //먼지량 갱신
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) world[i][j] += addDust[i][j];
    }
}
//공기청정기 작동
void CleanerActive() {
    int checkPoint = airCleaner[0].first;//공기청정기 위쪽 위치
    //반시계
    for(int i= checkPoint-1;i>0;i--) world[i][0] = world[i-1][0];
    for (int j = 0; j < c-1; j++) world[0][j] = world[0][j + 1];
    for (int i = 0; i < checkPoint; i++) world[i][c-1] = world[i + 1][c-1];
    for (int j = c-1; j>1; j--) world[checkPoint][j] = world[checkPoint][j - 1];
    world[checkPoint][1] = 0;//청정기 옆
    //시계
    for (int i = checkPoint + 2; i < r-1; i++) world[i][0] = world[i + 1][0];
    for (int j = 0; j < c - 1; j++) world[r-1][j] = world[r-1][j + 1];
    for (int i = r-1; i > checkPoint+1; i--) world[i][c - 1] = world[i - 1][c - 1];
    for (int j = c - 1; j > 1; j--) world[checkPoint+1][j] = world[checkPoint+1][j - 1];
    world[checkPoint+1][1] = 0;//청정기 옆
}
//먼지의 양
void AmountDust() {
    int total = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (world[i][j] > 0) total += world[i][j];
        }
    }
    cout << total;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    int times = 0;
    while (times < T) {//T초 동안
        Init();//초기화
        Spread();//확산
        CleanerActive();//공기청정기 작동
        times++;
    }
    AmountDust();//먼지의 양
    return 0;
}
