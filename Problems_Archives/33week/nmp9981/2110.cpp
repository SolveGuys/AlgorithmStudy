#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
const int maxi = 200001;
int home[maxi];//집의 위치

//입력
void input() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> home[i];
	sort(home, home + n);//정렬
}

//공유기의 개수
int Router(int x) {
	int cnt = 1;//개수
	int place = home[0];//설치 장소
	for (int i = 1; i < n; i++) {
		if (place + x <= home[i]) {
			cnt++;//개수 증가
			place = home[i];//설치 장소 갱신
		}
	}
	return cnt;
}

//공유기 설치
void install() {
	int left = 0;
	int right = 2000000000;
	while (left <= right) {
		int mid = (left + right) / 2;//간격
		if (Router(mid) >= c) {
			left = mid + 1;//간격을 늘림
		}
		else {
			right = mid - 1;//간격을 좁힘
		}
	}
	cout << right;//출력
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	input();//입력
	install();//공유기 설치
	return 0;
}
