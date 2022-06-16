#include <cstio>
#include <vector>
#include <algorithm>
//	5136	224
const bool check(int height,const std::vector<int>& trees, const long sum, const int M)
{
#ifndef first_idea
	long taken = 0;
	for (int i = 0; i < trees.size(); i++) 
	{
		if (trees[i] > height)
			taken += trees[i] - height;
		if (taken >= M)
			return true;
	}
	return false;
#else
	// height보다 작은 tree높이는 0보다 작은 값이 나오기때문에, loop를 돌려서 찾아야 한다.
	long current = height * trees.size();
	return sum - current >= M;
#endif
}

int main()
{
	int N, M;
	scanf("%d %d",&N, &M);

	std::vector<int> trees(N);
	long sum = 0;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &trees[i]);
		sum += trees[i];
	}

	std::sort(trees.begin(),trees.end());

    const int big = 1e9;
	long left = 0, right = big;
	int answer;

	while (left <= right) 
	{
		int mid = (left + right) / 2;

		if (check(mid,trees,sum,M)) 
		{
			answer = mid;
			left = mid + 1;
		}
		else 
		{
			right = mid - 1;
		}
	}

	printf("%d",answer);

	return 0;
}