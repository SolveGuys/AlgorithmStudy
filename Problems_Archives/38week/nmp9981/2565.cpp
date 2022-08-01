#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int maxi = 501;
vector<pair<int, int>> wire;//전깃줄 정보
int lineLength[maxi];//유지되는 전깃줄의 길이

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		wire.push_back({ a,b });
	}
	sort(wire.begin(), wire.end());//첫번째 열 기준으로 정렬
}

//LIS
void LIS() {
	//초기화
	for (int i = 0; i < n; i++) lineLength[i] = 1;//처음 길이는 1

	//LIS
	for (int i = 1; i < n; i++) {//기준점
		for (int j = 0; j < i; j++) {
			//오름차순이면
			if (wire[j].second < wire[i].second) lineLength[i] = max(lineLength[i], lineLength[j] + 1);
		}
	}
}
//자르는 전선의 개수
void cutLine() {
	int cutMaxi = 0;
	for (int i = 0; i < n; i++) {
		cutMaxi = max(cutMaxi, lineLength[i]);//유지되는 전선의 개수
	}
	cout << n - cutMaxi;//전체-LIS
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	LIS();//최대 증가 수열
	cutLine();//자르는 전선의 개수
    return 0;
}
