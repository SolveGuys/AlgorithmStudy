#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<map>
#include<stack>

using namespace std;

typedef pair<int, int> ii;

int N,d;
vector<ii> arr;
vector<ii> res;
vector<int> mx;
vector<int>	mn;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	arr.resize(N);
	int min_ = 1e9;
	for ( int i = 0; i < N; i++ )
	{
		int a, b;
		cin >> a >> b;
		if ( b < a )
		{
			
			arr[i].first = b;
			arr[i].second = a;
		}
		else
		{
			
			arr[i].first = a;
			arr[i].second = b;
		}
	}
	cin >> d;
	for ( int i = 0; i < N; i++ )
	{
		if ( arr[i].second - arr[i].first <= d )
		{
			mx.push_back(arr[i].second);
			mn.push_back(arr[i].first);
		}
	}
	sort(mn.begin(), mn.end());
	sort(mx.begin(), mx.end());
	int total = 0;
	for ( int i = 0; i < mn.size(); i++ )
	{
		int left = mn[i];
		auto iter1 = lower_bound(mn.begin(), mn.end(), left);
		int l_idx = iter1 - mn.begin();
		int right = left + d;
		auto iter2 = upper_bound(mx.begin(), mx.end(), right);
		int r_idx = iter2 - mx.begin();
		total = max(total, r_idx - l_idx);
	}
	cout << total << endl;
	return 0;
}