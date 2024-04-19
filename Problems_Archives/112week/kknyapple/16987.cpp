#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <stack>
#include <queue>
#include <string>
#include<math.h>
using namespace std;

int n;
int a[2][8]; // a[0][n] : 내구도, a[1][n] : 무게
int res;

void go(int idx) {
	if (idx == n) { // 모든 계란을 사용
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			// cout << a[0][i] << "\n";
			if (a[0][i] <= 0) cnt++; // 깨진 계란
		}

		if (cnt > res) res = cnt; // 계란 최댓값 저장

		return;
	}



	if (a[0][idx] <= 0) go(idx + 1); // 깨진 계란일 경우 다음 계란 사용
	else {
		int flag = 0;

		for (int i = 0; i < n; i++) {
			if (a[0][i] <= 0) continue; // 깨진 계란일 경우 건너 뜀
			if (idx == i) continue; // 사용하는 계란일 경우 건너 뜀

			flag = 1;

			a[0][i] -= a[1][idx]; // 상대 계란 내구도 감소
			a[0][idx] -= a[1][i]; // 사용하는 계란 내구도 감소
			go(idx + 1);
			// 다음 재귀를 위해 계란 내구도 복구
			a[0][i] += a[1][idx];
			a[0][idx] += a[1][i];
		}

		if (flag == 0) { // 만약 사용하는 계란 제외 모든 계란이 깨져있다면
			go(n);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[0][i] >> a[1][i];
	}

	go(0);



	cout << res << "\n";

	return 0;
}
