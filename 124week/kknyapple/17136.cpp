#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <memory.h>
#include <set>
using namespace std;

int a[12][12];
int paper[6] = { 0,5,5,5,5,5 };
int ans=1000;

int isPossible(int y, int x, int k) {
	for (int i = y; i < y + k; i++) {
		for (int j = x; j < x + k; j++) {
			if (a[i][j] != 1) return 0;
		}
	}
	return 1;
}

void update(int y, int x, int k, int num) {
	for (int i = y; i < y + k; i++) {
		for (int j = x; j < x + k;j++) {
			a[i][j] = num;
		}
	}
}

void go(int y, int x, int cnt) {

	while (a[y][x] == 0) {
		if (x < 9) {
			x++;
		}
		else if (y < 9) {
			x = 0;
			y++;
		}
		else {
			ans = min(ans, cnt);
			return;
		}
	}
	
	for (int k = 5; k >= 0; k--) {
		if (paper[k] != 0 && isPossible(y, x, k) == 1) {
			paper[k]--;
			update(y, x, k, 0);

			go(y, x, cnt + 1);

			paper[k]++;
			update(y, x, k, 1);
		}
	}

}

int main() {
	ios_base::sync_with_stdio();
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> a[i][j];
		}
	}

	go(0, 0, 0);

	if (ans == 1000)ans = -1;
	cout << ans << "\n";

	return 0;
}
