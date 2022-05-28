#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll n,atk;
vector<pair<ll, pair<ll, ll>>> dungeon;//던전

//입력
void input() {
	cin >> n>>atk;
	for (int i = 0; i < n; i++) {
		ll t, a, h;
		cin >> t >> a >> h;
		dungeon.push_back({ t,{a,h} });
	}
}

//던전 플레이
void DungeonPlay() {
	ll decreaseHP = 0;//감소한 HP
	ll maxHP = 0;//최대 HP
	for (int i = 0; i < n; i++) {
		ll types = dungeon[i].first;
		ll attack = dungeon[i].second.first;
		ll HP = dungeon[i].second.second;

		//던전 타입
		if (types == 1) {
			decreaseHP += attack * ((HP-1) / atk);//총 감소 HP
			maxHP = max(decreaseHP, maxHP);//최대 HP
		}
		else if (types == 2) {
			decreaseHP = max(decreaseHP - HP, 0ll);
			atk += attack;//공격력 증가
		}
	}
	cout << maxHP + 1;//생존 최소 HP
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	DungeonPlay();//던전 공략
	return 0;
}
