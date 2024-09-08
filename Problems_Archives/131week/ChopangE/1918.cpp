#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<map>
#include<stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	stack<char> sta;


	cin >> str;
	vector<char> res;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (sta.empty() || sta.top() == '(')
			{
				sta.push(str[i]);
			}
			else
			{
				res.push_back(sta.top());
				sta.pop();
				i--;
			}
		}
		else if (str[i] == '/' || str[i] == '*')
		{
			if (sta.empty() || (sta.top() != '/' && sta.top() != '*'))
			{
				sta.push(str[i]);
			}
			else
			{
				res.push_back(sta.top());
				sta.pop();
				i--;
			}
		}
		else if (str[i] == '(')
		{
			sta.push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (sta.top() == '(')
			{
				sta.pop();
			}
			else
			{
				res.push_back(sta.top());
				sta.pop();
				i--;
			}
		}
		else
		{
			res.push_back(str[i]);
		}
	}

	while (!sta.empty())
	{
		res.push_back(sta.top());
		sta.pop();
	}

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
	}
	cout << endl;
	return 0;

}