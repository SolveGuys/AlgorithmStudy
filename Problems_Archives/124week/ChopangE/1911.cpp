#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> ii;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, L;
	cin >> N >> L;
	vector<ii> arr(N);

	for ( int i = 0; i < N; i++ ) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end());
	int sum = 0;
	int remain = 0;
	for ( int i = 0; i < N; i++ ) {
		if ( remain > arr[i].first ) arr[i].first = remain;
		int diff = arr[i].second - arr[i].first;
		if ( diff < 0 )continue;
		if ( diff % L != 0 ) {
			sum += diff / L + 1;
			remain = (L - (diff % L)) + arr[i].second;
		}
		else {
			sum += diff / L;
			remain = arr[i].second;
		}
	}
	cout << sum << endl;

	return 0;
}