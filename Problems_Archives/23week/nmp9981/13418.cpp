#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n,m;
const int maxi =1001;
int parent[maxi];//각 노드의 부모노드
vector<pair<int, pair<int, int>>> up_road;//오르막길
vector<pair<int, pair<int, int>>> down_road;//내리막길
int up_tired = 0;//오르막 피곤함 수치
int down_tired = 0;//내리막 피곤함 수치

//입력
void input() {
	cin >> n>>m;
	//부모노드 초기화
	for (int i = 0; i <= n; i++) parent[i] = i;
	//길 입력
	for (int i = 0; i <= m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		up_road.push_back({ 1-d,{a,b} });//오르막 먼저
		down_road.push_back({ d-1,{a,b} });//내리막 먼저
	}
	//정렬
	sort(up_road.begin(), up_road.end());
	sort(down_road.begin(), down_road.end());
}

//루트노드 구하기
int find(int k) {
	if (parent[k] == k) return k;
	return parent[k] = find(parent[k]);
}
//오르막길 연결
void up_connect() {
	int node = 0;//연결노드
	for (int i = 0; i <= m; i++) {
		int x = up_road[i].second.first;
		int y = up_road[i].second.second;
		int t = up_road[i].first;

		//연결
		int a = find(x);
		int b = find(y);
		if (a != b) {
			parent[b] = a;//연결
			node++;//노드 증가
			up_tired += t;//피로도 증가
		}
		//모두 연결
		if (node == n) return;
	}
}
//내리막길 연결
void down_connect() {
	int node = 0;//연결노드
	for (int i = 0; i <= m; i++) {
		int x = down_road[i].second.first;
		int y = down_road[i].second.second;
		int t = down_road[i].first;

		//연결
		int a = find(x);
		int b = find(y);
		if (a != b) {
			parent[b] = a;//연결
			node++;//노드 증가
			down_tired += t;//피로도 증가
		}
		//모두 연결
		if (node == n) return;
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	up_connect();// 오르막길 연결
	for (int i = 0; i <= n; i++) parent[i] = i;//부모노드 초기화
	down_connect();//내리막길 연결
	cout << abs(pow(up_tired, 2) - pow(down_tired, 2));//피로도 구하기
	return 0;
}
