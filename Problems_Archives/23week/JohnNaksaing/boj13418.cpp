#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class edge 
{
public:
	int to, from;
	bool bUp;
};

std::vector<edge> edges;
int parents[1001];
int find(int x) 
{
	if (parents[x] == x) return x;
	else return parents[x] = find(parents[x]);
}
bool merge(int x, int y)
{
	if (find(x) == find(y)) return false;

	parents[find(x)] = find(y);
	return true;
}

int mst(int n) 
{
	for (int i = 0; i <= n; i++)
		parents[i] = i;

	int count = 0, k = 0;
	for (edge& e : edges)
	{
		if (merge(e.to, e.from))
		{
			if (e.bUp == 0)
			{
				k++;
			}
			if (++count == n) break;
		}
	}
	return k * k;
}

int main() 
{
	int n, m;
	scanf("%d %d",&n,&m);
	for (int i = 0; i <= m; i++) 
	{
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		edges.push_back({ a,b,(bool)c });
	}

	std::sort(edges.begin(), edges.end(), [](edge& e1, edge& e2)->bool {return e1.bUp < e2.bUp; });
	int k_max = mst(n);
	
	std::sort(edges.begin(), edges.end(), [](edge& e1, edge& e2)->bool {return e1.bUp > e2.bUp; });
	int k_min = mst(n);

	printf("%d", k_max - k_min);
	return 0; 
}