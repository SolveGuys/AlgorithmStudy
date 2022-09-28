#include <iostream>
#include <queue>
using namespace std;
typedef unsigned long long ull;

string s;//문자열
ull sum = 0;//총 합

//탐색
void Search() {
	queue<pair<ull, int>> q;//노드 결과, 인덱스
	q.push({ 1,0 });//초기값

	while (!q.empty()) {
		ull curNode = q.front().first;//현재 노드 결과
		int curIndex = q.front().second;//현재 인덱스
		q.pop();

		//*을 만날때까지 반복(bfs횟수를 줄인다)
		while (curIndex < s.size()) {
			if (s[curIndex] == 'L') curNode <<1;//L
			if (s[curIndex] == 'R') curNode = (curNode<<1)+1;//R
			if (s[curIndex] == '*') break;

			curIndex++;
		}

		//끝까지 갔다
		if (curIndex == s.size()) {
			sum += curNode;
			continue;
		}

		//다음지점
		q.push({ curNode<<1,curIndex + 1 });//L
		//q.push({ curNode,curIndex + 1 });//P
		q.push({ (curNode <<1)+1,curIndex + 1 });//R
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;//입력
	Search();//탐색
	cout << sum;//출력
	return 0;
}
