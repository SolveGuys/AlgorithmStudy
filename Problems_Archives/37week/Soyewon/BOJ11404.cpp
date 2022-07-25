#include <iostream>
#include <algorithm>

using namespace std;

int n, m; // 도시 개수와 버스 수
int cost[101][101]; // 비용
const int INF = 987654321; // 경로가 없을 경우를 위해 최대한 큰 숫자로 설정

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				cost[i][j] = INF;
			} // 최대값으로 초기화
			else
				cost[i][j] = 0;// 출발지와 도착지가 같을 때 
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cost[a][b] = min(cost[a][b], c); // 중복되는 루트의 경우 이전 저장값이 더 크다면 새로운 비용으로 갱신
	}
}

void floyd()
{
	for (int k = 1; k <= n; k++) // 경유지 k
		for (int i = 1; i <= n; i++) // 출발지점 i
			for (int j = 1; j <= n; j++) // 도착지점 j
			{
				if (i == j) continue;
				else
				{
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
				}
			}

}

int main()
{
	input();
	floyd();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (cost[i][j] == 987654321) // 경로가 없을 시
				cout << "0 "; // 0 출력
			else
				cout << cost[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
