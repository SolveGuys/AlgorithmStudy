#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<string>
#include<limits>
 
using namespace std;

int N, mp, mf, ms, mv;

struct Node
{
	int p, f, s, v, c;
};
int total = 1000000;

vector<Node> arr;
vector<int> tmp;
vector<int> res;
void Check()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int sum = 0;
	for ( int i = 0; i < tmp.size(); i++ )
	{
		Node &t = arr[tmp[i]];
		a += t.p;
		b += t.f;
		c += t.s;
		d += t.v;
		sum += t.c;
	}
	if ( a >= mp && b >= mf && c >= ms && d >= mv )
	{
		if ( sum < total )
		{
			res = tmp;
			total = sum;
		}
		else if ( sum == total )
		{
			if ( res.size() < tmp.size() )
			{
				for ( int i = 0; i < res.size(); i++ )
				{
					if ( tmp[i] < res[i] )
					{
						res = tmp;
						break;
					}
					else if ( tmp[i] > res[i] )
					{
						break;
					}
				}
			}
			else if ( res.size() > tmp.size() )
			{
				bool isCheck = false;
				for (int i = 0; i < tmp.size(); i++ )
				{
					if ( tmp[i] < res[i] )
					{
						res = tmp;
						isCheck = true;
						break;
					}
					else if ( res[i] < tmp[i] )
					{
						isCheck = true;
						break;
					}
				}
				if ( isCheck == false )
				{
					res = tmp;
				}
				
			}
			
			
		}
	}
}


void Select(int idx)
{
	if ( idx == N )
	{
		Check();
		return;
	}
	for ( int i = 0; i < 2; i++ )
	{
		if ( i == 0 )
		{
			tmp.push_back(idx);
			Select(idx + 1);
			tmp.pop_back();
		}
		else
		{
			Select(idx + 1);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	arr.resize(N);
	cin >> mp >> mf >> ms >> mv;
	for ( int i = 0; i < N; i++ )
	{
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		arr[i].p = a;
		arr[i].f = b;
		arr[i].s = c;
		arr[i].v = d;
		arr[i].c = e;
	}
	Select(0);
	if ( total == 1000000 )
	{
		cout << -1 << endl;
		return 0;
	}
	cout << total << endl;
	for ( int x : res )
	{
		cout << x + 1<< " ";
	}
	
	cout << endl;
	return 0;
}