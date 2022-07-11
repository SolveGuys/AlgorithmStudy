#include <iostream>
#include <queue>
#include <set>
using namespace std;

int n, m,ans;
const int maxi = 100001;
int card[maxi];//카드 현황

//입력
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> card[i];
}

//크기비교
inline int max(int x, int y) {
	return x > y ? x : y;
}

//구매
void purchase() {
	set<int> s;//중복여부 검사, 현재 저장되어 있는 카드와 숫자
	queue<int> q;//인덱스를 담는 큐(현재 카드팩의 상품)

	int left = 1;
	int right = maxi/m;

	while (left <= right) {
		int mid = (left + right) / 2;//구성품의 개수
		s.clear();
		int cnt = 0;//카드팩의 개수

		for (int i = 0; i < n; i++) {
			auto dup = s.insert(card[i]);
			if (dup.second) {//중복이 안된다면
				q.push(i);//인덱스 넣기
			}
			else {//중복된 숫자 발견
				//카드팩에 있는 상품은 필요없어진다,
				int num = card[i];
				while (!q.empty()) {
					int p = q.front();
					q.pop();
					s.erase(card[p]);
					if (card[p] == num) break;
				}
				//새로운 구성품 넣기
				s.insert(card[i]);
				q.push(i);
			}

			//카드팩 1개 만들어짐
			if (s.size() >= mid) {
				s.clear();
				cnt++;
				while (!q.empty()) q.pop();
			}
		}

		if (cnt >= m) {//구성품의 개수가 적으므로 팩이 많다
			left = mid + 1;//구성품의 개수를 늘린다.
			ans = max(ans, mid);
		}
		else {
			right = mid - 1;//구성품의 개수를 줄인다.
		}

		while (!q.empty()) q.pop();//초기화
	}
	cout << ans;//정답
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	purchase();//구매
	return 0;
}
