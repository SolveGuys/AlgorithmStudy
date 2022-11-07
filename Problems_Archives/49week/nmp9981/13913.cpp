#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Hide {
private:
	static const int inf = 100001;
	int n, k;
	int visit[inf];//이전 지점
	vector<int> root;//경로
public:
	Hide();//생성자
	void input();//입력
	void Search();//탐색
	void FindRoot(int x);//경로 찾기
	void output();//출력
};

//생성자
Hide::Hide() {
	n = 0; k = 0;
	root.clear();
	for (int i = 0; i < inf; i++) visit[i] = inf;
}
//입력
void Hide::input() {
	cin >> n >> k;
}
//경로 찾기
void Hide::FindRoot(int x) {
	root.push_back(x);//경로 저장
	if (x == n) return;//종료
	FindRoot(visit[x]);//이전 지점
}
//탐색
void Hide::Search() {
	queue<pair<int, int>> q;
	q.push({ n,0 });//시작 지점

	while (!q.empty()) {
		int x = q.front().first;
		int sec = q.front().second;
		q.pop();

		//도착
		if (x == k) {
			cout << sec << "\n";//시간 출력
			FindRoot(x);//경로 찾기
			return;
		}
		//다음 지점
		if (x + 1 < inf && visit[x + 1]==inf) {//범위 내에 들고 미방문
			visit[x + 1] = x;//이전 지점 기록
			q.push({ x + 1,sec + 1 });
		}
		if (x - 1 >= 0 && visit[x - 1]==inf) {//범위 내에 들고 미방문
			visit[x - 1] = x;//이전 지점 기록
			q.push({ x - 1,sec + 1 });
		}
		if (x*2 < inf && visit[x*2]==inf) {//범위 내에 들고 미방문
			visit[x*2] = x;//이전 지점 기록
			q.push({ 2 * x,sec + 1 });
		}
	}
}
//출력
void Hide::output() {
	for (int i = root.size() - 1; i >= 0; i--) cout << root[i] << " ";
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Hide hide;
	hide.input();//입력
	hide.Search();//탐색
	hide.output();//출력
	return 0;
}
