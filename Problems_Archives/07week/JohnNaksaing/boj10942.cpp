#include <cstdio>
#include <vector>
int main()
{
	int N;
	scanf("%d",&N);
	std::vector<int> nums(N+1);

	for (int i = 1; i <= N; i++) 
	{
		scanf("%d",&nums[i]);
	}
	
	//initializing
	std::vector< std::vector<bool>> dp_pel(N+1, std::vector<bool>(N+1,false));
	for (int i = 1; i < N; i++) 
	{
		dp_pel[i][i] = true;
		if(nums[i] == nums[i+1])
			dp_pel[i][i + 1] = true;
	}
	dp_pel[N][N] = true;

	for (int i = N-1; i > 0; i--) 
	{
		for (int j = i; j <= N; j++) 
		{
			if(nums[i] == nums[j] && dp_pel[i+1][j-1])
				dp_pel[i][j] = true;
		}
	}

	//inputs
	int M;
	scanf("%d",&M);
	while (M--) 
	{
		int S, E;
		scanf("%d %d",&S,&E);

		printf("%d\n",(int)dp_pel[S][E]);
	}
	return 0;
}

