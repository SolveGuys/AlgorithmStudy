#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;

void DFS(int n, int depth, const string& exp);
int Parse(const string& exp);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n = 0;

		cin >> n;
		DFS(n, 1, "1");
		sort(answer.begin(), answer.end());

		for (const string& a : answer)
		{
			cout << a << '\n';
		}

		cout << '\n';
		answer.clear();
	}
}

void DFS(int n, int depth, const string& exp)
{
	if (depth == n)
	{
		if (Parse(exp) == 0)
		{
			answer.push_back(exp);
		}

		return;
	}

	string num = to_string(depth + 1);

	DFS(n, depth + 1, exp + '+' + num);
	DFS(n, depth + 1, exp + '-' + num);
	DFS(n, depth + 1, exp + ' ' + num);
}

int Parse(const string& exp)
{
	int tot = 0;
	string num;
	char op = '+';

	for (int i = 0; i < exp.length(); ++i)
	{
		if ((exp[i] == '+') || (exp[i] == '-'))
		{
			tot += ((op == '+') ? stoi(num) : -stoi(num));
			op = exp[i];
			num.clear();
		}
		else if (isdigit(exp[i]))
		{
			num.push_back(exp[i]);
		}
	}

	tot += ((op == '+') ? stoi(num) : -stoi(num));

	return tot;
}
