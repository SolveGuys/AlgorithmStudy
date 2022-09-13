#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;//입력
vector<int> dist;//거리
vector<int> plusPosition;//양의 위치
vector<int> minusPosition;//음의 위치
int maxDist = 0;//최대 거리

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//abs
inline int abs(int x) {
	return x < 0 ? -x : x;
}
//입력
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		maxDist = max(abs(x), maxDist);//거리의 최댓값
		
		if (x >= 0) plusPosition.push_back(x);//양수
		else minusPosition.push_back(-x);//음수
	}
	//정렬
	if(plusPosition.size()>0) sort(plusPosition.begin(), plusPosition.end());
	if(minusPosition.size()>0) sort(minusPosition.begin(), minusPosition.end());
}
//도서관
int library() {
	int totalDist = 0;//총 거리
	//양의 위치
	for (int i = plusPosition.size()-1; i >= 0; i -= m) totalDist += (2 * plusPosition[i]);//왕복
	//음의 위치
	for (int i = minusPosition.size() - 1; i >= 0; i -= m) totalDist += (2 * minusPosition[i]);//왕복
	//가장 먼 거리는 1회만
	totalDist -= maxDist;
	return totalDist;
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	cout<<library();//도서관
    return 0;
}
