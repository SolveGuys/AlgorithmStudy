#include<iostream>
#include<algorithm>

using namespace std;

#define INF 1e9;

int N;
long double height[52];
long long view[52];
long long ans = 0;

int find_view(int n) {
	long double now = -INF;
	for (int i = n+1; i < N; i++) {
		long double h = (height[i] - height[n]) / (i - n);
		// long double h = (static_cast<long double>(height[i]) - height[n]) / (i - n);
		if (now < h) {
			view[i]++;
			view[n]++;
			now = h;
		}
	}
	ans = max(ans, view[n]);

	return 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> height[i];
	}

	fill(view, view + N, 0);

	for (int i = 0; i < N; i++) {
		find_view(i);
	}

	cout << ans;
}