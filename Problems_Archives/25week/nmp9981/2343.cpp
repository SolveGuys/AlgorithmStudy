#include <iostream>
#include <algorithm>
using namespace std;

int n,m,st,ed;
const int maxi = 100001;
int A[maxi];//카드 i개일때 최대금액

//입력
void input() {
	ed = 0;
	cin >> n>>m;
	for (int i = 0; i < n; i++) cin >> A[i];
	//시작점, 끝점 구하기
	for (int i = 0; i < n; i++) {
		st = max(st, A[i]);
		ed += A[i];
	}
}
//블루레이 개수
int blueray(int x) {
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + A[i] > x) {
			cnt++;
			sum = 0;
		}
		sum += A[i];
	}
	cnt++;//마지막 한세트
	return cnt;
}
//기타 레슨
void lesson() {
	while (st <= ed) {
		int mid = (st + ed) / 2;
		if (blueray(mid) > m) {
			st = mid + 1;
		}
		else {//같으면 1줄인다.(최솟값을 구하는 문제이므로)
			ed = mid - 1;
		}
	}
	cout << st;//출력
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	lesson();//기타 레슨
	return 0;
}
