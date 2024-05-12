#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> T(N + 1);
	vector<int> P(N + 1);
	vector<int> res(N + 2, 0);
	for ( int i = 1; i < N + 1; i++ ) {
		cin >> T[i] >> P[i];
	}
	for ( int i = 1; i < N + 1; i++ ) {
		res[i] = max(res[i - 1], res[i]);
		if ( i + T[i] >= N + 2 )continue;
		res[i + T[i]] = max(res[i+T[i]],res[i] + P[i]);
	}
	res[N + 1] = max(res[N], res[N + 1]);
	cout << res[N + 1] << endl;

	return 0;
}