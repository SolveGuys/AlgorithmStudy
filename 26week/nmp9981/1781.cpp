#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> ramen;

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int date, reward;
		cin >> date >> reward;
		ramen.push_back({ date,reward });
	}
	sort(ramen.begin(), ramen.end());//날짜 기준으로 정렬
}

//라면 먹기
void eat() {
	priority_queue<int,vector<int>,greater<int>> pq;//최소 힙
	for (int i = 0; i < n; i++) {
		int day = ramen[i].first;//마감 기한
		int score = ramen[i].second;//보상

		pq.push(score);//최소 힙에 넣기
		//용량초과
		if (day < pq.size()) pq.pop();//가장 작은것 빼기
	}
	//최대 보상 구하기
	int sum = 0;
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum;//출력
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	eat();//라면 먹기
	return 0;
}
