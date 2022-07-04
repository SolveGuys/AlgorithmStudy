#include <iostream>
#define MAX 15

using namespace std;

int col[MAX];
int N;
int res = 0; // 결과값

bool check(int row)
{
    // 대각선에 있을 때, 기울기가 1 또는 -1 이므로 행과 열을 좌표처럼 이용, 차이가 동일할 시 대각선에 있다고 판단
    for(int i = 0; i < row; i++)
    {
        if(col[i] == col[row] || abs(col[row] - col[i]) == row - i)
            return false;
    }
    return true; // 조건 만족 시
}

void nQueen(int row)
{
    if(row == N) // N개의 퀸 배치 완료시
        res++;
    else
    {
        for(int i = 0; i < N; i++)
        {
            col[row] = i; // N까지 돌며 퀸 배치
            if(check(row)) // 조건 만족 시 다음 열 퀸 배치
                nQueen(row+1); // 조건 불만족 시 다른 위치에 퀸 배치
        }
    }
}
int main() {
    cin >> N;
    nQueen(0);
    cout << res;
}
