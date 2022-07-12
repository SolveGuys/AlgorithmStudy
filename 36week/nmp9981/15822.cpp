#include <iostream>
using namespace std;

int n;
const int maxi = 2001;
int wavyX[maxi];//x파형
int wavyY[maxi];//y파형
int dist[maxi][maxi];//두 소리사이의 거리 최솟값

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> wavyX[i];
	for (int i = 0; i < n; i++) cin >> wavyY[i];
}

//제곱
inline int Pow2(int x) {
	return x * x;
}
//최솟값
inline int min(int a, int b) {
	return a > b ? b : a;
}
//소리 거리 구하기
void DTW() {
	//초기값
	dist[0][0] = Pow2(wavyX[0] - wavyY[0]);

	//소리의 거리 구하기
	for (int i = 1; i < n; i++) dist[i][0] = dist[i-1][0]+Pow2(wavyX[i] - wavyY[0]);
	for (int j = 1; j < n; j++) dist[0][j] = dist[0][j-1]+Pow2(wavyX[0] - wavyY[j]);
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			dist[i][j] = min(dist[i - 1][j], min(dist[i][j - 1], dist[i - 1][j - 1])) + Pow2(wavyX[i] - wavyY[j]);
		}
	}
	cout << dist[n - 1][n - 1];//출력
}
int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	if(n==1) cout<< Pow2(wavyX[0] - wavyY[0]);
	else DTW();//소리 거리 구하기
	return 0;
}
