/**********************************************************
2024-05-17
https://github.com/keastmin
백준/14863/서울에서 경산까지
난이도: 골드4
유형: 다이나믹 프로그래밍
**********************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> walkTime;
vector<int> walkCost;
vector<int> bikeTime;
vector<int> bikeCost;
vector<vector<int>> dp;

int Dynamic_Prog(int curr, int time) {
	// 제한 시간이 넘는 경우 어떤 수를 더해도 제한 시간을 준수한 방식보다 결과가 낮게 나와야함
	if (time > K) return -1000000000;

	// 제한 시간 내에 가장 끝 인덱스까지 도달했다면 계산에 영향이 가지 않을 0을 반환
	if (curr == N) return 0;

	// ret은 dp[curr][time]의 주소값을 가져 ret의 값이 변화하면 dp[curr][time]의 값도 변화
	int& ret = dp[curr][time];

	//cout << ret << ' ';

	// 방문한 적 있는 경우 그대로 반환(이미 최대값이 정해져 있기 때문)
	if (ret != -1) return ret;

	// 제한 시간을 준수하며 끝까지 가는 것이 중요하다.
	// 때문에 재귀를 통해 가능한 시간 내인지 검사하며 walkCost와 bikeCost를 더해가며 최대값을 찾는다.
	// 재귀의 특성상 가장 끝 인덱스까지 간 후 현재 최대 ret값이 반환된다.
	// 때문에 가능한 시간대의 경로를 따라 처음 인덱스까지 되돌아가며 ret값이 더해지며 최대값을 찾는다.
	ret = max(Dynamic_Prog(curr + 1, time + walkTime[curr]) + walkCost[curr],
			  Dynamic_Prog(curr + 1, time + bikeTime[curr]) + bikeCost[curr]);

	//cout << ret << '\n';

	return ret;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	walkTime.resize(N);
	walkCost.resize(N);
	bikeTime.resize(N);
	bikeCost.resize(N);

	// dp[N][K]: N번째 인덱스내에서 K시간 내에 가능한 Cost 합의 최대값
	dp.resize(N, vector<int>(K + 1, -1));
	for (int i = 0; i < N; i++) {
		cin >> walkTime[i] >> walkCost[i] >> bikeTime[i] >> bikeCost[i];
	}

	// 0번째 인덱스의 0분 내에 가능한 최대값부터 시작
	int res = Dynamic_Prog(0, 0);

	cout << res << '\n';

	return 0;
}
