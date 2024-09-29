#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<map>
#include<stack>
#include<set>

using namespace std;

int N;
vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	
	arr.resize(N);
	
	for ( int i = 0; i < N; i++ )
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	if ( arr[0] != 1 )
	{
		cout << 1 << endl;
		return 0;
	}
	int max_num = arr[0];
	for ( int i = 1; i < N; i++ )
	{
		if ( arr[i] - 1 <= max_num )
		{
			max_num += arr[i];
		}
		else
		{
			cout << max_num + 1 << endl;
			return 0;
		}
	}

	cout << max_num + 1 << endl;

	return 0;
}