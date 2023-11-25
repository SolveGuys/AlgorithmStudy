#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[100'002];
int answer[1'000'002];
vector<int> divisors[1'000'002];

void GetDivisor(int num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];

		if (divisors[arr[i]].empty())
		{
			GetDivisor(arr[i]);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int div : divisors[arr[i]])
		{
			if ((div != arr[i]) && (!divisors[div].empty()))
			{
				++answer[div];
				--answer[arr[i]];
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << answer[arr[i]] << ' ';
	}
}

void GetDivisor(int num)
{
	for (int i = 1; i * i <= num; ++i)
	{
		if (num % i == 0)
		{
			divisors[num].push_back(i);
		}
	}

	for (int i = static_cast<int>(divisors[num].size()) - 1; i >= 0; --i)
	{
		if (divisors[num][i] * divisors[num][i] == num)
		{
			continue;
		}

		divisors[num].push_back(num / divisors[num][i]);
	}
}
