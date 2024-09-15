#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<map>
#include<stack>

using namespace std;
int m, n;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	vector<vector<int>> arr(m + 1, vector<int>(n + 1,0));
	vector<vector<int>> dp(m + 1, vector<int>(n + 1,0));
	vector<vector<vector<int>>> res(m + 1, vector<vector<int>>(n + 1, vector<int>()));
	for ( int i = 1; i < n + 1; i++ )
	{
		int t;
		cin >> t;
		for ( int j = 1; j < m + 1; j++ )
		{
			cin >> arr[j][i];
		}
	}

	for ( int i = 1; i < m + 1; i++ )
	{
		for ( int j = 0; j < n + 1; j++ )
		{
			int t;
			for ( int k = 0; k <= j; k++ )
			{
				if ( dp[i][j] <= dp[i - 1][j - k] + arr[i][k] )
				{
					dp[i][j] = dp[i - 1][j - k] + arr[i][k];
					t = k;
				}
			}
			vector<int> tmp = res[i - 1][j - t];
			tmp.push_back(t);
			res[i][j] = tmp;
		}
	}
	cout << dp[m][n]<<endl;
	for ( int i : res[m][n] )
	{
		printf("%d ", i);
	}
	cout << endl;
	return 0;
}