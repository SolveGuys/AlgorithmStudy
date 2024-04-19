#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> ii;

void back(vector<ii> arr, int &N, int &ans, int index) {
	if ( index == N ) {
		int cnt = 0;
		for ( int i = 0; i < N; i++ ) {
			if ( arr[i].first <= 0 )cnt++;
		}
		ans = max(ans, cnt);
		return;
	}
	ii &cur = arr[index];
	if ( cur.first <= 0 )back(arr, N, ans, index + 1);
	else {
		bool check = false;
		for ( int i = 0; i < N; i++ ) {
			if ( i == index )continue;
			ii &sel = arr[i];
			if ( sel.first <= 0 )continue;
			check = true;
			cur.first -= sel.second;
			sel.first -= cur.second;
			back(arr, N, ans, index + 1);
			cur.first += sel.second;
			sel.first += cur.second;
		}
		if ( check )return;
		int cnt = 0;
		for ( int i = 0; i < N; i++ ) {
			if ( arr[i].first <= 0 )cnt++;
		}
		ans = max(ans, cnt);
		return;
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<ii> arr(N);
	int ans = 0;
	for ( int i = 0; i < N; i++ ) {
		int s, w;
		cin >> s >> w;
		arr[i].first = s;
		arr[i].second = w;
	}

	back(arr, N, ans, 0);

	cout << ans << endl;

	return 0;
}