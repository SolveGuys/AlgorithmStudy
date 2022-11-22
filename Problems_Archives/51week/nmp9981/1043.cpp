#include <iostream>
#include <vector>
using namespace std;

int n, m;
const int maxi = 51;
vector<int> graph[maxi];//파티 목록
vector<int> know;//진실을 아는 자
int parent[maxi];//각 노드의 부모노드

//각 노드의 루트노드 구하기
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
//그래프 합치기(루트노드와 합치기)
void merge(int a, int b) {
	a = find(a); b = find(b);
	parent[b] = a;
}
//입력
bool input() {
	cin >> n >> m;
	int knowHuman; cin >> knowHuman;
	//진실을 아는 자
	for (int i = 0; i < knowHuman; i++) {
		int tu; cin >> tu;
		know.push_back(tu);
	}
	//그래프 입력
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		for (int j = 0; j < num; j++) {
			int people; cin >> people;
			graph[i].push_back(people);
		}
	}
	if (knowHuman == 0) return false;
	return true;
}
//파티
void Party() {
	//루트노드 초기화
	for (int i = 1; i <= n; i++) parent[i] = i;
	//그래프 합치기
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < graph[i].size(); j++) merge(graph[i][0], graph[i][j]);
	}
	//파티 검사
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		bool flag = true;//파티 참석이 가능한가?
		for (int j = 0; j < graph[i].size(); j++) {
			if (flag == false) break;
			int human = graph[i][j];
			for (int k = 0; k < know.size(); k++) {
				if (find(human) == find(know[k])) {
					flag = false;
					break;
				}
			}
		}
		if (flag == true) cnt++;
	}
	cout << cnt;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	//진실을 아는자가 존재하는가?
	if (input() == false) cout << m;
	else Party();//파티의 개수
	return 0;
}
