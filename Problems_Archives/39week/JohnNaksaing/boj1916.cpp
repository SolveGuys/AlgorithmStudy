#include <vector>
#include <queue>
#include <iostream>

struct node
{
	int idx, weight;
};
auto compare = [](node& l, node& r) ->bool {return l.weight > r.weight; };
int search(int from, int to, std::vector<int>& dist, const std::vector<std::vector<node>>& map)
{
	std::priority_queue<node, std::vector<node>, decltype(compare)> pq(compare);

	pq.push({ from,0 });

	while (!pq.empty()) 
	{
		node here = pq.top();
		pq.pop();

        ////otherwise TLE in 26%/////////
		if (here.weight > dist[here.idx])
			continue;
        /////////////////////////////////
        
		for (node next : map[here.idx]) 
		{
			if (next.weight + here.weight < dist[next.idx]) 
			{
				dist[next.idx] = next.weight + here.weight;
				pq.push({next.idx,dist[next.idx]});
			}
		}
	}

	return dist[to];
}

int main() 
{
	int n, m;
	scanf("%d %d", &n, &m);
	const int big = 1e9;
	std::vector<std::vector<node>> map(n+1, std::vector<node>());
	std::vector<int> dist(n+1,big);

	while (m--) 
	{
		int from, to, weight;
		scanf("%d %d", &from, &to);//std::cin >> from >> to >> weight;
		scanf("%d",&weight);
		map[from].push_back({to,weight});
	}
		
	int from, to;
	scanf("%d %d", &from, &to);//std::cin >> from >> to;
	
	int answer = search(from, to, dist, map);
	printf("%d",answer);
	return 0;
}