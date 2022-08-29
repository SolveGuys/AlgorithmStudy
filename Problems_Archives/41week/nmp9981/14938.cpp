#include <iostream>
using namespace std;

int n, m, r;
const int maxi = 101;
const int inf = 200000000;
int item[maxi];//각 노드별 아이템
bool isGet[maxi];//아이템을 먹었는가?
int dist[maxi][maxi];//i,j까지의 거리

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//min
inline int min(int x, int y) {
	return x > y ? y : x;
}
//초기화
void init() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = inf;
		}
	}
}
//입력
void input() {
	for (int i = 1; i <= n; i++) cin >> item[i];
	for (int i = 0; i < r; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		dist[a][b] = d;//양방향
		dist[b][a] = d;
	}
}
//플로이드 알고리즘
void floyd() {
	//i,j까지의 최단거리
	for (int k = 1; k <= n; k++) {//경유 지점
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}
//아이템 얻기
void getItem() {
	int itemCount = 0;
	for (int i = 1; i <= n; i++) {//기준 노드
		int getCount = 0;//각 기준노드별 얻는 개수
		for (int j = 1; j <= n; j++) {//탐색 노드
			if (dist[i][j] <= m) getCount += item[j];//탐색범위 내
		}
		itemCount = max(itemCount, getCount);
	}
	cout << itemCount;//출력
}
int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init();//초기화
	input();//입력
	floyd();//플로이드
	getItem();//아이템 얻기
	return 0;
}
