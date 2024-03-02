#include<iostream>
#include<algorithm>

using namespace std;

int RGB[1001][3]; // RGB 입력
int DP[1001][3]; // DP

int N;

int main() {
	cin >> N;
	//입력 부분
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> RGB[i][j];
		}
	}
	fill(&DP[0][0], &DP[0][0] + 1000 * 3, 0);
	
	// RGB 배열만큼 생성된 배열에 지금의 칸까지 도착하기 위한 최소비용을 계속 갱신
	
	// 49 50 10 : 0
	// 23 45 67 : 1
	
	// 49 50 10  " dp 0 
	// (49+min(45,67)) (50+min(23,67)) (10+min(23,45))
	// -> 각 줄에서 나올 수 있는 최소비용이 3개. => 이것 중에서 가장 작은 하나
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			DP[i][j] = min(DP[i - 1][(j + 1) % 3], DP[i - 1][(j + 2) % 3]);
			DP[i][j] += RGB[i][j];
		}
	}

	int ans = min(DP[N][0], DP[N][1]);
	ans = min(ans, DP[N][2]);

	cout << ans;
}