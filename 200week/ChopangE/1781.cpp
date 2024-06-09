#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int, int> ii;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<ii> arr(N);

	for ( int i = 0; i < N; i++ ) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	for ( int i = 0; i < N; i++ ) {
		pq.push(arr[i].second);
		if ( pq.size() > arr[i].first ) pq.pop();
	}
	int res = 0;
	while ( !pq.empty() ) {
		res += pq.top();
		pq.pop();
	}
	cout << res << endl;
	return 0;
}