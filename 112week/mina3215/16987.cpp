#include<iostream>
#include<algorithm>

using namespace std;

int N;
int S[9];
int W[9];
int ans = 0;

int crash_Eggs(int idx, int prev[9]);
void count_Egg(int eggs[9]);

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> W[i];
	}

	crash_Eggs(0, S);

	cout << ans;
}
void count_Egg(int eggs[9]) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (eggs[i] <= 0) cnt++;
	}
	ans = max(ans, cnt);
}


int crash_Eggs(int idx, int prev[9]) {
	if (idx == N) {
		count_Egg(prev);
		return 0;
	}
	if (prev[idx] <= 0) {
		crash_Eggs(idx + 1, prev);
		return 0;
	}
	int _eggs[9];
	copy(prev, prev + N, _eggs);

	for (int i = 0; i < N; i++) {
		if (idx == i || _eggs[i] <= 0) continue;
		_eggs[i] -= W[idx];
		_eggs[idx] -= W[i];
		crash_Eggs(idx + 1, _eggs);
		_eggs[i] += W[idx];
		_eggs[idx] += W[i];
	}

	count_Egg(_eggs);

	return 0;
}