#include <iostream>
#include <vector>

//6048KB	1088ms

int main(void) 
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int x, n;
		
	while (std::cin >> x >> n) 
	{
		std::vector<int> blocks(n);

		for (int i = 0; i < n; i++) 
			std::cin >> blocks[i];
		
		int length = x * 1e7;

		std::sort(blocks.begin(),blocks.end());

		int front = 0;
		int back = blocks.size() - 1;

		while (front < back) 
		{
			int& L_1 = blocks[front];
			int& L_2 = blocks[back];

			if (L_1 + L_2 < length)
			{
				front++;
			}
			else if(L_1 + L_2 > length)
			{
				back--;
			}
			else 
			{
				std::cout << "yes " << L_1 << ' ' << L_2 << '\n';
				break;
			}
		}
		if (front >= back) 
		{
			std::cout << "danger" << '\n';
		}
	}	
	return 0;
}