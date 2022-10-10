#include <iostream>
using namespace std;

int n,m;
const int maxi = 501;
const int inf = (1e+9)+1;
int world[maxi][maxi];//지도
int dpTime[maxi][maxi];//i->j 최단거리

//min
int inline min(int x, int y) {
	return x > y ? y : x;
}
//입력
void input() {
	cin >> n>>m;
	//초기값
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dpTime[i][j] = 0;
			else dpTime[i][j] = inf;
		}
	}
	//지도 입력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> world[i][j];
			dpTime[i][j] = world[i][j];
		}
	}
}
//최단거리 구하기
void Floyd() {
	//dp
	for (int k = 1; k <= n; k++) {//경유지점
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dpTime[i][j] = min(dpTime[i][j], dpTime[i][k] + dpTime[k][j]);
			}
		}
	}
}
//질문
void Question() {
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (dpTime[a][b] <= c) cout << "Enjoy other party\n";//시간내 도착
		else cout << "Stay here\n";//도착 불가
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	Floyd();//최단거리 구하기
	Question();//질문
	return 0;
}
