#include <iostream>
#include <string>

using namespace std;

void Solve(const string& w, int k);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		string w = {};
		int k = 0;

		cin >> w >> k;
		Solve(w, k);
	}
}

void Solve(const string& w, int k)
{
	int minLen = 0x7fffffff, maxLen = 0;
	int freq[26] = {};

	for (int i = 0; i < w.length(); ++i)
	{
		++freq[w[i] - 'a'];
	}

	for (int i = 0; i < w.length(); ++i)
	{
		if (freq[w[i] - 'a'] < k)
		{
			continue;
		}

		int cnt = 0;

		for (int j = i; j < w.length(); ++j)
		{
			if (w[i] == w[j])
			{
				++cnt;

				if (cnt == k)
				{
					minLen = min(minLen, j - i + 1);
					maxLen = max(maxLen, j - i + 1);
					break;
				}
			}
		}
	}

	if ((minLen == 0x7fffffff) || (maxLen == 0))
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << minLen << ' ' << maxLen << '\n';
	}
}
