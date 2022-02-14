#include <iostream>
#include <vector>
const std::array< std::array<std::string,5>,10 > nums 
{ {
	{"###","#.#","#.#","#.#","###"}, //0
	{"..#","..#","..#","..#","..#"}, //1
	{"###","..#","###","#..","###"}, //2
	{"###","..#","###","..#","###"}, //3
	{"#.#","#.#","###","..#","..#"}, //4
	{"###","#..","###","..#","###"}, //5
	{
		"###",
		"#..",
		"###",
		"#.#",
		"###"
	}, //6
	{"###","..#","..#","..#","..#"}, //7
	{"###","#.#","###","#.#","###"}, //8
	{"###","#.#","###","..#","###"}  //9
} };


int main()
{
	int N;
	std::cin >> N;

	std::array<std::string, 5> input;

	for (int i = 0; i < 5; i++) 
	{
		std::cin >> input[i];
	}	

	float answer = 0.0f, digit = 1.0f;
	for (int i = N - 1; i >= 0; i--)
	{
		int sum = 0, count = 0;

		for (int num = 0; num < 10; num++) 
		{
			bool bHit = true;
			for (int row = 0; row < 5; row++)
			for (int col = 0; col < 3; col++)
				if (nums[num][row][col] == '.' && input[row][4 * i + col] == '#')
					bHit = false;
			if (bHit) 
			{
				count++;
				sum += num;
			}
		}
		if (cnt == 0) 
			return std::cout << -1, 0;

		answer += digit * sum / count;
		digit *= 10;
	}

	std::cout << answer;

	return 0;
}