#include <iostream>
using namespace std;

int h,w;
int highest = 0;//기장 높은 기둥의 위치
const int maxi = 501;
int rain[maxi];//빗물

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}

//입력
void input() {
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		cin >> rain[i];
		if (rain[highest] < rain[i]) highest = i;
	}
}
//물의 양 구하기
void AmountWater() {
	int total = 0;//총량
	int left = 0;//왼쪽 기준 기둥
	int right = w - 1;//오른쪽 기준 기둥

	//왼쪽
	for (int i = 0; i < highest; i++) {
		if (rain[left] <= rain[i]) left = i;//기준 기둥 옮기기
		else total += (rain[left] - rain[i]);
	}
	//오른쪽
	for (int i = w-1; i > highest; i--) {
		if (rain[right] <= rain[i]) right = i;//기준 기둥 옮기기
		else total += (rain[right] - rain[i]);
	}
	cout << total;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	AmountWater();//물의 양 구하기
	return 0;
}
