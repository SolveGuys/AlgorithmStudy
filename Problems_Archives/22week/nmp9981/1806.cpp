#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
const int maxi = 100001;
const int inf = 1e+7;
int A[maxi];//수열
int ans = inf;//수열의 길이

//입력
void input() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> A[i];
}
//부분합
void subsum() {
	int left = 0;
	int right = 0;
	int sum = A[0];//부분합
	//두 포인터 이용
	while (left <= right && right<n) {//right가 수열의 길이를 넘지 않게
		//s이상
		if (sum >= s) {
			ans = min(ans, right - left + 1);//길이 갱신
			sum -= A[left];
			left++;
		}else {//s미만
			right++;
			sum += A[right];
		}
	}
	//결과
	if (ans >= inf) cout << 0;//불가능
	else cout << ans;
}
int main() {
	input();//입력
	subsum();//부분합
	return 0;
}
