#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>

using namespace std;

#define INF 2e9

int C, N;
vector<pair<int, int>> hotel;
int DP[1001];


void input() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C >> N;
	int cost, plus;
	for (int i = 0; i < N; i++) {
		cin >> cost >> plus;
		hotel.push_back({ cost, plus });
	}
}

int main() {
	input();
	fill(DP, DP + 1001, INF);
	sort(hotel.begin(), hotel.end(), greater<pair<int,int>>());

	for (int i = 0; i < hotel.size();i++) {
		int c, p;
		tie(c, p) = hotel[i];
		for (int j = 1; j <= C; j++) {
			int cost = c + c * ((j-1) / p);
			DP[j] = min(DP[j],cost);
			if((j-1)/p)
				DP[j] = min(DP[j], DP[j - p] + c);
		}
	}

	cout<< DP[C];
}