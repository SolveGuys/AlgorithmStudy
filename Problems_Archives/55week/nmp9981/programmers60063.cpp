#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Robot {//로봇 상태
    int time;//시간
    int x, y;//위치
    int type;//가로, 세로
};
int n;//board크기
const int maxi = 101;
bool visit[maxi][maxi][2];//방문 여부(위치, 모양)
int dx[4] = { 1,-1,0,0 }; int dy[4] = { 0,0,1,-1 };//이동

//체크
bool isPossible(int x,int y, int type, vector<vector<int>> board) {
    if (type == 0) {//가로
        if (x < 0 || x >= n || y < 0 || y + 1 >= n) return false;//범위 조건
        if (board[x][y] == 1 || board[x][y + 1] == 1) return false;//장애물
    }
    else if (type == 1) {//세로
        if (x < 0 || x+1 >= n || y < 0 || y >= n) return false;//범위 조건
        if (board[x+1][y] == 1 || board[x][y] == 1) return false;//장애물
    }
    return true;
}

//로봇 이동
int Move(vector<vector<int>> board) {
    n = board.size();//지도 크기
    visit[0][0][0] = true;//초기 지점 방문 체크(x,y가 더 작은쪽)
    queue<Robot> q;//로봇 위치
    q.push({ 0,0,0,0 });

    while (!q.empty()) {
        Robot now = q.front();//로봇 위치
        q.pop();
       
        //방문 완료
        if ((now.type==0 && now.x==n-1 && now.y==n-2) || (now.type==1 && now.x==n-2 && now.y==n-1)) {
            return now.time;
        }

        //회전 X
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i]; int ny = now.y + dy[i];

            if (isPossible(nx, ny, now.type ,board) == false) continue;//탐색 가능한가?
            if (visit[nx][ny][now.type] == true) continue;//방문 여부

            visit[nx][ny][now.type] = true;
            q.push({ now.time+1,nx,ny,now.type });
        }
        //회전
        if (now.type == 0) {//현재 가로
            //왼쪽이 축
            //위로 회전
            if (now.x - 1 >= 0 && board[now.x - 1][now.y] == 0 && board[now.x - 1][now.y + 1] == 0) {//범위, 장애물
                if (visit[now.x - 1][now.y][1] == false) {//방문 조건
                    q.push({ now.time + 1,now.x - 1,now.y,1 });
                }
            }
            //아래로 회전
            if (now.x + 1 < n && board[now.x + 1][now.y] == 0 && board[now.x + 1][now.y + 1] == 0) {//범위, 장애물
                if (visit[now.x][now.y][1] == false) {//방문 조건
                    q.push({ now.time + 1,now.x ,now.y,1 });
                }
            }
            //오른쪽이 축
            //위로 회전
            if (now.x - 1 >= 0 && board[now.x - 1][now.y] == 0 && board[now.x - 1][now.y+1] == 0) {//범위, 장애물
                if (visit[now.x - 1][now.y+1][1] == false) {//방문 조건
                    q.push({ now.time + 1,now.x - 1,now.y+1,1 });
                }
            }
            //아래로 회전
            if (now.x + 1 < n && board[now.x + 1][now.y] == 0 && board[now.x + 1][now.y + 1] == 0) {//범위, 장애물
                if (visit[now.x][now.y+1][1] == false) {//방문 조건
                    q.push({ now.time + 1,now.x ,now.y+1,1 });
                }
            }
        }
        else if (now.type == 1) {//현재 세로
            //위쪽이 축
            //왼쪽으로 회전
            if (now.y - 1 >= 0 && board[now.x][now.y-1] == 0 && board[now.x + 1][now.y - 1] == 0) {//범위, 장애물
                if (visit[now.x][now.y-1][0] == false) {//방문 조건
                    q.push({ now.time + 1,now.x,now.y-1,0 });
                }
            }
            //오른쪽으로 회전
            if (now.y + 1 < n && board[now.x][now.y+1] == 0 && board[now.x + 1][now.y + 1] == 0) {//범위, 장애물
                if (visit[now.x][now.y][0] == false) {//방문 조건
                    q.push({ now.time + 1,now.x ,now.y,0 });
                }
            }
            //아래쪽이 축
            //왼쪽으로 회전
            if (now.y - 1 >= 0 && board[now.x + 1][now.y - 1] == 0 && board[now.x][now.y-1] == 0) {//범위, 장애물
                if (visit[now.x + 1][now.y-1][0] == false) {//방문 조건
                    q.push({ now.time + 1,now.x + 1,now.y-1,0 });
                }
            }
            //오른쪽으로 회전
            if (now.y + 1 < n && board[now.x][now.y+1] == 0 && board[now.x + 1][now.y + 1] == 0) {//범위, 장애물
                if (visit[now.x+1][now.y][0] == false) {//방문 조건
                    q.push({ now.time + 1,now.x+1 ,now.y,0 });
                }
            }
        }
    }
    return 0;
}
int solution(vector<vector<int>> board) {
    int answer = Move(board);
    return answer;
}
