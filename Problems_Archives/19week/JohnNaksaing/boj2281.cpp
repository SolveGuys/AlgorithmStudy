#include <iostream>
#include <cstring>


int names[1001];
int n, m;

const int init_val = -1;

int dp_1d[1001];

int bottom_up(int name)
{
	int& result = dp_1d[name];

	if (result != init_val)
		return result;

	result = 1000000000;
	for (int i = name, sum = names[name];
		i < n && sum <= m;
		i++, sum += names[i] + 1)
	{
		if (i == n - 1)
		{
			result = 0;
			break;
		}

		result = std::min(result, (m - sum) * (m - sum) + bottom_up(i + 1));
	}

	return result;
}

int main()
{
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
		std::cin >> names[i];

	//memset(dp,init_val,sizeof(dp));
	memset(dp_1d, init_val, sizeof(dp_1d));

	//std::cout << get_dp(0, 0);
	std::cout << bottom_up(0);

	return 0;
}
