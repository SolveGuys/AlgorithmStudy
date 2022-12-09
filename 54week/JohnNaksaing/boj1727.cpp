
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);
	int n, m;
	std::cin >> n >> m;

	std::vector<int> men(n+1);

	for(int i = 1; i <= n; i++)
		std::cin >> men[i];

	std::sort(men.begin(),men.end());

	std::vector<int> women(m+1);
	for (int i = 1; i <= m; i++)
		std::cin >> women[i];
	std::sort(women.begin(),women.end());

	//map[i][j] : man i만큼, woman j만큼 짝짓기 했을 때 최소 성격차.
	std::vector<std::vector<int>> map(n+1, std::vector<int>(m+1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = map[i - 1][j - 1] + std::abs(men[i] - women[j]);

			if (i > j)
			{
				map[i][j] = std::min
				(
					map[i][j],
					map[i - 1][j]
				);
			}
			else if (i < j)
			{
				map[i][j] = std::min
				(
					map[i][j],
					map[i][j - 1]
				);
			}
		}
	}
	std::cout << map[n][m];
	return 0;
}