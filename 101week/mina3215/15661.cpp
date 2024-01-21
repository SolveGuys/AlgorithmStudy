#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int person[21][21];
int N;

vector<vector<int>> v;

//ÆÀ, num, k
int combination(vector<int> &team, int num, int k) {
	if (num > N) {
		v.push_back(team);
		return 0;
	}

	team[num]=1;
	combination(team, num + 1, k+1);
	team[num]=0;
	combination(team, num + 1, k);

	return 0;

}


int main() {
	cin >> N;
	

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> person[i][j];
		}
	}

	vector<int> team(N+1);
	combination(team, 1, 0);


	int min_V = 2e9;

	for (int i = 0; i < v.size(); i++) {
		int teamA = 0;
		int teamB = 0;
		for (int j = 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				if (v[i][j]&&v[i][k]) {
					teamA += person[j][k] + person[k][j];
				}
				else if(!v[i][j]&&!v[i][k]) {
					teamB += person[j][k] + person[k][j];
				}
			}
		}
		min_V = min(abs(teamA - teamB), min_V);
	}

	cout << min_V;
}