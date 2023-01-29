#include <bits/stdc++.h>
const int NOT_YET = -1;

char dp[101];
std::string g_str;
std::vector<std::string> g_dictionary;
int words_count;

//dp[n]을 계산해서 반환
bool is_DP_able_at(int n)
{
	char& b_DPable = dp[n];
	
    // 계산 완료 : 그대로 반환
	if (b_DPable != NOT_YET)
		return b_DPable;

    // 기저 케이스 : 기본값으로 반환
	if (n == 0)
	{
		b_DPable = true;
		return b_DPable;
	}

	b_DPable = false;
	for(std::string& word : g_dictionary)
	{

		// 1. 이번 word가 너무 김
		if (n - (int)word.size() < 0)
			continue;

		// 2. g_str - word는 되는데, word 갖다붙였을 때 다름
		std::string slice = g_str.substr(n - (int)word.size(), word.size());
		if (slice != word)
			continue;

		// 3. g_str - word 만큼이 이미 false
		if (!is_DP_able_at(n - (int)word.size()))
			continue;
		
		b_DPable = true;
		break;
	}

	return b_DPable;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);
		
	std::cin >> g_str;	
    
	std::cin >> words_count;	
	g_dictionary.resize(words_count);
	
    for (int i = 0; i < words_count; i++)
		std::cin >> g_dictionary[i];

	memset(dp, NOT_YET, sizeof(char) * (g_str.size() + 1));
	
	bool b = is_DP_able_at(g_str.size());
	std::cout << b;

	return 0;
}