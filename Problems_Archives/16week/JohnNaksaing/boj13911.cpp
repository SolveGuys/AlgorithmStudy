#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

class solve 
{
    using weight = int;
    using index = int;

    const int INF = 987654321;

    int v, e;
    int m, x;
    int s, y;

    int starbucks, mcdonald;

    std::vector<std::vector<std::pair<index,weight>>> edges;

    struct compare 
    {
        bool operator()(const std::pair<index, weight>& _left, const std::pair<index, weight>& _right) const
        {
            return _left.second > _right.second;
        }
    };
    std::priority_queue<std::pair<index,weight>, std::vector<std::pair<index, weight>>,compare> pq;
    std::vector<weight> distances_mc;
    std::vector<weight> distances_sb;


public:
    solve(int v_, int e_) : v(v_),e(e_), edges(e+5),distances_mc(v+1,INF),distances_sb(v+1,INF), starbucks(v+1), mcdonald(v+2)
    {
        for (int i = 0; i < e; i++)
        {
            index from, to; 
            weight w;
            std::cin >> from >> to >> w;

            edges[from].emplace_back(to,w);
            edges[to].emplace_back(from,w);
        }

        std::cin >> m >> x;

        std::vector<int> mcs(m);
        for (int i = 0; i < m; i++)
        {
            index idx;
            std::cin >> idx;
            distances_mc[idx] = 0;
            pq.push({idx,0});
        }
        set_distance(distances_mc);

        std::cin >> s >> y;

        for (int i = 0; i < s; i++)
        {
            index idx;
            std::cin >> idx;
            distances_sb[idx] = 0;
            pq.push({idx,0});
        }

        set_distance(distances_sb);

    }

    void set_distance(std::vector<weight>& distances);

    int get_distance();
};

//dijkstra
void solve::set_distance(std::vector<weight>& distances)
{
    while (!pq.empty()) 
    {
        const std::pair<index,weight> node = pq.top();
        pq.pop();

        index here = node.first;
        weight cost = node.second;

        for (int i = 0; i < edges[here].size(); i++) 
        {
            index next_index = edges[here][i].first;
            weight next_weight = edges[here][i].second;

            if (cost + next_weight < distances[next_index]) 
            {
                distances[next_index] = cost + next_weight;
                pq.push({ next_index,distances[next_index] });
            }
        }
    }
}

int solve::get_distance() 
{
    int result = INF;

    for (int i = 1; i <= v; i++) 
    {
        //if(distances_mc[i] == -1 || distances_sb[i] == -1) continue;
        if (distances_mc[i] != 0 && distances_sb[i] != 0 && distances_mc[i] <= x && distances_sb[i] <= y) 
        {
            result = std::min(result, distances_mc[i] + distances_sb[i]);
        }

    }

    if (result == INF)
        result = -1;

    return result;
}

int main()
{
    int v, e;
    std::cin >> v >> e;

    solve _solve(v,e);

    std::cout << _solve.get_distance();
	return 0;
}