#include <iostream>
#include <algorithm>

using namespace std;

int n, x;
int arr[1'000'002];

void Solve();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> x >> n)
	{
		// 센티미터 -> 나노미터
		x *= 10'000'000;

		for (int j = 0; j < n; ++j)
		{
			cin >> arr[j];
		}

		sort(arr, arr + n);
		Solve();
	}
}

void Solve()
{
	int st = 0, en = n - 1;
	int l1 = 0, l2 = 0;

	while (st < en)
	{
		int sum = arr[st] + arr[en];

		if (sum < x)
		{
			++st;
		}
		else if (sum > x)
		{
			--en;
		}
		else
		{
			l1 = arr[st];
			l2 = arr[en];
			break;
		}
	}

	if ((l1 == 0) && (l2 == 0))
	{
		cout << "danger\n";
	}
	else
	{
		cout << "yes " << l1 << ' ' << l2 << '\n';
	}
}
