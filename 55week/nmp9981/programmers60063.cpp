#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct Pos {
    int xpos, ypos, direction, cnt;
};

int n;//board크기
const int maxi = 101;
bool visit[maxi][maxi][4];//방문 시간
vector<vector<int>> board = { {0,0,0,1,1},{0,0,0,1,0},{0,1,0,1,1},{1,1,0,0,1},{0,0,0,0,0} };

int dx[4] = { 0,-1,0,1 }; int dy[4] = { -1,0,1,0 };//탐색

//탐색 가능한가?
bool isNotCan(int nx, int ny, vector<vector<int>> board) {
    if (nx < 0 || nx >= n || ny < 0 || ny >= n) return true;//범위체크
    if (board[nx][ny] == 1) return true;//장애물
    return false;
}
//로봇 이동
int Move(vector<vector<int>> board) {
    n = board.size();
    memset(visit, false, sizeof(visit));//초기화
    queue<Pos> q;//로봇의 앞쪽 정보
    //앞쪽을 넣기
    q.push({ 0,1,0,0 });//위치, 방향, 시간
    visit[0][1][0] = true;
    q.push({ 0,0,2,0 });
    visit[0][0][2] = true;

    while (!q.empty()) {
        //현재 로봇 정보
        int x1 = q.front().xpos; int y1 = q.front().ypos;//위치
        int dir = q.front().direction;//방향
        int sec = q.front().cnt;//시간
        q.pop();
        int x2 = x1 + dx[dir]; int y2 = y1 + dy[dir];//로봇 뒤쪽 위치
        //방문 완료
        if ((x1 == n - 1 && y1 == n - 1) || (x2 == n - 1 && y2 == n - 1)) return sec;

        //다음 지점
        for (int i = 0; i < 4; i++) {
            int nx1 = x1 + dx[i]; int ny1 = y1 + dy[i];
            int nx2 = x2 + dx[i]; int ny2 = y2 + dy[i];

            //탐색 가능 지점인가?
            if (isNotCan(nx1, ny1, board) || isNotCan(nx2, ny2, board)) continue;

            //방문여부
            if (visit[nx1][ny1][dir] == false) {
                visit[nx1][ny1][dir] = true;
                q.push({ nx1,ny1,dir,sec + 1 });
            }
            if (visit[nx2][ny2][(dir + 2) % 4] == false) {//앞면이 바뀜
                visit[nx2][ny2][(dir + 2) % 4] = true;
                q.push({ nx2,ny2,(dir + 2) % 4,sec + 1 });
            }
            //회전 가능할 때
            if ((dir + 1) % 2 == i % 2) {
                if (visit[nx1][ny1][i] == false) {
                    visit[nx1][ny1][i] = true;
                    q.push({ nx1,ny1,i,sec + 1 });
                }
                if (visit[nx2][ny2][(i + 2) % 4] == false) {//앞면 변경
                    visit[nx2][ny2][(i + 2) % 4] = true;
                    q.push({ nx2,ny2,(i + 2) % 4,sec + 1 });
                }
            }
        }
    }
    return 0;
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int answer = Move(board);
    cout << answer<<"\n";
	return 0;
}
