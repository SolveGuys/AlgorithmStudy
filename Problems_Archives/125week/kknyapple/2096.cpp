#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n;
int a[3];
int dp[3];
int dp2[3];
int dp2_prev[3], dp_prev[3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[j];
		}
		if (i == 0) {
			dp_prev[0] = a[0];
			dp_prev[1] = a[1];
			dp_prev[2] = a[2];

			dp2_prev[0] = a[0];
			dp2_prev[1] = a[1];
			dp2_prev[2] = a[2];
		}
		else {
			dp[0] = max(dp_prev[0], dp_prev[1]) + a[0];
			dp[1] = max({ dp_prev[0], dp_prev[1], dp_prev[2] }) + a[1];
			dp[2] = max(dp_prev[1], dp_prev[2]) + a[2];

			dp_prev[0] = dp[0];
			dp_prev[1] = dp[1];
			dp_prev[2] = dp[2];

			dp2[0] = min(dp2_prev[0], dp2_prev[1]) + a[0];
			dp2[1] = min({ dp2_prev[0], dp2_prev[1], dp2_prev[2] }) + a[1];
			dp2[2] = min(dp2_prev[1], dp2_prev[2]) + a[2];

			dp2_prev[0] = dp2[0];
			dp2_prev[1] = dp2[1];
			dp2_prev[2] = dp2[2];
		}
		
	}

	int max_res = max({ dp_prev[0], dp_prev[1], dp_prev[2] });
	int min_res = min({ dp2_prev[0], dp2_prev[1], dp2_prev[2] });

	cout << max_res << ' ' << min_res << "\n";

	return 0;
}
