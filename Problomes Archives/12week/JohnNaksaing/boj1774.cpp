#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
struct coordinate
{
	int x, y;
};

int parant[1001];

int find_parant(int idx) 
{
	if (parant[idx] == idx)return idx;
	else return parant[idx] = find_parant(parant[idx]);
}

bool make_union(int idx1, int idx2) 
{
	int p1 = find_parant(idx1), p2 = find_parant(idx2);
	if (find_parant(p1) == find_parant(p2)) return false;
	else return parant[p1] = p2, true;
}

struct connection
{
	int idx1, idx2;
	double length;
};

std::vector<connection> e_connections;

auto cmp_e = [](const connection& lhs, const connection& rhs)->bool {return lhs.length < rhs.length; };

inline double distance(const coordinate& lhs, const coordinate& rhs)
{
	long int x = (lhs.x - rhs.x);
	long int y = (lhs.y - rhs.y);
	return std::sqrt(x * x + y * y);
}

int main() 
{
	int N, M;
	std::cin >> N >> M;

	std::vector<coordinate> SpaceGods(N+1);
	for (int i = 1; i <= N; i++) 
	{
		int a, b;
		std::cin >> a >> b;
		SpaceGods[i] = {a,b};
	}
	for (int i = 1; i <= N; i++) parant[i] = i;

	double sum_of_already_given = 0.0;

	//std::cout << '\n';
	//for (int i = 0; i < SpaceGods.size(); i++)	std::cout << SpaceGods[i].x << '\n';

	//distance given
	for (int i = 0; i < M; i++)
	{
		int a, b;
		std::cin >> a >> b;
		//connected SpaceGods[a]+ SpaceGods[b].
		make_union(a,b);
		//sum_of_already_given += distance(SpaceGods[a],SpaceGods[b]);
	}

	//distance other
	for (int i = 1; i < N; i++)
	{
		//connected SpaceGods[a]+ SpaceGods[b].
		for (int j = i + 1; j <= N; j++) 
		{
			e_connections.push_back({ i,j,distance(SpaceGods[i],SpaceGods[j]) });
		}
	}

	std::sort(e_connections.begin(),e_connections.end(),cmp_e);

	double sum_of_dist = 0.0;

	for (int i = 0; i < e_connections.size(); i++) 
	{
		int idx1 = e_connections[i].idx1, idx2 = e_connections[i].idx2;
		if (make_union(idx1, idx2)) sum_of_dist += e_connections[i].length;
	}
	
	//iomanip required
	std::cout << std::fixed << std::setprecision(2) << sum_of_dist;// - sum_of_already_given;

	return 0;
}