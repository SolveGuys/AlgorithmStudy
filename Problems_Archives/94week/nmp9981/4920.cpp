#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, maxSum;
const int maxi = 101;
const int inf = 4000001;
int board[maxi][maxi];//보드 판
//13개의 경우의 수
pair<int,int> blockDir[13][4] = {
    //1번 블록
    {{0,0},{1,0},{2,0},{3,0}},
    {{0,0},{0,1},{0,2},{0,3}},
    //2번 블록
    {{0,0},{0,1},{1,1},{1,2}},
    {{0,0},{1,0},{1,-1},{2,-1}},
    //3번 블록
    {{0,0},{0,1},{0,2},{1,2}},
    {{0,0},{0,1},{0,2},{-1,0}},
    {{0,0},{1,0},{2,0},{2,-1}},
    {{0,0},{1,0},{2,0},{0,1}},
    //4번 블록
    {{0,0},{0,1},{0,2},{-1,1}},
    {{0,0},{0,1},{0,2},{1,1}},
    {{0,0},{1,0},{2,0},{1,-1}},
    {{0,0},{1,0},{2,0},{1,1}},
    //5번 블록
    {{0,0},{0,1},{1,0},{1,1}}
};

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//초기화
void Init() {
    maxSum = -inf;
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < maxi; j++) board[i][j] = 0;
    }
}
//입력
void input() {
    cin >> n;
    if (n == 0) exit(0);//종료
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)cin >> board[i][j];
    }
}
//블록 배치
int BlockBatch(int x, int y) {//중심 좌표
    int sumResult = -inf;
    for (int k = 0; k < 13; k++) {//총 13개의 경우의 수
        int cnt = 0;
        int block4 = 0;
        for (int dir = 0; dir < 4; dir++) {//블록 배치
            int nx = x + blockDir[k][dir].first;
            int ny = y + blockDir[k][dir].second;
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;//범위 조건
            cnt++;
            block4 += board[nx][ny];
        }
        if (cnt == 4) sumResult = max(sumResult, block4);//모두 채울 수 있음
    }
    return sumResult;
}
//테트리스
void Tetris(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) maxSum = max(maxSum, BlockBatch(i, j));
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 0;
    while (true) {
        t++;//테스트 번호 증가
        Init();//초기화
        input();//입력
        Tetris();//테트리스
        cout << t << ". " << maxSum << "\n";//출력
    }
    return 0;
}
