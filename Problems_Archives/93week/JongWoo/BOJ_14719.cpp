#include <iostream>
#include <stack>

using namespace std;

int h, w;
int heights[502];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> h >> w;

	int maxIndex = 0;

	for (int i = 0; i < w; ++i)
	{
		cin >> heights[i];

		if (heights[i] > heights[maxIndex])
		{
			maxIndex = i;
		}
	}

	int answer = 0;
	stack<int> stk;

	stk.push(0);

	for (int i = 1; i < maxIndex; ++i)
	{
		if (heights[i] > heights[stk.top()])
		{
			stk.pop();
			stk.push(i);
		}

		answer += heights[stk.top()] - heights[i];
	}

	stk.pop();
	stk.push(w - 1);

	for (int i = w - 2; i > maxIndex; --i)
	{
		if (heights[i] > heights[stk.top()])
		{
			stk.pop();
			stk.push(i);
		}

		answer += heights[stk.top()] - heights[i];
	}

	cout << answer << '\n';
}
