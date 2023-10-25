#include <iostream>

using namespace std;

int n;
int arr[100'002];
int sum[100'002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	int answer = 0;

	// 1. 벌을 양 끝에 배치하는 경우
	for (int i = 2; i < n; ++i)
	{
		answer = max(answer, (sum[i] - arr[1]) + (sum[n - 1] - sum[i - 1]));
	}

	// 2. 벌통을 첫 번째 위치에 배치하는 경우(한 마리 벌은 반대쪽 끝에 위치하고, 나머지 벌은 i번째에 위치)
	for (int i = 2; i < n; ++i)
	{
		answer = max(answer, sum[i - 1] + (sum[n - 1] - arr[i]));
	}

	// 3. 벌통을 마지막 위치에 배치하는 경우(한 마리 벌은 반대쪽 끝에 위치하고, 나머지 벌은 i번째에 위치)
	for (int i = 2; i < n; ++i)
	{
		answer = max(answer, (sum[n] - arr[1] - arr[i]) + (sum[n] - sum[i]));
	}

	cout << answer << '\n';
}
