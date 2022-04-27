#include <stdio.h>

#pragma warning(disable:4996)

int n, m;
int lo, mid, hi;
int arr[100001];
int sum;
int answer=1e18;

int min(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	return b;
}

int check(int mid)
{
	int num = 0;
	int tmp = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > mid) return 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (tmp + arr[i] > mid)
		{
			num++;
			tmp= 0;
		}
		tmp += arr[i];
	}
	num++;

	return num <= m;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	lo = 1;
	hi = sum;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if(check(mid))
		{
			//answer = min(answer, mid);
			answer = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	printf("%d", answer);


	return 0;
}
