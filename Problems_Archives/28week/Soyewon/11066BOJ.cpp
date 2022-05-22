// BOJ 11066. 파일 합치기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, K; // T : 테스트 데이터 개수 / K : 파일의 크기
const int MAX = 501;
const int DPMAX = 10000000; // 파일 전체 최대 크기들의 합보다 더 커야함. 합치는 비용까지 고려
int file[MAX]; // k 내부 파일들 각각의 크기
int sum[MAX]; // sum[i] : 1~i까지의 파일 크기 합
int dp[MAX][MAX]; // dp[i][j] : i에서 j 구간까지의 최소 합치는 비용

void input()
{
	cin >> T;

	while (T--)
	{
		cin >> K;
		for (int i = 1; i <= K; i++)
		{
			cin >> file[i];
			sum[i] = sum[i - 1] + file[i];
		}
	}
}

int main()
{
	input();

	for (int i = 1; i <= K; i++)
	{
		for (int j = 1; j <= K - i; j++)
		{
			dp[j][i + j] = DPMAX;
			for (int k = j; k < i + j; k++)
			{
				// 최소비용 + 합치는데 필요한 비용(구간 내 모든 파일들의 크기합)
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
			}
		}
	}

	cout << dp[1][K] << endl;

}
