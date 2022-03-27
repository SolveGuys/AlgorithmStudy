#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,total;
vector<pair<int, int>> task;//과제

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		task.push_back({ a,b });
	}
	sort(task.begin(), task.end());//마감날짜순으로 정렬
}
//시험 채점
void exam() {
	priority_queue<int, vector<int>, greater<int>> pq;//최소힙
	for (int i = 0; i < n; i++) {
		int day = task[i].first;
		int score = task[i].second;
		pq.push(score);
		//과제 과부하
		if (pq.size() > day) pq.pop();
	}
	//점수 계산
	while(!pq.empty()) {
		total += pq.top();
		pq.pop();
	}
	cout << total;//출력
}
int main() {
	input();//입력
	exam();//시험 채점
	return 0;
}
