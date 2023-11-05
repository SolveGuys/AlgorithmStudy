#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string nations[4];
unordered_map<string, int> um;
int games[6][2]; // games[i][j]: i번째 게임은 games[i][0]와 games[i][1]의 대결
double rates[6][3]; // i번째 게임의 승부 확률, rates[i][0]: win, rates[i][1]: draw, rates[i][2]: lose
int scores[4];
double answer[4];

void DFS(int depth, double prob);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed;
	cout.precision(10);

	for (int i = 0; i < 4; ++i)
	{
		cin >> nations[i];
		um[nations[i]] = i;
	}

	for (int i = 0; i < 6; ++i)
	{
		string nat1, nat2;

		cin >> nat1 >> nat2 >> rates[i][0] >> rates[i][1] >> rates[i][2];
		games[i][0] = um[nat1];
		games[i][1] = um[nat2];
	}

	DFS(0, 1.0);

	for (int i = 0; i < 4; ++i)
	{
		cout << answer[i] << '\n';
	}
}

void DFS(int depth, double prob)
{
	if (depth == 6)
	{
		int firstScore = 0, secondScore = 0;
		vector<int> firstIndices, secondIndices;

		for (int i = 0; i < 4; ++i)
		{
			if (scores[i] > firstScore)
			{
				firstScore = scores[i];
				firstIndices.clear();
				firstIndices.push_back(i);
			}
			else if (scores[i] == firstScore)
			{
				firstIndices.push_back(i);
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			if (scores[i] == firstScore)
			{
				continue;
			}
			else if (scores[i] > secondScore)
			{
				secondScore = scores[i];
				secondIndices.clear();
				secondIndices.push_back(i);
			}
			else if (scores[i] == secondScore)
			{
				secondIndices.push_back(i);
			}
		}

		int n = static_cast<int>(firstIndices.size());
		int m = static_cast<int>(secondIndices.size());

		if (n == 1)
		{
			answer[firstIndices[0]] += prob;

			for (int i = 0; i < m; ++i)
			{
				answer[secondIndices[i]] += prob / m;
			}
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				answer[firstIndices[i]] += prob * 2.0 / n;
			}
		}

		return;
	}

	int nat1 = games[depth][0], nat2 = games[depth][1];
	double w = rates[depth][0], d = rates[depth][1], l = rates[depth][2];

	if (w > 0.0)
	{
		scores[nat1] += 3;
		DFS(depth + 1, prob * w);
		scores[nat1] -= 3;
	}

	if (d > 0.0)
	{
		++scores[nat1], ++scores[nat2];
		DFS(depth + 1, prob * d);
		--scores[nat1], --scores[nat2];
	}

	if (l > 0.0)
	{
		scores[nat2] += 3;
		DFS(depth + 1, prob * l);
		scores[nat2] -= 3;
	}
}
