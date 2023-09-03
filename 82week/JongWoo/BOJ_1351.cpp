#include <iostream>
#include <unordered_map>

using namespace std;

long long n;
int p, q;
unordered_map<long long, long long> um;

long long Calculate(long long num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> p >> q;
	um[0] = 1;
	cout << Calculate(n) << '\n';
}

long long Calculate(long long num)
{
	if (num == 0)
	{
		return 1;
	}

	if (um.find(num) != um.end())
	{
		return um[num];
	}

	return um[num] = Calculate(num / p) + Calculate(num / q);
}
