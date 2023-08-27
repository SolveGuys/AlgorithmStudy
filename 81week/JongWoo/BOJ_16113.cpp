#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n;
string signal;

unordered_map<string, char> um =
{
	{ "####.##.##.####", '0' },
	{ "###..#####..###", '2' },
	{ "###..####..####", '3' },
	{ "#.##.####..#..#", '4' },
	{ "####..###..####", '5' },
	{ "####..####.####", '6' },
	{ "###..#..#..#..#", '7' },
	{ "####.#####.####", '8' },
	{ "####.####..####", '9' }
};

char Decode(int& idx);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	cin >> signal;

	string answer;
	int len = n / 5;

	for (int i = 0; i < len; ++i)
	{
		if (signal[i] == '#')
		{
			answer.push_back(Decode(i));
		}
	}

	cout << answer << '\n';
}

char Decode(int& idx)
{
	string num;
	int len = n / 5;

	for (int i = 0; i < 5; ++i)
	{
		num += signal.substr(len * i + idx, 3);
	}

	if (um.find(num) == um.end())
	{
		++idx;
		return '1';
	}

	idx += 3;
	return um[num];
}
