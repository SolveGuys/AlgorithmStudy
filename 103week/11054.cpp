/**********************************************************
2024-02-03
https://github.com/keastmin
백준/11054/가장 긴 바이토닉 부분 수열
난이도: 골드4
유형: DP(Dynamic-Programming)
**********************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	// C와의 입출력 버퍼 동기화를 해제하여 빠른 속도를 확보
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	// 수열의 개수 입력받기
	int N;
	cin >> N;

	vector<int> arr(N, 0);		// 수열을 저장하는 배열
	vector<int> lis(N, 0);		// 가장 긴 부분 증가 수열 길이 저장
	vector<int> rev_lis(N, 0);	// 역순으로 긴 부분 증가 수열 저장

	// 수열을 배열에 저장
	for (int i = 0; i < N; i++) {
		int m;
		cin >> m;
		arr[i] = m;
	}

	// DP를 이용하여 가장 긴 부분 수열 길이 도출
	for (int i = 0; i < N; i++) {
		lis[i] = 1;
		for (int j = 0; j < i; j++) {

			// 현재 수보다 크기가 작으면서 길이가 긴 부분 증가 수열 저장
			if (arr[i] > arr[j]) {
				lis[i] = max(lis[i], lis[j] + 1);
			}
		}
	}

	// 위의 과정을 역순으로 수행
	for (int i = N - 1; i >= 0; i--) {
		rev_lis[i] = 1;
		for (int j = N - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				rev_lis[i] = max(rev_lis[i], rev_lis[j] + 1);
			}
		}
	}

	// 길이가 긴 부분 증가 수열과 그 역순의 길이에서 -1을 했을 때 가장 긴 길이 찾기
	// -1은 현재 자신을 가리키는 수가 중복되기 때문
	int res = 0;
	for (int i = 0; i < N; i++) {
		res = max(res, (lis[i] + rev_lis[i]) - 1);
	}

	cout << res << '\n';

	return 0;
}