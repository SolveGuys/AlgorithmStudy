#include <string>
#include <vector>

const int INT_MAX = 100000000;

class distance_table
{
	std::vector<std::vector<int>> distances;
	int n;
	void folyd_warshall();
public:
	//void print_dist();
	distance_table(int n, const std::vector<std::vector<int>>& fares) : n(n), distances(std::vector<std::vector<int>>(n, std::vector<int>(n, INT_MAX)))
	{
		for (const auto& fare : fares)
		{
			distances[fare[0]-1][fare[1]-1] = fare[2];
			distances[fare[1]-1][fare[0]-1] = fare[2];
		}
		
		for (int i = 0; i < n; i++) 
		{
			distances[i][i] = 0;
		}

		folyd_warshall();
	}

	int get_dist(int s, int a, int b);
};
/*
void distance_table::print_dist() 
{
	for (const auto& distance : distances) 
	{
		for (const auto& dist : distance) 
		{
			std::cout << dist << '\t';
		}
		std::cout << '\n';
	}
}
*/
void distance_table::folyd_warshall() 
{
	for (int pass = 0; pass < n; pass++) 
	{
		for (int start = 0; start < n; start++) 
		{
			for (int end = 0; end < n; end++) 
			{
				//if (pass == start || start == end || end == pass) continue;
				
				distances[start][end] = std::min(distances[start][end],distances[start][pass] + distances[pass][end]);
			}
		}
	}
}

int distance_table::get_dist(int s, int a, int b) 
{
	int answer = INT_MAX;
	for (int i = 0; i < n; i++) 
	{
		//if(distances[s][i] != INT_MAX && distances[i][a-1] != INT_MAX && distances[i][b-1] != INT_MAX)
			answer = std::min(answer,distances[s-1][i] + distances[i][a-1] + distances[i][b-1]);
	}
	return answer;
}	

int solution(int n, int s, int a, int b, std::vector<std::vector<int>> fares) {
	
	distance_table _tbl(n,fares);

	//std::cout << '\n';
	//_tbl.print_dist();
	//std::cout << '\n';

	return _tbl.get_dist(s,a,b);

}