#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxi = 100001;
int cnt = 0;//간선 수
int lastNode = 0;//마지막 노드
int depth = 0;//마지막 노드까지 깊이
int moveCnt = 0;//간선 수
bool visit[maxi];//방문 여부
vector<int> graph[maxi];//그래프

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b != -1) cnt++;
		graph[a].push_back(b);
		if (c != -1) cnt++;
		graph[a].push_back(c);
	}
}
// 중위 순회
void inOrder(int node)
{
	if (node == -1) return;

	// left - root - right
	inOrder(graph[node][0]);
	lastNode = node;
	inOrder(graph[node][1]);
}
//순회
void Tour(int idx, int dist) {
	//마지막 노드
	if (idx == lastNode) depth = dist;

	//다음 지점
	for (int i = 0; i < 2; i++) {
		int next = graph[idx][i];
		if (next == -1) continue;//자식 노드가 없음
		if (visit[next] == true) continue;//방문 지역

		visit[next] = true;
		Tour(next, dist + 1);
		visit[next] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	inOrder(1);//중위 순회
	Tour(1, 0);//마지막 노드로 순회
	cout << 2 * cnt - depth;
	return 0;
}
