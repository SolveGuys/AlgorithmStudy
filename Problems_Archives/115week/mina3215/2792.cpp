#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 2e9;

long long N, M;
int ans = INF;

int divide(int num, vector<int>& colors);

int main() {
	cin >> N >> M;
	vector<int> colors(M);

	for (int i = 0; i < M; i++) {
		cin >> colors[i];
	}
	sort(colors.begin(), colors.end()); // 오름차순 정렬
	int num = colors.back();
	int l = 0, r = num;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (divide(mid, colors)) {
			r = mid - 1;
			ans = min(mid, ans);
		}
		else l = mid + 1;
	}
	cout << ans;
}

int divide(int num, vector<int>& colors) {
	if (!num) return 0;
	int jew = M - 1;
	long long available = 0;
	for (int i = 0; i < M; i++) {
		available += colors[i] % num ? colors[i] / num + 1 : colors[i] / num;
	}
	if (available <= N) return 1;
	else return 0;
}