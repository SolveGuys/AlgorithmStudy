#include <iostream>
using namespace std;

int n;
const int maxi = 1001;
const int colorN = 3;//색상개수
int rgb[maxi][colorN];//i번집에서 각 색을 칠하는 비용
int cost[maxi][colorN];//i번집까지 j색으로 칠했을때의 비용

//min
inline int min(int x, int y) {
	return x > y ? y : x;
}
//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < colorN; j++) cin >> rgb[i][j];
	}
	for (int j = 0; j < colorN; j++) cost[0][j] = rgb[0][j];//1번집 비용
}
//비용 구하기
void house() {
	for (int i = 1; i < n; i++) {
		cost[i][0] = rgb[i][0] + min(cost[i - 1][1], cost[i - 1][2]);//R
		cost[i][1] = rgb[i][1] + min(cost[i - 1][0], cost[i - 1][2]);//G
		cost[i][2] = rgb[i][2] + min(cost[i - 1][0], cost[i - 1][1]);//B
	}
	cout << min(cost[n - 1][0], min(cost[n - 1][1], cost[n - 1][2]));//출력
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	input();//입력
	house();//비용 구하기
	return 0;
}
