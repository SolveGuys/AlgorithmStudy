#include <iostream>
#include <string>

using namespace std;

// ABAC, BBACD
//   A B A C
// B 0 1 0 0
// B 0 1 0 0
// A 1 0 2 0
// C 0 0 0 3
// D 0 0 0 0
// => 3

string str1, str2;
int dp[4002][4002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> str1 >> str2;

	// 계산에 편의를 위해 문자열의 가장 앞에 공백을 추가하여 인덱스가 1부터 시작하도록 만든다.
	str1 = ' ' + move(str1);
	str2 = ' ' + move(str2);

	int answer = 0;
	int n = static_cast<int>(str1.length());
	int m = static_cast<int>(str2.length());

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			if (str1[i] == str2[j])
			{
				if (str1[i - 1] == str2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = 1;
				}

				answer = max(answer, dp[i][j]);
			}
		}
	}

	cout << answer << '\n';
}
