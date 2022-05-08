#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
struct problem
{
	int num, deadline, reward;
};

struct sort_by 
{
	bool operator()(const problem& _left, const problem& _right)
	{
		return _left.deadline < _right.deadline;
	}
};

int main(void) 
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<problem> problems(n);

	int ramen = 0;

	for (int i = 0; i < n; i++)
	{
		std::cin >> problems[i].deadline >> problems[i].reward;
		problems[i].num = i;
		ramen += problems[i].reward;
	}
	
	std::sort(problems.begin(), problems.end(), sort_by());

	std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

	for (int i = 0; i < n; i++)
	{
		pq.push(problems[i].reward);
		if (pq.size() > problems[i].deadline)
		{
			ramen -= pq.top();
			pq.pop();
		}
	}
	std::cout << ramen;
	return 0;
}

