#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);
    
	int n;
	std::cin >> n;

	std::vector<std::pair<int, int>> lines(n);

	for (int i = 0; i < n; i++) 
	{
		std::cin >> lines[i].first >> lines[i].second;
	}

	std::sort(lines.begin(),lines.end());

	int length = 0;
	int left = lines[0].first, right = lines[0].second;

	for (int i = 1; i < n; i++)
	{
		if (lines[i].first > right)
		{
			length += right - left;
			left = lines[i].first;
			right = lines[i].second;
		}
		else
		{
			right = std::max(right,lines[i].second);
		}
	}
	length += right - left;

	return std::cout << length, 0;
}