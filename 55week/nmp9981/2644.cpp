#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,p1,p2,m;
const int maxi = 101;
vector<int> graph[maxi];//친척 관계
bool visit[maxi];//방문 여부

//입력
void input() {
	cin >> n;
	cin >> p1 >> p2;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}
//촌수 계산
void Kinship(int p1,int p2) {
	queue<pair<int,int>> q;
	q.push({ p1,0 });
	visit[p1] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		//도착
		if (x == p2) {
			cout << cnt;
			return;
		}
		//다음 지점
		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i];
			if (visit[next] == true) continue;//방문 조건
			visit[next] = true;
			q.push({ next,cnt + 1 });
		}
	}
	cout << -1;//아무 관계가 아닌 경우
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    input();//입력
	Kinship(p1,p2);//촌수 계산
	return 0;
}
