/*
* 용액마다 특성을 나타내는 정수가 주어지고, 두 용액을 혼합한 특성값은 각각 용액의 특성값의 합
* 두 용액을 혼합하여 특성값이 0에 가까운 용액을 만들어내는 두 용액을 찾아야 함
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <memory.h>
#include<tuple>
using namespace std;

int n;
int a[100004];
int res = 2000000000; // 특성값 최대 20억
int ans1, ans2;

int main() {
	ios_base::sync_with_stdio();
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n); // 오름차순 정렬


	// 투포인터
	int l = 0, r = n - 1; // 맨 처음과 끝 설정
	int sum = 0;

	while (1) {
		if (l >= r) break;

		// 현재 포인터의 용액 특성값 합 계산
		sum = a[l] + a[r];

		// 현재 두 용액의 특성값의 합이 이전에 저장된 값보다 0에 더 가까운지 확인
		if (res > abs(sum)) { // 더 가까운 경우, 그 값을 갱신
			res = abs(sum);
			ans1 = a[l];
			ans2 = a[r];
		}

		if (sum > 0) r--; // 특성값의 합이 0보다 큰 경우, 오른쪽 포인터를 왼쪽으로 이동
		else l++; // 특성값의 합이 0보다 작은 경우, 왼쪽 포인터를 오른쪽으로 이동
	}

	cout << ans1 << " " << ans2 << "\n";

	return 0;
}
