#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int cards[1000002];
int scores[1000002];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int n;

	fill(scores,scores + 1000002, 0);
	for (int i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
		cards[n] = 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = v[i]*2; j < 1000002; j+=v[i]) {
			if (cards[j]){
				scores[j]--;
				scores[v[i]]++;
			}
		}
	}
	for (auto i : v) {
		cout << scores[i] << ' ';
	}

	
}