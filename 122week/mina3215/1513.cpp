#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int N, M, C;
int MAP[51][51];
long long DP[51][51][51][51];

#define DIV 1000007

void input() {
	fill(&MAP[0][0], &MAP[0][0]+51*51, 0);
	cin >> N >> M >> C;
	for (int i = 1; i <= C;i++) {
		int y, x;
		cin >> y >> x;
		MAP[y][x] = i;
	}
}

void find_ans(int y, int x) {
	
	int n = MAP[y][x];

	for (int cnt = 0; cnt < C + 1;cnt++) {
		for (int num = 0; num < C + 1; num++) {
			// 번호가 있는 오락실.
			if (n) {
				if (num >= n) break;
				DP[y][x][cnt + 1][n] += (DP[y - 1][x][cnt][num] + DP[y][x-1][cnt][num]) % DIV;
			}

			else {
				DP[y][x][cnt][num] += (DP[y - 1][x][cnt][num] + DP[y][x - 1][cnt][num]) % DIV;
			}
		}
	}
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(DP, 0, sizeof(DP));
	memset(MAP, 0, sizeof(MAP));
	
	input();

	DP[0][1][0][0] = 1;
	
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			find_ans(y, x);
		}
	}

	for (int cnt = 0; cnt < C+1;cnt++) {
		long long answer = 0;
		for (int num = 0; num < C + 1; num++) {
			answer += DP[N][M][cnt][num];
			answer %= DIV;
		}
		cout << answer << ' ';
	}
}