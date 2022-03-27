#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() 
{
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> vec;
	while (n--) 
	{
		int day, score;
		std::cin >> day >> score;
		vec.push_back({ day,score });
	}
	std::sort(vec.begin(),vec.end());

	std::priority_queue<int,std::vector<int>,std::greater<int>> pq;

	for (int i = 0; i < vec.size(); i++) 
	{
		int day = vec[i].first;
		int score = vec[i].second;

		pq.push(score);
		if (pq.size() > day)
			pq.pop();
	}

	int score_total = 0;
	while (!pq.empty()) 
	{
		score_total += pq.top();
		pq.pop();
	}
	std::cout << score_total;
	return 0;
}

