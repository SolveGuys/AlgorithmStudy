#include <iostream>
using namespace std;

#define maxi 1000001//배열 최대 길이
#define ll unsigned int//자료형 정의

ll n;//나무의 수
ll m;//나무의 길이
const ll zero = 0;
ll tree_height[maxi];//나무의 높이

//크기 비교 함수
inline ll max(ll x, ll y) {
	return x > y ? x : y;
}

//입력
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> tree_height[i];
}
//남은 나무의 길이
ll rest_tree(ll x) {
	ll rest = 0ll;
	for (int i = 0; i < n; i++) rest += max(zero, tree_height[i] - x);
	return rest;
}

//나무자르기
void cut_tree() {
	ll min_height = 0ll;
	ll max_height = 1000000000ll;
	
	while (min_height <= max_height) {
		ll height = (min_height + max_height) / 2;//중앙값
		if (rest_tree(height) >= m) {//높이 증가
			min_height = height + 1ll;
		}
		else {
			max_height = height - 1ll;
		}
	}
	cout << max_height;//출력
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	input();//입력
	cut_tree();//나무 자르기
	return 0;
}
