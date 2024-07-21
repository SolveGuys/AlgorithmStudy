#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int N;
vector<int> v(500001);
vector<int> ans(500001);

void input() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	fill(ans.begin(), ans.end(), -1);
}

void find_ans() {
	stack<pair<int, int>> s;

	for (int i = N - 1;i >= 0; i--) {
		while (true) {
			if (s.empty() || s.top().first >= v[i])
				break;
			ans[s.top().second] = i;
			s.pop();
		}
		s.push({ v[i],i });
	}
}

int main() {
	input();
	find_ans();
	for (int i = 0; i < N; i++) {
		cout << ans[i] + 1 << ' ';
	}
}