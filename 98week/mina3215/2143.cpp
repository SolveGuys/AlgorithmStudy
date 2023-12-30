#include<iostream>
#include<map>
#include<vector>

using namespace std;

int T, N, M;
int sumN[1000];
int sumM[1000];

vector<long long> numN;
map<long long, int> numM;

int main() {
	cin >> T;
	cin >> N;

	sumN[0] = 0;
	sumM[0] = 0;
	
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		sumN[i] = sumN[i - 1] + n;

		for (int j = 0; j < i; j++) {
			numN.push_back(sumN[i]-sumN[j]);
		}
	}

	cin >> M;
	
	for (int i = 1; i <= M; i++) {
		int m;
		cin >> m;
		sumM[i] = sumM[i - 1] + m;
		for (int j = 0; j < i; j++) {
			if (!numM[sumM[i] - sumM[j]]) {
				numM[sumM[i] - sumM[j]] = 1;
			}
			else {
				numM[sumM[i] - sumM[j]] += 1;
			}
		}
	}

	long long ans = 0;

	for (int i = 0; i < numN.size(); i++) {
		if (numM[T-numN[i]]) {
			ans += numM[T-numN[i]];
		}
	}

	cout << ans;

}