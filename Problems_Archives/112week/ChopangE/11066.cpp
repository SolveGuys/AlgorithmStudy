#include<iostream>
#include<vector>
#include<limits>

using namespace std;


int returnSum(vector<vector<int>> &sum, int start, int end) {
	int sum_ = 0;
	for ( int i = start; i <= end; i++ ) {
		sum_ = sum_ + sum[i][i];
	}
	return sum_;
}

void MakeSum(vector<vector<int>> &sum, int K) {

	for ( int l = 1; l < K; l++ ) {
		for ( int start = 0; start + l < K; start++ ) {
			sum[start][start + l] = returnSum(sum, start, start + l);
		}
	}
}

int main() {
	int T, K;
	cin >> T;
	vector<int> minResult(T);
	for ( int i = 0; i < T; i++ ) {
		cin >> K;
		vector<vector<int>> array(K, vector<int>(K, 0));
		vector<vector<int>> sum(K, vector<int>(K, 0));
		for ( int j = 0; j < K; j++ ) {
			cin >> sum[j][j];
		}
		MakeSum(sum, K);
		for ( int l = 1; l < K; l++ ) {
			for ( int start = 0; start + l < K; start++ ) {
				int end = start + l;
				int totalmin = numeric_limits<int>::max();
				int tmpsum = sum[start][end];
				for ( int s = start; s < end; s++ ) {
					if ( totalmin > array[start][s] + array[s + 1][end] + tmpsum )
						totalmin = array[start][s] + array[s + 1][end] + tmpsum;
				}
				array[start][end] = totalmin;
			}
		}
		minResult[i] = array[0][K - 1];
	}
	for ( int i = 0; i < T; i++ ) {
		printf("%d\n", minResult[i]);
	}

	return 0;
}