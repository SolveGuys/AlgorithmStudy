#include <iostream>
#include <algorithm>
//#include <vector>

//	127164KB	2724ms
int main() 
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;

	int *a, *b, *c, *d;
	a = new int[n];	b = new int[n];	c = new int[n];	d = new int[n];
	//std::vector<int> a(n), b(n), c(n), d(n);

	for (int i = 0; i < n; i++) std::cin >> a[i] >> b[i] >> c[i] >> d[i];


	int* ab = new int[n*n], * cd = new int[n*n];
	//std::vector<int> ab(n*n), cd(n*n);
	
	int k = 0;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			ab[k] = a[i] + b[j];
			cd[k++] = c[i] + d[j];
		}
	}
	delete[] a, b, c, d;

	std::sort(ab, ab + k), std::sort(cd, cd + k);
	//std::sort(ab.begin(), ab.end()), std::sort(cd.begin(), cd.end());


	int start = 0, end = k-1, sum;
    long int answer = 0;
	while (start < k && end >= 0) 
	{
		sum = ab[start] + cd[end];
		if (sum > 0)
		{
			end--;
		}
		else if (sum < 0) 
		{
			start++;
		}
		else// if (sum == 0)
		{

			//int idx1 = start, idx2 = end;
			long int cnt_ab{}, cnt_cd{};
			
			int i = start;
			while (i < k && ab[start] == ab[i])
			{
				cnt_ab++;
				i++;
			}
			start = i;

			i = end;
			while (i >= 0 && cd[end] == cd[i])
			{
				cnt_cd++;
				i--;
			}
			end = i;

			answer += cnt_ab * cnt_cd;
		}
	}

	std::cout << answer;
	
    delete[] ab, cd;
	
    return 0;
}

