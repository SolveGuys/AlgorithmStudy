#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int team[21][21];

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> team[i][j];
		}
	}
	
	
	vector<int> mask(N);
	fill(mask.begin(), mask.end(), 1);
	for (int i = 0; i < N / 2; i++) {
		mask[i] = 0;
	}
	int min_V = 2e9;
	//for (auto i : mask) cout << i;
	do {
		int teamA = 0;
		int teamB = 0;

		//for (auto i : mask) cout << i<<' ';
		//cout << '\n';
		
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				if (mask[i] && mask[j]) teamA += team[i][j] + team[j][i];
				if (!mask[i] && !mask[j]) teamB += team[i][j] + team[j][i];
			}
		}
		min_V = min(abs(teamA - teamB), min_V);
		

	} while (next_permutation(mask.begin(), mask.end()));
	
	cout << min_V;


}