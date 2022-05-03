#include <iostream>
#include <queue>
//	2284	0, iostream 대신 cstdio 쓰면 1492kb,	0ms

inline bool bInside(const int& now) 
{
	return !(now < 0 || now > 100000);
}

struct status 
{
	int location, time;
};

int main()
{
	int n, k;
	bool* bVisited = new bool[100'001]{false,};
	
	std::cin >> n >> k;

	std::queue<status> q;
	q.push({ n,0 });

	while(!q.empty())
	{
		int now = q.front().location;
		int time = q.front().time;
		q.pop();

		if (now == k)
		{
			std::cout << time;
			break;
		}

		if (bInside(now - 1) && !bVisited[now - 1])
        {
            bVisited[now - 1] = true;
            q.push({ now - 1, time + 1 });
        }
		if (bInside(now + 1) && !bVisited[now + 1])
        {
            bVisited[now + 1] = true;
            q.push({ now + 1, time + 1 });
        }
		if (bInside(now * 2) && !bVisited[now * 2])
        {
            bVisited[now * 2] = true;
            q.push({ now * 2 , time + 1});
        }

	}
	delete[] bVisited;

	return 0;
}

