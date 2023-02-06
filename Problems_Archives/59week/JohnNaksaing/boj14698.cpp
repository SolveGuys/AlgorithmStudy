#include <bits/stdc++.h>

using ty = int64_t;

int main()
{
	const int mod = 1000000007;
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
    
	while (n--)
	{
		int j;
		std::cin >> j;
		std::priority_queue<ty,std::vector<ty>,std::greater<ty>> pq;
		for (int i = 0; i < j; i++)
		{
            ty num;
			std::cin >> num;
			pq.push(num);
		}

		ty pi = 1;
		while (pq.size() > 1)
		{
			ty top1 = pq.top();
			pq.pop();
			ty top2 = pq.top();
			pq.pop();

			ty mul = (top1) * (top2);
			pq.push(mul);

			pi *= mul % mod;
			pi %= mod;
		}
        std::cout << pi << '\n';
	}
	return 0;
}
