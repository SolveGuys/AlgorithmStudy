#include<iostream>
#include<vector>
#include<cctype>
#include<cmath>
#define MAX 10000000

using namespace std;

int diff(const int &a, const int &b, const int &T) {
	if ( abs(a - b) > T )return MAX;
	if ( a >= b )return 1;
	else {
		return pow((b - a), 2);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int N, M, T, D;
	cin >> N >> M >> T >> D;
	int t = N * M;
	vector<int> place(t);
	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < M; j++ ) {
			char c;
			int t;
			cin >> c;
			if ( isupper(c) ) {
				t = c - 'A';
			}
			else {
				t = c - 71;
			}
			place[i * M + j] = t;
		}
	}
	vector<vector<int>> fw(t, vector<int>(t, MAX));
	for ( int i = 0; i < t; i++ ) {
		if ( i % M != 0 ) {
			fw[i][i - 1] = diff(place[i], place[i - 1], T);
		}
		if ( i % M != M - 1 ) {
			fw[i][i+1] = diff(place[i], place[i + 1], T);
		}
		if ( i - M >= 0 ) fw[i][i - M] = diff(place[i], place[i - M], T);
		if ( i + M < t ) fw[i][i + M] = diff(place[i], place[i + M], T);
	}
	for ( int k = 0; k < t; k++ ) {
		for ( int i = 0; i < t; i++ ) {
			if ( i == k )continue;
			for ( int j = 0; j < t; j++ ) {
				if ( i == j || j == k )continue;
				if ( fw[i][k] + fw[k][j] >= MAX )continue;
				fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
			}
		}
	}

	int res = place[0];
	for ( int i = 1; i < t; i++ ) {
		int tmp = fw[0][i];
		int tmp2 = fw[i][0];
		if ( tmp >= MAX || tmp2 >= MAX )continue;
		int sum = tmp + tmp2;
		if ( sum > D )continue;
		res = max(res, place[i]);
	}
	cout << res << endl;
	return 0;
}