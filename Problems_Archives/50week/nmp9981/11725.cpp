#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxi = 100001;
vector<int> graph[maxi];
int parent[maxi];//각 노드의 부모 노드

//입력
void input() {
	cin >> n;
	//초기화
	for (int i = 1; i <= n; i++) parent[i] = 0;
	//그래프 연결
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);//양방향 그래프
		graph[b].push_back(a);
	}
}

//탐색
void dfs(int st) {
	//다음 지점
	for (int i = 0; i < graph[st].size(); i++) {
		int next = graph[st][i];//다음 노드
		if (parent[next] != 0) continue;//방문여부
		parent[next] = st;//부모 노드 저장
		dfs(next);
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	input();//입력
	dfs(1);//탐색
	for (int i = 2; i <= n; i++) cout << parent[i] << "\n";
	return 0;
}
