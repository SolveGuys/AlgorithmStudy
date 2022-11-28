#include <iostream>
using namespace std;

int n;
const int maxi = 501;
int tri[maxi][maxi];//삼각형 배열
int sum[maxi][maxi];//배열의 합

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) cin >> tri[i][j];
    }
}
//정수 삼각형
void TriAngle() {
    sum[0][0] = tri[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) sum[i][j] = tri[i][j]+sum[i - 1][j];
            else if (j == i) sum[i][j] = tri[i][j]+sum[i - 1][j - 1];
            else sum[i][j] = tri[i][j]+max(sum[i - 1][j], sum[i - 1][j - 1]);
        }
    }
    //최대값 구하기
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ans < sum[n - 1][i]) ans = sum[n - 1][i];
    }
    cout << ans;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    input();//입력
    TriAngle();//정수 삼각형
	return 0;
}
