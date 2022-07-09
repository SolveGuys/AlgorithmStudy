#include <bits/stdc++.h>

constexpr int MAX_SIZE = 100'000;
constexpr int MAX_NUMBER = 500'000;

int cards[MAX_SIZE+1];
int bUsed[MAX_NUMBER+1];

//mid : 카드팩 하나의 크기
bool check(int mid, int n, int m) 
{
	int count = 0, end = 1;
	memset(bUsed, 0, sizeof(bUsed));
	for (int i = 1; i <= n; ++i) 
	{
		if (bUsed[cards[i]] > 0 && bUsed[cards[i]] >= end)
			end = bUsed[cards[i]] + 1;

		bUsed[cards[i]] = i;

		//카드팩 1개 완료
		if(i- end + 1 == mid)
		{
			count++;
			end = i + 1;
		}
		if (count == m)
			return true;
	}
	return count == m;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;
	
	for (int i = 1; i <= n; i++) 
	{
		std::cin >> cards[i];
	}
	int left = 1, right = n, answer;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (check(mid,n,m))
		{
			answer = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	std::cout << answer;

	return 0;
}