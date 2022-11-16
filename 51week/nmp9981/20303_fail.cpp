#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k,child,candySum;
const int maxi = 30001;
vector<int> graph[maxi];//친구 관계
int candy[maxi];//사탕 개수
int visit[maxi];//방문여부
vector<pair<int, int>> getItem;//사탕 수, 인원 수

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
	cin >> n >> m>>k;
	for (int i = 1; i <= n; i++) cin >> candy[i];//사탕 개수
	//그래프 입력
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);//양방향 그래프
		graph[b].push_back(a);
	}
}
//사탕 스틸
bool Steal(int st) {
	queue<int> q;
	q.push(st);
	visit[st] = true;//방문 체크
	
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		if (child >= k) return false;//인원 초과

		for (int j = 0; j < graph[node].size(); j++) {
			int next = graph[node][j];//다음 지점
			if (visit[next] == false) {//미방문인 지역만
				visit[next] = true;
				child++;
				candySum += candy[next];
				q.push(next);
			}
		}
	}
	return true;
}
//정산
void Account() {
	//for (int i = 0; i < getItem.size();i++) cout << getItem[i].first << " " << getItem[i].second << "\n";
	int total = 0; int human = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//사탕 개수
	for (int i = getItem.size() - 1;i>=0; i--) {
		pq.push({ getItem[i].first,getItem[i].second });
		human += getItem[i].second;
		//인원 초과
		if (human >= k) {
			human -= pq.top().second;
			pq.pop();
		}
	}
	while (!pq.empty()) {
		total += pq.top().first;
		pq.pop();
	}
	cout << total;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	input();//입력
	//사탕 스틸
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			child = 1; candySum = candy[i];//초기화
			//인원 내로 들어오는 경우만 넣는다.
			if(Steal(i)) getItem.push_back({ candySum, child });
		}
	}
	if(getItem.size()>=1) sort(getItem.begin(), getItem.end());//사탕 수 기준으로 정렬
	Account();//사탕 정산
	return 0;
}
