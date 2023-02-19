#include <bits/stdc++.h>
bool visited[15]{ 0 };
int result = 0;
int visit_mask = 0;

int n, l, r, x;
std::vector<int> numbers;

void search(int idx, int max, int min, int sum)
{
	if (l <= sum && sum <= r && max - min >= x)
	{
		result++;
	}

	for (int i = idx; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			if (sum + numbers[i] <= r)
				search(i + 1, std::max(max, numbers[i]), std::min(min, numbers[i]), sum + numbers[i]);
			visited[i] = false;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	std::cin >> n >> l >> r >> x;
	numbers.resize(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> numbers[i];
	}

	search(0, -12345678 - 1, 12345678 + 1, 0);

	std::cout << result;

	return 0;
}