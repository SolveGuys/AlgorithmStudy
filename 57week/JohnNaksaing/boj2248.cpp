#include <bits/stdc++.h>

const int NOT_BUILD = -1;
long dp[33][33];
std::string str;

long build(int n, int m) 
{
	long& here = dp[n][m];

	if (here != NOT_BUILD)
		return here;
	if (n == 0 || m == 0)
		return here = 1;

	here = build(n - 1, m);
	if (m > 0)
		here += build(n - 1, m - 1);

	return here;
}

void getnum(int n, int l, long nth)
{
	if (n == 0)
		return;

	if (l == 0) 
	{
		while (n--)
			str += '0';
		return;
	}

	long piv = build(n-1,l);

	if (piv >= nth)
	{
		str += '0';
		getnum(n-1,l,nth);
	}
	else 
	{
		str += '1';
		getnum(n - 1, l - 1, nth - piv);
	}
}

int main()
{
	memset(dp,NOT_BUILD,sizeof(dp));

	int n,l;
    long i;
	scanf("%d %d %d", &n, &l, &i);
	
	getnum(n,l,i);

	printf("%s", str.c_str());

	return 0;
}