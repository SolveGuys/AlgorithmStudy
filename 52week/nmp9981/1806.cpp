#include <iostream>
using namespace std;

int n,s;
const int maxi = 100001;
int A[maxi];//수열

//min
inline int min(int x, int y) {
	return x > y ? y : x;
}
//입력
void input() {
	cin >> n>>s;
	for (int i = 0; i < n; i++) cin >> A[i];
}
//부분합
void Csum() {
	int sum = A[0]; int cnt = n + 1;
	int left = 0; int right = 0;//부분합 범위
	while (left <= right && right<n) {
		if (sum < s) {//합이 목표보다 작으므로 범위를 늘린다.
			right++;
			sum += A[right];
		}
		else if (sum >= s) {//합이 목표보다 이상이므로 범위를 좁힌다.
			cnt = min(cnt, right - left + 1);
			sum -= A[left];
			left++;
		}
	}
	//출력
	if (cnt > n) cout << 0;
	else cout << cnt;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	input();//입력
	Csum();//부분합
	return 0;
}
