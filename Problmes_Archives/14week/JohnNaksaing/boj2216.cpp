#include <iostream>
#include <vector>

int main() 
{
	int A,B,C;
	std::string str1, str2;

	std::cin >> A >> B >> C;
	std::cin >> str1 >> str2;

	std::vector<std::vector<int>> dp(str1.length()+1,std::vector<int>(str2.length()+1,0));

	for (int i = 1; i <= str1.length(); i++) 
	{
		dp[i][0] = dp[i - 1][0] + B;
	}
	for (int j = 1; j <= str2.length(); j++) 
	{
		dp[0][j] = dp[0][j - 1] + B;
	}

	for (int i = 1; i <= str1.length(); i++) 
	{
		for (int j = 1; j <= str2.length(); j++) 
		{
			char char1 = str1[i - 1];
			char char2 = str2[j - 1];
			
			int score;
			if (char1 == char2)
			{
				score = A + dp[i-1][j-1];
			}
			else //if(char1 != char2)
			{
				score = C + dp[i-1][j-1];
			}

			dp[i][j] = std::max(score, std::max(dp[i-1][j] + B,dp[i][j-1] + B));
		}
	}

	/*
	for (int i = 0; i <= str1.length(); i++)
	{
		for (int j = 0; j <= str2.length(); j++)
		{
			std::cout << dp[i][j] << ' ';
		}
		std::cout << '\n';
	}
	*/
	std::cout << dp[str1.length()][str2.length()];

	return 0;
}
