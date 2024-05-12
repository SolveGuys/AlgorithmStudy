#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <memory.h>
#include<tuple>
using namespace std;

long long n, m; // n명 아이들, m개 놀이기구
long long amus_time[10004], res;

bool check(long long mid) {
	long long cnt = m;

	for (int i = 0; i < m; i++) {
		cnt += mid / amus_time[i];
	}

	if (cnt < n) {
		return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> amus_time[i];
	}

	if (n <= m) {
		cout << n << "\n";

		return 0;
	}

	long long l = 1, r = 60000000000;

	while (1) {
		if (l > r) break;

		long long mid = (l + r) / 2;

		if (check(mid)) {
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	long long temp = m;
	for (int i = 0; i < m; i++) {
		temp += (res - 1) / amus_time[i];
	}

	for (int i = 0; i < m; i++) {
		if (res % amus_time[i] == 0) {
			temp++;
		}
		if (temp == n) {
			cout << i + 1 << "\n";
			break;
		}
	}

	return 0;
}
