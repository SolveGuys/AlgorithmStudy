#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;

vector<pair<int, long long>> hw;
int N;

void input() {
	int D;
	long long C;
	for (int i = 0; i < N; i++) {
		cin >> D >> C;
		hw.push_ba#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>

			using namespace std;

		vector<pair<int, long long>> hw;
		int N;

		void input() {
			int D;
			long long C;
			for (int i = 0; i < N; i++) {
				cin >> D >> C;
				hw.push_back({ D,C });
			}
		}

		// 우선 순위 큐 사용
		// queue size == 날짜 
		void find_ans() {
			priority_queue<pair<long long, int>> pq;
			long long ans = 0;

			for (int i = 0; i < N; i++) {
				int D, C;
				tie(D, C) = hw[i];
				if (pq.size() < D) {
					pq.push({ -C,D });
					ans += C;
				}
				else {
					if (-(pq.top().first) < C) {
						ans += (C + pq.top().first);
						pq.pop();
						pq.push({ -C,-D });
					}
				}
			}

			cout << ans;

		}

		int main() {

			ios::sync_with_stdio(false);
			cin.tie(NULL);
			cout.tie(NULL);

			cin >> N;
			input();

			// 1. 데드라인 적은 순 정렬
			sort(hw.begin(), hw.end());
			find_ans();
		}ck({ D,C });
	}
}

// 우선 순위 큐 사용
// queue size == 날짜 
void find_ans() {
	priority_queue<pair<long long, int>> pq;
	long long ans = 0;

	for (int i = 0; i < N; i++) {
		int D, C;
		tie(D, C) = hw[i];
		if (pq.size() < D) {
			pq.push({ -C,D });
			ans += C;
		}
		else {
			if (-(pq.top().first) < C) {
				ans += (C + pq.top().first);
				pq.pop();
				pq.push({ -C,- D });
			}
		}
	}

	cout << ans;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	input();

	// 1. 데드라인 적은 순 정렬
	sort(hw.begin(), hw.end());
	find_ans();
}