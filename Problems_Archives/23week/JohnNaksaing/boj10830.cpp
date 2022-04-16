#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template<typename T>
using matrix2x2 = std::vector<std::vector<T>>;

matrix2x2<int> multiply(matrix2x2<int> m1, matrix2x2<int> m2)
{
	int n = m1.size();
	matrix2x2<int> temp(n,std::vector<int>(n,0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				temp[i][j] += m1[i][k] * m2[k][j];
			}
			temp[i][j] %= 1000;

		}
	}

	return temp;
}
matrix2x2<int> power(matrix2x2<int> a, long long int b){
	if (b == 1)
        return a;

	if (b & 0x1)
		return multiply(power(a,b - 1),a);

	matrix2x2<int> sqrt = power(a, b / 2);
	return multiply(sqrt, sqrt);
}

int main()
{
	int n;
    long long int b;
	scanf("%d %lld", &n, &b);

	matrix2x2<int> a(n,std::vector<int>(n));
	matrix2x2<int> result(n, std::vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a_ij;
			scanf("%d", &a_ij);

			a[i][j] = a_ij % 1000;
		}

	}

	result = power(a, b);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}