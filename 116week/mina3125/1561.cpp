#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;

long long N;
int M;
int ride[10001];

pair<int, long long> bin_search(int min_t) {
	long long s = 1;
	long long e = N * min_t;
	long long mid;

	long long cnt;
	long long plus;

	while (s <= e) {
		mid = (s + e) / 2;

		cnt = 0;
		plus = 0;
		for (int i = 1; i <= M; i++) {
			cnt += mid % ride[i] ? mid / ride[i] + 1 : mid / ride[i];
			plus += mid % ride[i] ? 0 : 1;
		}

		if (cnt + plus < N)
			s = mid + 1;
		else {
			if (cnt >= N)
				e = mid - 1;
			else {
				break;
			}
		}
	}
	//cout << mid << '\n';
	return { cnt, mid };
}

int main() {
	cin >> N >> M;
	int min_t = 2e9;
	for (int i = 1; i <= M; i++) {
		cin >> ride[i];
		min_t = min(min_t, ride[i]);
	}
	if (N <= M) {
		cout << N;
		return 0;
	}
	long long cnt, mid;

	tie(cnt, mid) = bin_search(min_t);

	for (int i = 1; i <= M; i++) {
		cnt += mid % ride[i] ? 0 : 1;
		if (cnt == N) {
			cout << i;
			return 0;
		}
	}

}