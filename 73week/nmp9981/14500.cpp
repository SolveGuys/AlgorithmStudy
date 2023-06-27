#include <iostream>
using namespace std;

int n,m;
const int maxi = 501;
int board[maxi][maxi];//보드
bool visit[maxi][maxi];//방문 여부
int maxSum = 0;
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> board[i][j];
    }
}
//테트로미노
void Tetromino(int x,int y,int cnt,int sum) {
    if (cnt == 4) {//4개 모임
        maxSum = max(maxSum, sum);
        return;
    }
    //다음 지점
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
        if (visit[nx][ny]) continue;//방문 조건

        visit[nx][ny] = true;
        Tetromino(nx, ny, cnt+1, sum + board[nx][ny]);//다음 블록
        visit[nx][ny] = false;
    }
}
//ㅏ 모양
int Ah(int x, int y,int sum) {//중심 좌표
    int cnt = 0;
    int ahSum = sum;
    int minBoard = 5000;
    //4방 탐색(날개)
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
        cnt++;
        ahSum += board[nx][ny];
        minBoard = min(board[nx][ny], minBoard);
    }
    //결과
    if (cnt <= 2) return 0;//만들기 불가
    else if (cnt == 3) return ahSum;//ㅏ모양
    return ahSum - minBoard;//가장 작은 것 하나뺀다.
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    //테트로미노
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = true;
            Tetromino(i, j, 1, board[i][j]);//테트로미노 시작 지점
            visit[i][j] = false;
        }
    }
    //Ah모양
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) maxSum = max(maxSum,Ah(i, j,board[i][j]));//중심 좌표
    }
    cout << maxSum;//출력
    return 0;
}
