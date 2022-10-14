#include <bits/stdc++.h>
int main() 
{
	int n;
	std::cin >> n;

	std::vector<int> poss;

	std::vector<int> negs;

	int num;
	int zero_count = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin >> num;
		if (num > 0)
			poss.push_back(num);
		else if (num < 0)
			negs.push_back(num);
		else
			zero_count++;
	}

	std::sort(poss.begin(), poss.end());
	std::sort(negs.begin(), negs.end(), std::greater<int>());

	int sum = 0;
	//for(int i = 0; i < negs.size() - 1; i+= 2)
	for (int i = negs.size() - 1; i >= 1; i -= 2)
	{
		sum += negs[i] * negs[i - 1];
	}
	for (int i = poss.size() - 1; i >= 1; i -= 2)
	{
		if(poss[i] * poss[i - 1] > poss[i] + poss[i - 1])
			sum += poss[i] * poss[i - 1];
		else
			sum += poss[i] + poss[i - 1];
	}

	if ((negs.size() % 2 == 0) || (negs.size() % 2 != 0 && zero_count > 0))
		;
	else
		sum += negs.front();
	//poss.size() != 0 &&
	if ( poss.size() % 2 != 0)
		sum += poss.front();
	
	std::cout << sum;
	return 0;
}