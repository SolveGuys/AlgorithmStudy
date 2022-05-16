#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
double new_slope, slope;
const int maxi = 51;
const double inf = 2000000001;
double building[maxi];//빌당의 높이

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> building[i];
}

//기울기
double Slope(double x1, double y1, double x2, double y2) {
	return (y2 - y1) / (x2 - x1);
}

//보이는 빌딩의 개수
void building_number() {
	//기준 빌딩
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		//왼쪽
		slope = inf;
		for (int j = i - 1; j >= 0; j--) {
			new_slope = Slope(i, building[i], j, building[j]);
			if (slope > new_slope) {//기울기가 감소해야함
				cnt++;
				slope = new_slope;
			}
		}
		//오른쪽
		slope = -inf;
		for (int j = i + 1; j < n; j++) {
			new_slope = Slope(i, building[i], j, building[j]);
			if (slope < new_slope) {//기울기가 증가해야함
				cnt++;
				slope = new_slope;
			}
		}
		ans = max(ans, cnt);//최대 갯수 갱신
	}
	cout << ans;//출력
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	building_number();//보이는 빌딩의 개수
	return 0;
}
