#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
#include<set>

using namespace std;

int t, n;

bool cmp(string &a, string &b)
{
	if ( a.size() == b.size() ) return a < b;
	return a.size() < b.size();
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	vector<string> res;
	for ( int T = 0; T < t; T++ )
	{
		cin >> n;
		set<string> sets;
		vector<string> strs(n);
		for ( int i = 0; i < n; i++ )
		{
			cin >> strs[i];
		}
		sort(strs.begin(), strs.end(), cmp);
		bool isCheck = false;
		for ( int i = 0; i < n; i++ )
		{
			string s = "";
			string ss = strs[i];
			for ( int j = 0; j < ss.size(); j++ )
			{
				s = s + ss[j];
				if ( sets.find(s) != sets.end() )
				{
					cout << "NO" << endl;
					isCheck = true;
					break;
				}
			}
			if ( isCheck )break;
			sets.insert(s);
		}
		if ( !isCheck ) cout << "YES" << endl;
	}

	return 0;
}