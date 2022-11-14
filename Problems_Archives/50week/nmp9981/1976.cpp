#include <iostream>
using namespace std;

int n,m;
const int maxi = 201;
const int planMaxi = 2001;
int world[maxi][maxi];//각 도시간 연결 여부
int parent[maxi];//각 노드의 루트 노드
int plan[planMaxi];//여행 계획

//입력
void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> world[i][j];
	}
	for (int i = 0; i < m; i++) cin >> plan[i];
}
//루트노드 구하기
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
//합치기(a,b의 루트노드와 합치기)
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}
//그래프 연결
bool connect() {
	//루트 노드 초기화
	for (int i = 1; i <= n; i++) parent[i] = i;
	//도시 연결
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (world[i][j] == 1 && i < j) merge(i, j);
		}
	}
	int stdRoot = find(plan[0]);//첫 도시의 루트노드
	for (int i = 1; i < m; i++) {//여행이 가능한가?
		if (stdRoot != find(plan[i])) return false;
	}
	return true;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	input();//입력
	//여행이 가능한가?
	if (connect() == true) cout << "YES";
	else cout << "NO";
	return 0;
}
