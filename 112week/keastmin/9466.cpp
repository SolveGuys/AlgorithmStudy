/**********************************************************
2024-04-10
https://github.com/keastmin
백준/9466/텀 프로젝트
난이도: 골드3
유형: 수학
**********************************************************/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T;						// 테스트 케이스
int N;						// 학생의 수
vector<int> graph[100001];	// 그래프를 저장하는 변수
bool visited[100001];		// 방문 여부
bool finished[100001];		// 사이클을 찾는데에 사용 된 적이 있는가
int res;					// 사이클, 즉 팀을 이룬 학생의 수

void dfs(int curr) {
	// dfs가 시작되는 과정에서 진핸되는 방문 처리
	visited[curr] = true;

	// 다음 번호
	int next = graph[curr][0];

	// 방문한 적이 없다면 dfs 진행
	if (!visited[next])
		dfs(next);
	else {
		// 방문한 적이 있지만 사이클을 찾는데에 이용된 적이 없다면 팀을 이룰 수 있는 학생을 찾음
		if (!finished[next]) {
			// 현재 학생의 팀들의 수를 카운트
			for (int i = next; i != curr; i = graph[i][0])
				res++;
			// 자기 자신 카운트
			res++;
		}
	}

	// dfs가 종료되는 과정에서 진행되는 방문 처리, 사이클을 찾는데에 이용되는 변수
	finished[curr] = true;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	// 테스트 케이스 입력
	cin >> T;
	while (T--) {

		// 초기화
		memset(visited, false, sizeof(visited));
		memset(finished, false, sizeof(finished));
		for (int i = 0; i <= 100000; i++) {
			graph[i].clear();
		}
		res = 0;

		// 학생 수 입력
		cin >> N;

		// 그래프 입력
		for (int i = 1; i <= N; i++) {
			int a;
			cin >> a;
			graph[i].push_back(a);
		}
		
		// 아직 방문하지 않은 학생 번호 dfs
		for (int i = 1; i <= N; i++) {
			if(!visited[i])
				dfs(i);
		}

		// 전체 학생 수에서 팀을 이룬 학생 수 제외 출력
		cout << N - res << '\n';
	}

	return 0;
}
