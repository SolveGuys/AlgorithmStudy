#include <iostream>
#include <string>

inline int nCr(int n, int k)
{
	const int MAX = 1000001000;
	if (k > n) return 0;
	if (k * 2 > n) /*return*/ k = n - k;  //remove the commented section
	if (k == 0) return 1;

	long int result = n;
	for (int i = 2; i <= k; ++i) {
		result *= (n - i + 1);
		result /= i;

		if (result > MAX) 
		{
			result = MAX;
			break;
		}
	}
	return result;
}


int main()
{
	int n, m, k;
	std::cin >> n >> m >> k;

	int nmCm = nCr(n + m, m);

	if (k > nmCm) return std::cout << -1, 0;

	int a = n, z = m;
	k--;//k는 0부터
    
	std::string out_az = "";

	for(int i = 0; i < n+m; i++)
	{
		if (a == 0) //나머지가 전부 z
		{
			out_az += std::string(z,'z');
			break;
		}
		if (z == 0) //나머지가 전부 a
		{
			out_az += std::string(a,'a');
			break;
		}

		int z_threshold = nCr(a + z - 1, z);

		if (k >= z_threshold)
		{
			out_az += 'z';
			z--, k -= z_threshold;
		}
		else
		{
			out_az += 'a';
			a--;
		}
	}

	std::cout << out_az;
	return 0;
}
