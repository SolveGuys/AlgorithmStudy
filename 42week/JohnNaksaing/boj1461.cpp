#include <iostream>
#include <algorithm>
#include <vector>

int main() 
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int n, m;
	std::cin >> n >> m;
	
	std::vector<int> book(n);

	int minus_count = 0;

	for (int i = 0; i < n; i++) 
	{
		std::cin >> book[i];
		if (book[i] < 0)
			minus_count++;
	}	
	std::sort(book.begin(),book.end());
	int result = 0;
	for (int i = 0; i < minus_count; i += m)
	{
		result += -book[i] * 2;
	}
	for (int i = minus_count; i < n; i += m)
	{
		result += book[i] * 2;
	}

	result -= std::max(std::abs(book[0]), std::abs(book[n-1]));

	std::cout << result;

	return 0;
}