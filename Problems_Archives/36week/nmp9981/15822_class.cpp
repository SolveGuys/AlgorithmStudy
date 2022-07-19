#include <iostream>
#include <cstring>
using namespace std;

//제곱함수
inline int Pow(int x) {
	return x * x;
}

//최솟값 구하기
inline int min(int x, int y) {
	return x > y ? y : x;
}

class Sound {
public:
	Sound();

	void input();//입력
	void DTW();//DTW기법
	void output() const{ cout << dist[n][n]; }//출력
private:
	static const int maxi = 2001;
	int n;
	int wavyX[maxi];//x축 파형
	int wavyY[maxi];//y축 파형
	int dist[maxi][maxi];//두 소리사이의 최소거리
};
//생성자 초기화
Sound::Sound(){
	n = 0;
	memset(dist, 0, sizeof(dist));//초기화
	memset(wavyX, 0, sizeof(wavyX));
	memset(wavyY, 0, sizeof(wavyY));
}

//입력
void Sound::input() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> wavyX[i];
	for (int i = 1; i <= n; i++) cin >> wavyY[i];
}

//DTW기법
void Sound::DTW() {
	//초기값
	dist[1][1] = Pow(wavyX[1] - wavyY[1]);

	//한곳으로 몰빵
	for (int j = 2; j <= n; j++) dist[1][j] = dist[1][j-1]+Pow(wavyX[1] - wavyY[j]);
	for (int i = 2; i <= n; i++) dist[i][1] = dist[i-1][1]+Pow(wavyX[i] - wavyY[1]);

	//두 소리사이의 거리의 최솟값
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			dist[i][j] = min(dist[i-1][j],min(dist[i][j-1],dist[i-1][j-1]))+ Pow(wavyX[i] - wavyY[j]);
		}
	}
}

int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Sound sound;//소리 객체
	sound.input();//입력
	sound.DTW();//두 소리사이의 최솟값 구하기
	sound.output();//출력
	return 0;
}
