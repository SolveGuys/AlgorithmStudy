#include<iostream>

using namespace std;


int N;

int main() {
	cin >> N;
	if (N % 2) {
		cout << 0;
		return 0;
	}
	int DP[31];
	DP[1] = 1;
	DP[2] = 3;
	for (int i = 3; i <= N;i++) {
		if (i % 2)
			DP[i] = DP[i - 2] + DP[i - 1];
		else
			DP[i] = DP[i - 2] + DP[i - 1] * 2;
	}
	cout << DP[N];
}