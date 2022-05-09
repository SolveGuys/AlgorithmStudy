#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
vector<pair<int, int>> ramen;//컵라면
//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int deadline, reward;
		cin >> deadline >> reward;
		ramen.push_back({ deadline,reward });
	}
	sort(ramen.begin(), ramen.end());//데드라인 기준으로 정렬
}

//먹기
void eat() {
	priority_queue<int, vector<int>, greater<int>> pq;//최소힙
	for (int i = 0; i < ramen.size(); i++) {
		int deadline = ramen[i].first;
		int reward = ramen[i].second;

		pq.push(reward);
		//용량초과
		if (deadline < pq.size()) pq.pop();
	}
	//힙에있는 원소들의 합
	int total = 0;
	while (!pq.empty()) {
		total += pq.top();
		pq.pop();
	}
	cout << total;//출력
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	eat();//먹기
	return 0;
}
