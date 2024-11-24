#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, L;
vector<int> gate;



bool check(const int &m)
{
	int cnt = 0;
	for ( int i = 1; i < gate.size(); i++ )
	{
		int diff = gate[i] - gate[i - 1];
		cnt += diff / m;
		if ( diff % m == 0 )cnt--;
	}
	return cnt > M;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> L;
	gate.resize(N);
	for ( int i = 0; i < N; i++ )
	{
		cin >> gate[i];
	}
	gate.push_back(0);
	gate.push_back(L);
	sort(gate.begin(), gate.end());
	int s = 1;
	int d = L;
	int res = 0;
	int m = 0;
	while ( s <= d )
	{
		m = (s + d) / 2;
		if ( check(m) )
		{
			s = m + 1;
		}
		else
		{
			d = m - 1;
			res = m;
		}

	}

	cout << res << endl;

	return 0;
}