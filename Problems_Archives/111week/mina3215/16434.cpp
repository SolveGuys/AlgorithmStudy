#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>

using namespace std;

int N;
long long ATK;
long long Max_HP;
vector<long long> DMG(130000);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> ATK;
	DMG[0] = 0;
	for (int i = 1; i <= N; i++) {
		int t, a, h;
		cin >> t >> a >> h;
		// t == 1 : 몬스터
		long long dmg = 0;
		if (t % 2) {
			// 용사가 몬스터를 처치하는데 필요한 공격 수
			long long num = ceil(double(h) / double(ATK));
			// 용사가 맞는 데미지
			dmg = (num - 1) * a;
			// 누적합으로 데미지의 총합을 저장한다.
			DMG[i] = DMG[i - 1] + dmg;
			// 가장 많이 피가 깎이는 만큼을 계속 저장
			Max_HP = max(DMG[i], Max_HP);
		}
		else {
			dmg = DMG[i - 1] - h;
			ATK += a;
			DMG[i] = dmg >= 0 ? dmg : 0;
		}
	}
	// 최소 필요량 1을 더해줌.
	cout << Max_HP + 1;
}