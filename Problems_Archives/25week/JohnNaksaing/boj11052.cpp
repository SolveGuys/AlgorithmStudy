#include <cstdio>
int main() 
{	
	int n, i,j;
	scanf("%d",&n);
	int costs[1001];
	
	for (i = 0; i < n; i++) 
	{
		scanf("%d",&costs[i]);
	}

	for (i = 1; i < n; i++) 
	{
		for(j = 0; j < i; j++)
		{
            if(costs[i] < costs[i - j -1] + costs[j])
			    costs[i] = costs[i - j -1] + costs[j];
		}
	}
    /*
	for (int i = 0; i < n; i++)
	{
		std::cout << costs[i] << ' ';
	}
    */
    printf("%d",costs[n-1]);
	return 0;
}