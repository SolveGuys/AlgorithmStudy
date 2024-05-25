#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N);
	vector<int> sample(N);
	vector<vector<int>> place(N + 1, vector<int>(N + 1, 0));
	for ( int i = 0; i < N; i++ ) {
		cin >> arr[i];
		sample[i] = i + 1;
	}
	for ( int i = 1; i < N + 1; i++ ) {
		for ( int j = 1; j < N + 1; j++ ) {
			if ( arr[i - 1] == sample[j - 1] )place[i][j] = place[i - 1][j - 1] + 1;
			else {
				place[i][j] = max(place[i - 1][j], place[i][j - 1]);
			}
		}
	}
	cout << N - place[N][N] << endl;

	return 0;
}