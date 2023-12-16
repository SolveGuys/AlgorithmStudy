#include <iostream>
#include <climits>

using namespace std;

// 0: 6
// 1: 2
// 2: 5
// 3: 5
// 4: 4
// 5: 5
// 6: 6
// 7: 3
// 8: 7
// 9: 6
int nums[8] = { 0, 0, 1, 7, 4, 2, 0, 8 };
long long dp[101];

void PrintMinNumber(int n);
void PrintMaxNumber(int n);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n = 0;

		cin >> n;
		PrintMinNumber(n);
		cout << ' ';
		PrintMaxNumber(n);
		cout << '\n';
	}
}

void PrintMinNumber(int n)
{
	for (int i = 2; i < 8; ++i)
	{
		dp[i] = nums[i];
	}

	// 첫 자리는 0으로 시작할 수 없다.
	dp[6] = 6;

	// 8번째부터는 두 자리 수가 되는데 따로 초기화한 이유는 dp[1]의 값을 참조하지 않도록 하기 위해서다. (dp[1] + nums[7])
	dp[8] = 10;

	for (int i = 9; i <= n; ++i)
	{
		dp[i] = LLONG_MAX;

		for (int j = 2; j < 8; ++j)
		{
			dp[i] = min(dp[i], 10 * dp[i - j] + nums[j]);
		}
	}

	cout << dp[n];
}

void PrintMaxNumber(int n)
{
	if (n % 2 == 1)
	{
		cout << 7;
		n -= 3;
	}

	for (int i = 0; i < n / 2; ++i)
	{
		cout << 1;
	}
}
