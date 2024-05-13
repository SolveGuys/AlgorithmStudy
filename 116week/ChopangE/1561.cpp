#include<iostream>
#include<vector>

using namespace std;

long cal(vector<int> &time, long &mid) {
	long sum = 0;
	for ( int i = 1; i < time.size(); i++ ) {
		sum += (mid / time[i]);
		if ( mid % time[i] != 0 )sum += 1;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	long n;
	int m;
	cin >> n >> m;
	
	vector<int> time(m + 1);
	int maxTime = 0;
	for ( int i = 1; i < m + 1; i++ ) {
		cin >> time[i];
		maxTime = max(maxTime, time[i]);
	}
	if ( n <= m ) {
		cout << n << endl;
		return 0;
	}
	long left = 0;
	long right = maxTime * n;
	long res;
	while ( left <= right ) {
		long mid = (left + right) / 2;
		long num = cal(time, mid);
		if ( num >= n ) {
			right = mid - 1;
		}
		else {
			res = mid;
			left = mid + 1;
		}

	}
	int remain = n - cal(time, res);
	int tmp = 0;
	for ( int i = 1; i < m + 1; i++ ) {
		if ( res % time[i] == 0 )tmp++;
		if ( tmp == remain ) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}