#include <iostream>
using namespace std;

int g,p;
const int maxi = 100001;
int airplain[maxi];//비행기
int parent[maxi];//부모노드

//입력
void input() {
	cin >> g>>p;
	for (int i = 0; i <= g; i++) parent[i] = i;//초기 각 노드의 부모노드
	for (int i = 0; i < p; i++) cin >> airplain[i];//도착 비행기 입력
}

//해당 노드의 부모노드
int find(int x) {
	//부모노드이면
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
//합치기
void add(int x, int y) {
	int a = find(x);
	int b = find(y);
	parent[b] = a;
}

//공항
void airport() {
	int cnt = 0;//주차된 비행기 대수
	for (int i = 0; i < p; i++) {
		int k = find(airplain[i]);//부모노드 구하기
		if (k==0) break;//도킹 불가
		add(k-1,k);//이전지점과 결합, k번 비행기면 k,k-1,k-2...순으로 넣기
		cnt++;
	}
	cout << cnt;//출력
}
int main() {
	input();//입력
	airport();//공항
	return 0;
}
