#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() 
{
	int N, S;
	scanf("%d %d", &N, &S);
	std::vector<int> vec(N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &vec[i]);
	}

	int begin_idx = 0, end_idx = 0;
	int min_length = 100'000'000;
	int temp_sum = 0;


	while (begin_idx <= end_idx)
	{
		if (temp_sum >= S) 
		{
			min_length = std::min(min_length,end_idx - begin_idx);
			temp_sum -= vec[begin_idx++];
		}
		else 
		{
			if (end_idx == N) break;
			else temp_sum += vec[end_idx++];
		}
		
	}


	
	if (min_length == 100'000'000)
		printf("0");
	else
		printf("%d",min_length);

	return 0; 
}