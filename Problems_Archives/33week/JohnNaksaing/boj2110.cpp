#include <bits/stdc++.h>
bool check_mid(const std::vector<int>& vec,int mid, int c)
{
	int count = 1;
	int here = vec[0];
	for (int i = 1; i < vec.size(); i++) 
	{
		if (vec[i] - here >= mid)
		{
			count++;
			here = vec[i];
		}
	}
	return count >= c;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n,c;
	std::cin >> n >> c;
	std::vector<int> vec(n);

	for (int i = 0; i < n; i++) 
	{
		std::cin >> vec[i];
	}
	std::sort(vec.begin(),vec.end());

	int left = 1, right = *(vec.end()-1) - *vec.begin();
	int answer = -1;
	
	while (left <= right) 
	{
		int mid = (left + right) / 2;
		if (check_mid(vec,mid, c)) 
		{
			answer = mid;
			left = mid + 1;
		}
		else 
		{
			right = mid-1;
		}
	}
	std::cout << answer;
	return 0;
}