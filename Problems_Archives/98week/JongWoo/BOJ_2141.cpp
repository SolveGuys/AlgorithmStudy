#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m;
int A[1'002];
int B[1'002];
int accumA[1'002];
int accumB[1'002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	cin >> n;

	vector<int> v1, v2;

	for (int i = 1; i <= n; ++i)
	{
		cin >> A[i];
		accumA[i] = accumA[i - 1] + A[i];
		v1.push_back(A[i]);
	}

	for (int len = 2; len <= n; ++len)
	{
		for (int i = 0; i <= n - len; ++i)
		{
			v1.push_back(accumA[i + len] - accumA[i]);
		}
	}

	cin >> m;

	for (int i = 1; i <= m; ++i)
	{
		cin >> B[i];
		accumB[i] = accumB[i - 1] + B[i];
		v2.push_back(B[i]);
	}

	for (int len = 2; len <= m; ++len)
	{
		for (int i = 0; i <= m - len; ++i)
		{
			v2.push_back(accumB[i + len] - accumB[i]);
		}
	}

	long long answer = 0;

	sort(v1.begin(), v1.end());

	for (int i = 0; i < v2.size(); ++i)
	{
		auto p = equal_range(v1.begin(), v1.end(), t - v2[i]);

		answer += (p.second - p.first);
	}

	cout << answer << '\n';
}
