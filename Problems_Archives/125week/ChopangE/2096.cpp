#include<iostream>
#include<vector>

using namespace std;

int dx[3] = { -1,0,1 };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<vector<int>> arr(2, vector<int>(3));
	vector<vector<int>> arr2(2, vector<int>(3));
	int N;
	int prev, cur;
	cin >> N;
	cin >> arr[0][0] >> arr[0][1] >> arr[0][2];
	arr2[0][0] = arr[0][0];
	arr2[0][1] = arr[0][1];
	arr2[0][2] = arr[0][2];

	cur = 0;
	prev = cur;
	for ( int i = 1; i < N; i++ ) {
		cur = i % 2;
		cin >> arr[cur][0] >> arr[cur][1] >> arr[cur][2];
		for ( int j = 0; j < 3; j++ ) {
			int tmp = -1;
			int m_tmp = 1e7;
			for ( int k = 0; k < 3; k++ ) {
				int before = j + dx[k];
				if ( before < 0 || before >= 3 )continue;
				tmp = max(tmp, arr[prev][before] + arr[cur][j]);
				m_tmp = min(m_tmp, arr2[prev][before] + arr[cur][j]);
			}
			arr[cur][j] = tmp;
			arr2[cur][j] = m_tmp;
		}
		prev = cur;
	}
	cout << max(arr[cur][2], max(arr[cur][0], arr[cur][1])) << " ";
	cout << min(arr2[cur][2], min(arr2[cur][0], arr2[cur][1])) << endl;

	return 0;
}