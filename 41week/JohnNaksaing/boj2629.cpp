//  2172kb	0ms
#include <iostream>
#include <vector>
#include <unordered_set>
std::vector<int> choo;
std::unordered_set<int> dict;

int main()
{
	int n;
	std::cin >> n;
	
	choo.resize(n);
	
	dict.insert(0);
	for (int i = 0; i < n; i++) 
	{
		std::cin >> choo[i];

        //set을 단순히 돌 수 없다 ; insert로 추가하면 그것도 iteration을 돌기 때문.
		std::vector<int> vec_dict(dict.begin(),dict.end());
		int m = vec_dict.size();
		for (int j = 0; j < m; j++) 
		{
			dict.insert(vec_dict[j] + choo[i]);
			dict.insert(vec_dict[j] - choo[i]);
		}
	}

	int m;
	std::cin >> m;

	std::vector<int> query(m);
	for (int i = 0; i < m; i++)
	{
		std::cin >> query[i];
	}

	for (int i = 0; i < m; i++)
	{
		std::cout << (dict.find(query[i]) != dict.end()? 'Y' : 'N') << ' ';
	}

	return 0;
}

#ifdef using_vector_instead_of_set

//	2024kb	16ms
#include <iostream>
#include <algorithm>
#include <vector>
std::vector<int> choo;
std::vector<int> test;

int main()
{
	int n;
	std::cin >> n;

	choo.resize(n);

	test.push_back(0);

	for (int i = 0; i < n; i++)
	{
		std::cin >> choo[i];

		int k = test.size();
		for (int j = 0; j < k; j++)
		{
			int plus = test[j] + choo[i];
			if (std::find(test.begin(), test.end(), plus) == test.end())
			{
				test.push_back(plus);
			}
			int minus = test[j] - choo[i];
			if (std::find(test.begin(), test.end(), minus) == test.end())
			{
				test.push_back(minus);
			}
		}
	}

	int m;
	std::cin >> m;

	std::vector<int> query(m);
	for (int i = 0; i < m; i++)
	{
		std::cin >> query[i];
	}

	for (int i = 0; i < m; i++)
	{
		std::cout << (std::find(test.begin(), test.end(), query[i]) != test.end() ? 'Y' : 'N') << ' ';
	}

	return 0;
}

#endif