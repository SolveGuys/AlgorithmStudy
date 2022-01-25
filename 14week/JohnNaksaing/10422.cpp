#include <vector>

constexpr int by_mod = 1'000'000'007;

long long int dp_parnths[5001];

long long int get_parnts_count(int idx)
{
	static long long int dp_parnths[5001];

	if (idx % 2 != 0) return (dp_parnths[idx] = 0ll);
	
	{
		dp_parnths[0] = 1;
		dp_parnths[2] = 1;
	}

	auto get_val = [](int n, auto& get_val)->long long int
	{
		if (dp_parnths[n])
			return dp_parnths[n];

		for (int i = 2; i <= n; i+=2)
		{
			dp_parnths[n] += get_val(i-2, get_val) * get_val(n-i,get_val);		
			dp_parnths[n] %= by_mod;
		}
		
		return dp_parnths[n];
	};
	   
	return get_val(idx, get_val);
}

int main()
{
	int testcase_total;
	std::cin >> testcase_total;

	while (testcase_total--)
	{
		int testcase;
		std::cin >> testcase;

		std::cout << get_parnts_count(testcase) << '\n';
	}

	return 0;
}
