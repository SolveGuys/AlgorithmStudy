#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

#define INF 2e9
using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int k = 0;
	while (pow(2, k) < N) {
		k++;
	}
	vector<long long> min_tree(pow(2, k) * 2);
	vector<long long> max_tree(pow(2, k) * 2);

	fill(min_tree.begin(), min_tree.end(), INF);
	fill(max_tree.begin(), max_tree.end(), 0);
	int idx = pow(2, k);
	for (int i = 0; i < N;i++) {
		cin >> min_tree[i + idx];
		max_tree[i + idx] = min_tree[i + idx];
	}

	for (int i = k-1;i >= 0;i--) {
		for (int j = pow(2, i);j < pow(2, i + 1);j++) {
			max_tree[j] = max(max_tree[j * 2], max_tree[j * 2 + 1]);
			min_tree[j] = min(min_tree[j * 2], min_tree[j * 2 + 1]);
		}
	}
	

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		long long min_V = INF;
		long long max_V = 0;
		a += idx-1;
		b += idx-1;
		while (a <= b) {
			if (a % 2 == 1) {
				min_V = min(min_V, min_tree[a]);
				max_V = max(max_V, max_tree[a]);
			}
			if (b % 2 == 0) {
				min_V = min(min_V, min_tree[b]);
				max_V = max(max_V, max_tree[b]);
			}
			a = (a + 1) / 2;
			b = (b - 1) / 2;
		}
		
		cout << min_V << ' ' << max_V << '\n';
	}
}