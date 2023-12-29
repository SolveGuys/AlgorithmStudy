#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int n, k;
vector<pair<int, int>> jewels; // <무게, 가격>
multiset<int> bags;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	jewels.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> jewels[i].first >> jewels[i].second;
	}

	for (int i = 0; i < k; ++i)
	{
		int c = 0;

		cin >> c;
		bags.insert(c);
	}

	// 보석을 가격 기준으로 내림차순 정렬한다.
	sort(jewels.begin(), jewels.end(),
		[](const auto& a, const auto& b)
		{
			// 두 보석의 가격이 같다면, 무게 기준으로 오름차순 정렬한다.
			if (a.second == b.second)
			{
				return a.first < b.first;
			}

			return a.second > b.second;
		});

	long long answer = 0;

	for (int i = 0; i < jewels.size(); ++i)
	{
		auto iter = bags.lower_bound(jewels[i].first);

		if (iter != bags.end())
		{
			answer += jewels[i].second;
			bags.erase(iter);
		}
	}

	cout << answer << '\n';
}
