#include <iostream>
using namespace std;

int n;
const int maxi = 17;
int pipe[maxi][maxi];//파이프 상태
int caseNum[maxi][maxi][3];//경우의 수, 0:가로, 1:세로, 2:대각선

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> pipe[i][j];
    }
}
//파이프 옮기기
void MovePipe() {
    //맨 첫줄 -> 가로만
    for (int j = 1; j < n; j++) {
        if (pipe[0][j] == 1)break;
        caseNum[0][j][0] = 1;
    }
    //2번째줄부터
    for (int i = 1; i < n; i++) {
        for (int j = 2; j < n; j++) {
            if (pipe[i][j] == 1) continue;//벽

            if(pipe[i][j-1]==0) caseNum[i][j][0] = caseNum[i][j - 1][0] + caseNum[i][j - 1][2];//가로
            if(pipe[i-1][j]==0) caseNum[i][j][1] = caseNum[i - 1][j][1] + caseNum[i - 1][j][2];//세로
            if(pipe[i-1][j-1]==0 && pipe[i][j - 1] == 0 && pipe[i - 1][j] == 0) caseNum[i][j][2] = caseNum[i - 1][j - 1][0] + caseNum[i - 1][j - 1][1] + caseNum[i - 1][j - 1][2];//대각선
        }
    }
    cout << caseNum[n - 1][n - 1][0] + caseNum[n - 1][n - 1][1] + caseNum[n - 1][n - 1][2];//출력
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    MovePipe();//파이프 옮기기
    return 0;
}
