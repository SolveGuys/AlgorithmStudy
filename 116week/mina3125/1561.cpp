#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;

long long N;
int M;
int ride[10001];

pair<int, long long> bin_search(int min_t) {
	long long s = 1;

	// 최대 시간 : N * 놀이 기구 중 최소 소요 시간 
	// 무조건 이거 보다 적게 걸림. 
	long long e = N * min_t;
	long long mid;

	long long cnt;
	long long plus;

	// 시간을 기준으로 이분탐색
	while (s <= e) {
		mid = (s + e) / 2;

		cnt = 0;
		plus = 0;
		for (int i = 1; i <= M; i++) {
			// cnt : 현재 탑승하고 있는 인원 수 
			// plus : 다음으로 탑승 가능한 인원 수 -> 나머지 0일 경우,
			cnt += mid % ride[i] ? mid / ride[i] + 1 : mid / ride[i];
			plus += mid % ride[i] ? 0 : 1;
		}

		// 2가지 조건이 가능해야 한다.
		// 1. cnt + plus >= N 이어야 함 
		// 2. cnt < N 이어야 함. 
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