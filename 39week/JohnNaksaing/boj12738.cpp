#include <vector>
#include <algorithm>
#include <iostream>

int main() 
{
	int n;
	scanf("%d",&n);
	std::vector<int> vec(n);
	std::vector<int> smol;
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &vec[i]);	
	}

	int max_length = 0;

	int count = 0;
	smol.emplace_back(vec[0]);

	using iter = std::vector<int>::iterator;

	for (int i = 0; i < n; i++) 
	{
		if (vec[i] > smol.back()) 
		{
			smol.emplace_back(vec[i]);
		}
		else 
		{
			iter replace = std::lower_bound(smol.begin(), smol.end(), vec[i]);
			*replace = vec[i];
		}
	}

	printf("%d", smol.size()); 

	return 0;
}