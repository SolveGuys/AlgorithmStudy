#include <iostream>

using namespace std;

int n;
int heights[52];

int GetCount(int cur);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> heights[i];
	}

	int answer = 0;

	for (int i = 1; i <= n; ++i)
	{
		answer = max(answer, GetCount(i));
	}

	cout << answer << '\n';
}

int GetCount(int cur)
{
	int cnt = 0;

	// cur 건물 기준 왼쪽 검사
	for (int i = 1; i < cur; ++i)
	{
		int dx = cur - i;
		int dy = heights[cur] - heights[i];
		double slope = static_cast<double>(dy) / dx;
		bool isSeeable = true;

		for (int j = cur - 1; j > i; --j)
		{
			double y = slope * (j - i) + heights[i];

			// 지나거나 접하지 않아야 하므로 >=
			if (heights[j] >= y)
			{
				isSeeable = false;
				break;
			}
		}

		if (isSeeable)
		{
			++cnt;
		}
	}

	// cur 건물 기준 오른쪽 검사
	for (int i = n; i > cur; --i)
	{
		int dx = cur - i;
		int dy = heights[cur] - heights[i];
		double slope = static_cast<double>(dy) / dx;
		bool isSeeable = true;

		for (int j = cur + 1; j < i; ++j)
		{
			double y = slope * (j - i) + heights[i];

			// 지나거나 접하지 않아야 하므로 >=
			if (heights[j] >= y)
			{
				isSeeable = false;
				break;
			}
		}

		if (isSeeable)
		{
			++cnt;
		}
	}

	return cnt;
}
