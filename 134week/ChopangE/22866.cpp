#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<map>
#include<stack>
#include<set>
#include<cmath>

using namespace std;

typedef pair<int, int> ii;
int N;
vector<int> arr;
vector<ii> arr2;
vector<ii> arr3;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	arr.resize(N + 1);
	arr2.resize(N + 1);
	arr3.resize(N + 1);
	for ( int i = 1; i < N + 1; i++ )
	{
		cin >> arr[i];
	}

	arr2[1] = { 0,-1 };
	arr3[N] = { 0,-1 };
	for ( int i = 2; i < N + 1; i++ )
	{
		if ( arr[i] < arr[i - 1] )
		{
			arr2[i] = { arr2[i - 1].first + 1, i - 1 };
		}
		else
		{
			int t = arr2[i - 1].second;
			while ( t != -1 )
			{
				if ( arr[t] > arr[i] )
				{
					arr2[i] = { arr2[t].first + 1, t };
					break;
				}
				t = arr2[t].second;
			}
			if ( t == -1 )
			{
				arr2[i] = { 0,-1 };
			}
		}
	}
	for ( int i = N-1; i >= 1; i-- )
	{
		if ( arr[i] < arr[i + 1] )
		{
			arr3[i] = { arr3[i + 1].first + 1, i + 1 };
		}
		else
		{
			int t = arr3[i + 1].second;
			
			while ( t != -1 )
			{
				if ( arr[t] > arr[i] )
				{
					arr3[i] = { arr3[t].first + 1, t };
					break;
				}
				
				t = arr3[t].second;
			}
			if ( t == -1 )
			{
				arr3[i] = { 0,-1 };
			}
		}
	}
	
	for ( int i = 1; i < N + 1; i++ )
	{
		int sum = arr2[i].first + arr3[i].first;
		int t = arr2[i].second;
		if ( t == -1 )
		{
			t = arr3[i].second;
			
			if ( t == -1 )
			{
				printf("%d\n",sum);
			}
			else
			{
				printf("%d %d\n", sum, t);
			}
		}
		else
		{
			if ( arr3[i].second == -1 )
			{
				printf("%d %d\n", sum, arr2[i].second);
			}
			else
			{
				if ( i - arr2[i].second <= arr3[i].second - i )
				{
					t = arr2[i].second;
				}
				else t = arr3[i].second;
				printf("%d %d\n", sum, t);
			}

		}
	}
	
	return 0;
}