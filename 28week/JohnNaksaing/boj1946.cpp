#include <iostream>
#include <vector>

const int INF = 987'654'321;

inline void solve() 
{
	int n;
	std::cin >> n;
	std::vector<int> score_2s(n);

	for (int i = 0; i < score_2s.size(); i++)
	{
		int idx, score2;
		std::cin >> idx >> score2;
		score_2s[idx-1] = score2;
	}
	int highest_score2 = INF;
	int cnt = 0;
	for (int i = 0; i < score_2s.size(); i++) 
	{
		if (highest_score2 > score_2s[i])
			highest_score2 = score_2s[i], cnt++;
	}
	std::cout << cnt << '\n';
}
int main() 
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int T;
	std::cin >> T;
	while (T--) 
	{
		solve();
	}
	
	return 0;
}