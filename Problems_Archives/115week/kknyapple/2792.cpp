#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <memory.h>
#include<tuple>
using namespace std;

int n, m, ans;
int a[300004];

int main() {
	ios_base::sync_with_stdio();
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}

	sort(a, a + m);

	int l = 1, r = a[m - 1];

	while (l <= r) {
		int mid = (l + r) / 2;
		int cnt = 0;

		for (int i = 0; i < m; i++) {
			cnt += a[i] / mid;
			if (a[i] % mid != 0)cnt++;
		}

		if (cnt <= n) {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans << "\n";

	return 0;
}
