/**********************************************************
2024-04-11
https://github.com/keastmin
백준/2109/순회강연
난이도: 골드3
유형: 자료 구조, 그리디 알고리즘, 정렬, 우선순위 큐
**********************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;	// 대학의 개수
vector<pair<int, int>> pay;		// 일 수와 강연료
priority_queue<int, vector<int>, greater<int>> q;	// 큰 강연료를 기준으로 정렬할 우선순위 큐
int res = 0;	// 결과

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	// 초기화
	cin >> N;
	pay.resize(N);

	// 강연료와 일 수 초기화
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		pay[i].first = b; pay[i].second = a;
	}

	// 일 수를 기준으로 오름차순 정렬
	sort(pay.begin(), pay.end());
	
	/************************************************
	우선순위 큐에 강연료 삽입 후 만약 우선순위 큐의 사이즈가 
	해당 대학에서 요청한 일 수를 초과한다면 다시 팝.

	문제에서 주어진 일 수는 강연에 소요되는 시간이 아닌
	"언제까지 와주면 된다." 이므로 예를 들어 3일이라면
	3일 안에 오면 된다는 것으로 경우에 따라서는 1일차에 가도 된다.

	즉 우선순위 큐의 사이즈를 일 수와 동일시 한다면 큐 안에는
	해당 일 수에 맞는 강연료 중 가장 큰 수들만 남게 된다.
	*************************************************/
	for (int i = 0; i < N; i++) {
		q.push(pay[i].second);
		if (q.size() > pay[i].first) {
			q.pop();
		}
	}

	// 우선순위 큐에 남아있는 강연료 합산
	while (!q.empty()) {
		res += q.top();
		q.pop();
	}

	// 결과 출력
	cout << res << '\n';
	return 0;
}
