#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<map>
#include<stack>
#include<set>

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

set<ii> s;
queue<iii> que;

int a, b, c, e;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c >> e;
	que.push({ 0,0,0 });
	while ( !que.empty() )
	{
		int x, y, d;
		tie(x, y, d) = que.front();
		que.pop();
		if ( s.find({ x,y }) != s.end() )continue;
		s.insert({ x,y });

		if ( x == c && y == e )
		{
			cout << d << endl;
			return 0;
		}
		
		que.push({ a,y,d + 1 });
		que.push({ x,b,d + 1 });
		if ( x > 0 )
		{
			que.push({ 0,y,d + 1 });
			if ( x + y <= b )
			{
				que.push({ 0,x + y,d + 1 });
			}
			else
			{
				int t = b - y;
				que.push({ x - t,b,d + 1 });
			}
		}
		if ( y > 0 )
		{
			que.push({ x,0,d + 1 });
			if ( x + y <= a )
			{
				que.push({ x+y, 0 ,d + 1 });
			}
			else
			{
				int t = a - x;
				que.push({ a,y-t,d + 1 });
			}
		}

		


	}
	cout << -1 << endl;
	return 0;
}