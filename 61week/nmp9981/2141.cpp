#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
ll allPeople = 0;
vector<pair<ll,ll>> villege;//마을

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x, a;
		cin >> x >> a;
		villege.push_back({ x,a });//위치, 인원수
		allPeople += a;
	}
	sort(villege.begin(), villege.end());//거리 기준 정렬
}
//우체국 설치
void PostOffice() {
	ll people = 0;
	for (int i = 0; i < n; i++){
		people += villege[i].second;
		if (people >= (allPeople+1) / 2) {//전체 인원수의 절반
			cout << villege[i].first;
			return;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	PostOffice();//우체국 설치
	return 0;
}
