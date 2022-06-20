#include <iostream>
using namespace std;

#define maxi 1000001//배열 최대 길이
typedef long long ll;

ll n;//나무의 수
ll m;//나무의 길이
const ll zero = 0;
ll tree_height[maxi];//나무의 높이

//크기 비교 함수
inline ll num_max(ll x, ll y) {
	return x > y ? x : y;
}

//입력
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> tree_height[i];
}
//남은 나무의 길이
ll rest_tree(ll x) {
	ll rest = 0;
	for (int i = 0; i < n; i++) rest += num_max(zero, tree_height[i] - x);
	return rest;
}

//나무자르기
void cut_tree() {
	ll min_height = 0;
	ll max_height = 1000000000;
	
	while (min_height <= max_height) {
		ll height = (min_height + max_height) / 2;//중앙값
		if (rest_tree(height) >= m) {//높이 증가
			min_height = height + 1;
		}
		else {
			max_height = height - 1;
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
