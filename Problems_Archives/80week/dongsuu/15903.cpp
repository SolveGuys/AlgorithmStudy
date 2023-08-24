#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

ll N, M, cnt, ans;
ll arr[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// Input
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];

	// 카드 합체 후 항상 오름차순 정렬 후, 젤 작은값과 그 다음으로 작은값의 카드를 합체하는 것이 가장 점수를 작게 만들 수 있다.
	while (1) {
		if (cnt == M) break; // 카드 합체 횟수 다 사용하면 종료
		std::sort(arr, arr + N);
		ll sum = arr[0] + arr[1]; // 항상 젤 작은값 + 그 다음 작은값

		// 덮어씌우기
		arr[0] = sum;
		arr[1] = sum;
		cnt++; // 횟수 count
	}
	// SUM 계산
	for (int i = 0; i < N; i++) ans += arr[i];

	// Output
	cout << ans << '\n';
	return 0;
}