#include <iostream>
#define Row 2
using namespace std;

const int maxi = 1000001;
int t, n, cnt;
int score[Row][maxi],maxScore[Row+1][maxi];//점수, 누적 점수

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    //초기화
    for (int i = 0; i < Row + 1; i++) {
        for (int j = 0; j < n; j++) maxScore[i][j] = 0;
    }
    //입력
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < n; j++) cin >> score[i][j];
    }
    maxScore[0][0] = score[0][0];maxScore[1][0] = score[1][0];//초기화
}
//스티커 떼기
void sticker() {
    for (int i = 1; i < n; i++) {
        maxScore[0][i] = score[0][i] + max(maxScore[1][i-1], maxScore[2][i-1]);//위 선택
        maxScore[1][i] = score[1][i] + max(maxScore[0][i-1], maxScore[2][i-1]);//아래 선택
        maxScore[2][i] = max(max(maxScore[0][i - 1], maxScore[1][i - 1]), maxScore[2][i - 1]);//선택X
    }
    cout << max(max(maxScore[0][n - 1], maxScore[1][n - 1]), maxScore[2][n - 1])<<"\n";
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    cin >> t;
    while (t--) {
        input();//입력
        sticker();//스티커
    }
	return 0;
}
