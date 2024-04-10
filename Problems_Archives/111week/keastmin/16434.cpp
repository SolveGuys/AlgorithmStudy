#include <iostream>
#include <math.h>
using namespace std;

int N;

// 현재 공격력, 현재 체력, 최대 체력(최소 체력은 1을 가지고 있어야함)
long long hAtk, hCur = 0, hMax = 0;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> hAtk;

	for (int i = 0; i < N; i++) {
		int t, a, h;
		cin >> t >> a >> h;

		// 몬스터 방
		if (t == 1) {
			// ceil 함수: 소수점 무조건 올림
			long long dmg = (ceil((double)h / hAtk) - 1) * a;

			//cout << "dmg = " << dmg << '\n';

			// 몬스터한테 받는 데미지가 hCur 이하일 경우 hCur에서 dmg 만큼 차감
			if (hCur >= dmg) hCur -= dmg;
			// 몬스터한테 받는 데미지가 hCur을 초과할 경우 최대 체력을 증가시켜야 함
			else {
				hMax += (dmg - hCur);
				hCur = 0;
			}
		}
		// 포션 방
		else{
			// 공격력 증가
			hAtk += a;
			// 현재 체력은 최대 체력을 넘길 수 없으므로 현재 체력이 
			// 최대 체력보다 크다면 최대 체력을 현재 체력으로 적용
			hCur = min(hCur + h, hMax);
		}

		//cout << "hCur = " << hCur << ", hMax = " << hMax << '\n';
	}

	cout << hMax + 1;

	return 0;
}
