#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//	2020	196

int map[10][10];
bool bVisited[10];

int distance = 987654321;
void search(int idx_now, int N, int dist) 
{
	bool bAllSearched = true;
	//BT
	if (dist > distance)
		return;

	//all searched case : distance = min(distance,dist)
	for (int i = 0; i < N; i++) 
	{
		if (!bVisited[i]) 
		{
			bAllSearched = false;
			break;
		}
	}

	if (bAllSearched) 
	{
		distance = std::min(dist,distance);
		return;
	}

	for (int i = 0; i < N; i++) 
	{
		if (bVisited[i])
			continue;

		bVisited[i] = true;

		search(i,N,dist + map[idx_now][i]);

		bVisited[i] = false;
	}

}


int main() 
{
	int n, k;
	std::cin >> n >> k;


	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			std::cin >> map[i][j];
		}
	}
	
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map[i][j] = std::min(map[i][j],map[i][k] + map[k][j]);
			}
		}
	}

	search(k, n, 0);

	std::cout << distance;

	return 0; 
}