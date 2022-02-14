#include <iostream>
#include <vector>
#include <cmath>.

int main() 
{
	int N;
	std::cin >> N ;
	
	std::vector<int> BigTrain(N+1);
	std::vector<std::vector<int>> Trains3(4,std::vector<int>(N+1));

	for (int i = 1; i <= N; i++) 
	{
		std::cin >> BigTrain[i];
		BigTrain[i] += BigTrain[i - 1];
	}
	int SmallTrain;
	std::cin >> SmallTrain;

	//i = 1,2,3
	for (int i = 1; i <= 3; i++)
	{
		// j의 앞에 소형차 i대 지나감
		for (int j = i * SmallTrain; j <= N; j++) 
		{
			Trains3[i][j] = std::max(
				//지금 경우가 최대
				Trains3[i - 1][j - SmallTrain] + BigTrain[j] - BigTrain[j - SmallTrain],

				//지금 경우가 안 최대
				Trains3[i][j - 1]
			);
		}
	}

	std::cout << Trains3[3][N];
	return 0;
}
