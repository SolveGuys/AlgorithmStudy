#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<map>

using namespace std;

int m, n,T;
int res = 0;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	cin >> m >> n;
	vector<int> A(m);
	vector<int> B(n);
	map<int, int> A_map;
	for ( int i = 0; i < m; i++ )
	{
		cin >> A[i];
		if ( i > 0 )A[i] += A[i - 1];
	}
	for ( int i = 0; i < n; i++ )
	{
		cin >> B[i];
		if ( i > 0 ) B[i] += B[i - 1];
	}
	A_map[0]++;
	A_map[A[m - 1]]++;
	for ( int i = 0; i < m; i++ )
	{
		int cut;

		if ( i == 0 )
		{
			cut = 0;
		}
		else
		{
			cut = A[i - 1];
		}
		for ( int j = 0; j < m-1; j++ )
		{
			int tmp = 0;
			if ( i + j < m )
			{
				tmp = A[i + j] - cut;
			}
			else
			{
				tmp = A[m - 1] - cut;
				tmp += A[i + j - m];
			}
			A_map[tmp]++;

		}
	}
	for ( int i = 0; i < n; i++ )
	{
		int cut;

		if ( i == 0 )
		{
			cut = 0;
		}
		else
		{
			cut = B[i - 1];
		}
		for ( int j = 0; j < n - 1; j++ )
		{
			int tmp = 0;

			if ( i + j < n )
			{
				tmp = B[i + j] - cut;
			}
			else
			{
				tmp = B[n - 1] - cut;
				tmp += B[i + j - n];
			}
			if ( A_map.find(T - tmp) != A_map.end() )
			{
				res += A_map[T - tmp];
			}
		}	
	}
	res += A_map[T - B[n-1]];
	res += A_map[T];
	
	cout << res << endl;
	return 0;

}