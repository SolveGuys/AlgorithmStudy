/**********************************************************
2024-04-19
https://github.com/keastmin
백준/7579/앱
난이도: 골드3
유형: 다이나믹 프로그래밍, 배낭 문제
**********************************************************/

#include <iostream>
#include <vector>
using namespace std;

int N, M, sum = 0;		// sum: 활성화된 앱의 메모리의 최댓값을 찾는데에 사용되는 재시작 비용의 합
vector<int> appMemory;	// 활성화된 앱의 메모리
vector<int> appCost;	// 활성화된 앱의 재시작 비용

int dp() {
	// disable[a][b]: 첫 번째부터 a번째 앱까지 b만큼의 재시작 비용 내에서 확보 가능한 최대 메모리
	vector<vector<int>> disable(N + 1, vector<int>(sum + 1, 0));
	int res = 0;

	for (int appCnt = 1; appCnt <= N; appCnt++) {
		for (int cost = 0; cost <= sum; cost++) {

			// 전체 재시작 비용에서 현재 번호의 앱의 재시작 비용을 뺀 값이 0 이상이어야 현재 번호의 앱을 포합하여 계산 가능
			if (cost - appCost[appCnt] >= 0) {

				// 현재 번호까지의 현재 코스트 내에 최대 메모리 사용량 계산
				// disable[appCnt - 1][cost - appCost[appCnt]] + appMemory[appCnt]: 
				// 현재 번호의 앱의 메모리 사용량을 추가하여 연산을 시도해 볼 것이므로
				// 현재 번호의 앱을 연산에 추가하려면 현재 최대 재시작 비용에서 현재 번호의 앱의 재시작 비용이 들어갈 자리가 필요함: cost - appCost[appCnt]
				// 즉 [appCnt - 1][cost - appCost[appCnt]]를 통해 현재 번호의 앱이 포함되지 않은 이전 번호까지의 앱, 전체 재시작 비용에 현재 번호의 앱의 재시작 비용이 빠진 결과에
				// appMemory[appCnt]라는 현재 번호의 앱의 메모리 사용량을 더해줌
				disable[appCnt][cost] = max(disable[appCnt][cost], disable[appCnt - 1][cost - appCost[appCnt]] + appMemory[appCnt]);
			}

			// 위의 연산에 더해 한 번 더 최대값을 찾는 이유
			// 만약 현재 번호의 앱까지의 최대 비용, 즉 cost에서 현재 번호의 비용을 뺀 값이 0을 넘지 않을 경우 
			// 이전 번호 앱까지의 최대 메모리 사용량이 현재 번호의 현재 최대 코스트까지의 최대 메모리 사용량이므로 덮어쓸 수 있어야 함
			// 아래의 코드를 주석처리 한 것과 안 한 것의 차이를 디버깅 해보면 구분 가능
			disable[appCnt][cost] = max(disable[appCnt][cost], disable[appCnt - 1][cost]);
			
			// 디버깅
			// cout << disable[appCnt][cost] << ' ';
		}
		// cout << '\n';
	}

	// 확보해야하는 메모리, 즉 M을 넘기는 최소 재시작 비용을 찾고 break;
	for (int cost = 0; cost <= sum; cost++) {
		if (disable[N][cost] >= M) {
			res = cost;
			break;
		}
	}

	return res;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	appMemory.resize(N + 1);
	appCost.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> appMemory[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> appCost[i];

		// 재시작 비용의 합 누적
		sum += appCost[i];
	}

	// 재시작 비용 별로 최대 메모리 사용량 저장 후, M을 넘으면서 가장 가까운 최소 재시작 비용 출력
	cout << dp() << '\n';

	return 0;
}
