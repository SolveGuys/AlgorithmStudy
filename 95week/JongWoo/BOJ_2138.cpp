#include <iostream>
#include <string>

using namespace std;

const int INF = 100'001;

int n;
string init, target;

int Simulate(bool isOn);
void SwitchOn(string& cur, int idx);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> init >> target;

	int answer = INF;

	answer = min(Simulate(true), Simulate(false));

	if (answer == INF)
	{
		answer = -1;
	}

	cout << answer << '\n';
}

int Simulate(bool isOn)
{
	int ret = 0;
	string cur(init);

	if (isOn)
	{
		SwitchOn(cur, 0);
		++ret;
	}

	for (int i = 1; i < n; ++i)
	{
		if (cur[i - 1] != target[i - 1])
		{
			SwitchOn(cur, i);
			++ret;
		}
	}

	if (cur != target)
	{
		ret = INF;
	}

	return ret;
}

void SwitchOn(string& cur, int idx)
{
	if (idx - 1 >= 0)
	{
		cur[idx - 1] = '0' + ('1' - cur[idx - 1]);
	}

	cur[idx] = '0' + ('1' - cur[idx]);

	if (idx + 1 < n)
	{
		cur[idx + 1] = '0' + ('1' - cur[idx + 1]);
	}
}
