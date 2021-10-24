#include <iostream>
//#include <vector>
#include <string>
#include <unordered_set>

int main() {
	//using vec2x2 = std::vector<std::vector<int>>;
	using vec2x2 = std::string;
	vec2x2 BOARD = "";
	vec2x2 ANSWER = "123456780";


	const int X[] = {0,-1,0,1};
	const int Y[] = {1,0,-1,0};

	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			int a; std::cin >> a;
			char a_toStr = a + '0';
			BOARD += a_toStr;
		}
	}

	std::unordered_set<vec2x2> visited = { BOARD };
	std::queue<std::pair<vec2x2,int>> bfsQ;

	bfsQ.push(std::make_pair(BOARD,0));

	while (!bfsQ.empty())
	{
		vec2x2 front = bfsQ.front().first;
		int count = bfsQ.front().second;
		bfsQ.pop();

		if (front == ANSWER)
		{
			std::cout << count;
			return 0;
		}

		int x, y;
		int z = front.find('0');
		x = z / 3, y = z % 3;
		
		/*
		for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (front[i][j] == 0)
			{
				x = i, y = j;
				break;
			}
		}
		*/
		//std::cout << count << "\n";
		/*
		std::cout << "\n";
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++)
			{
				std::cout << front[i][j] << " ";
			}
			std::cout << "\n";
		}
		*/
		//

		for (int i = 0; i < 4; i++) 
		{
			int nx, ny;
			nx = x + X[i], ny = y + Y[i];
			
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
			{
				vec2x2 next = front;
				std::swap(next[x*3 + y], next[nx*3 + ny]);

				if (visited.find(next) == visited.end()) 
				{
					bfsQ.push(std::make_pair(next, count + 1));
					visited.insert(next);
				}
			}
		}
	}
	
	std::cout << -1;
	return 0;
}

/*
1 0 3
4 2 5
7 8 6

1 2 3
4 5 6
7 8 0

3 6 0
8 1 2
7 4 5

*/