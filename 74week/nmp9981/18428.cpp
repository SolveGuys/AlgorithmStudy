#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxi = 6;
int teacherSize;
char world[maxi][maxi];//지도
bool watchResult = false;//감시 결과
vector<pair<int, int>> teacher;//교사
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> world[i][j];
            if (world[i][j] == 'T') teacher.push_back({ i,j });
        }
    }
    teacherSize = teacher.size();
}
//감시
bool Watch() {
    for(int t=0;t<teacherSize;t++) {
        int x = teacher[t].first;
        int y = teacher[t].second;

        for (int k = 0; k < 4; k++) {
            int nx = x; int ny = y;
            while (true) {
                nx = nx + dx[k];
                ny = ny + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;;//범위 초과
                if (world[nx][ny] == 'O') break;//벽
                if (world[nx][ny] == 'S') return true;//감시 성공
            }
        }
    }
    return false;//감시 실패
}
//벽 설치
void InstallWall(int cnt) {
    if (cnt == 3) {//벽 모두 설치
        if (!Watch()) watchResult = true;//성공
        return;
    }
    //다음 지점
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (world[i][j] == 'X') {
                world[i][j] = 'O';
                InstallWall(cnt + 1);//다음 벽
                world[i][j] = 'X';
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    InstallWall(0);//벽 설치
    //출력
    if (watchResult) cout << "YES";
    else cout << "NO";
    return 0;
}
