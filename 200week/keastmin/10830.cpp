#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<int>> vvi;

int N;
ll B;

void MatrixMulti(vvi& matA, vvi& matB) {
	vvi tmp(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				tmp[i][j] += (matA[i][k] * matB[k][j]) % 1000;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matA[i][j] = tmp[i][j] % 1000;
		}
	}
}

int main() {
	cin >> N >> B;
	vvi matrix(N, vector<int>(N, 0));
	vvi A(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
		matrix[i][i] = 1;
	}

	while (B > 0) {
		if (B % 2 == 1) MatrixMulti(matrix, A);
		MatrixMulti(A, A);
		B /= 2;
	}

	for (const auto& mat : matrix) {
		for (const auto& m : mat) {
			cout << m << ' ';
		}
		cout << '\n';
	}

	return 0;
}
