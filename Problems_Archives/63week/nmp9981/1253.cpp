#include <iostream>
#include <algorithm>
using namespace std;

int n;
const int maxi = 2001;
int A[maxi];//수열

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	sort(A, A + n);//오름 차순 정렬
}
//좋은 수 개수
void GoodNum() {
	int cnt = 0;//좋은 수 개수
	for (int i = 0; i < n; i++) {//각 숫자에 대해
		int left = 0;
		int right = n-1;
		while (left < right) {
			if (A[left] + A[right] == A[i]) {//좋은 수 검사
				if (i!=left && i!= right) {
					cnt++;
					break;
				}
				//본인
				if (left == i) left++;
				if (right == i) right--;
			}
			else if (A[left] + A[right] < A[i]) left++;//커져야함
			else if (A[left] + A[right] > A[i]) right--;//작아져야함
		}
	}
	cout << cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();//입력
	GoodNum();//좋은 수
	return 0;
}
