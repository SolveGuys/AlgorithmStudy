#include <bits/stdc++.h>

int n, m, k;
struct fireball
{
	int r, c, m, s, d;
    const static int dr[];
    const static int dc[];
    
	void move() 
	{
		r = (r + dr[d] * s) % n;
		c = (c + dc[d] * s) % n;
        
        if(r <= 0) r += n;
        if(c <= 0) c += n;
	}

	fireball(int r, int c, int m, int s, int d) :r(r), c(c), m(m), s(s), d(d) {}
};
			  // 0  1  2  3  4  5  6  7
const int fireball::dr[]{ -1,-1, 0, 1, 1, 1, 0,-1 };
const int fireball::dc[]{  0, 1, 1, 1, 0,-1,-1,-1 };

std::vector<fireball> map[51][51];
std::queue<fireball> fireballs;

void print_map()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			std::cout << map[i][j].size() << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << '\n';
}

void merge() 
{
	//for (auto fb : fireballs)
	while(!fireballs.empty())
	{
		auto fb = fireballs.front();
		map[fb.r][fb.c].push_back(fb);
		fireballs.pop();
	}

	for (int i = 1; i <= n; i++) 
	for (int j = 1; j <= n; j++)
	{
		if (map[i][j].size() < 1)
		{
			continue;
		}

		if (map[i][j].size() == 1) 
		{
			fireballs.push(map[i][j][0]);
		}
		else
		{
			//merge here
			int big_m = 0, big_s = 0;
			bool b_All_Even_or_Odd = true;
			bool bFirst = map[i][j][0].d % 2 == 0;
			int count = map[i][j].size();
			for (auto& fb : map[i][j])
			{
				big_m += fb.m;
				big_s += fb.s;

				//방향 체크
				b_All_Even_or_Odd &= ((fb.d % 2 == 0) == bFirst);
			}

			if (big_m / 5 > 0)
			{
				if (b_All_Even_or_Odd)
				{
					fireballs.push({ i, j, big_m / 5, big_s / count, 0 });
					fireballs.push({ i, j, big_m / 5, big_s / count, 2 });
					fireballs.push({ i, j, big_m / 5, big_s / count, 4 });
					fireballs.push({ i, j, big_m / 5, big_s / count, 6 });
				}
				else
				{
					fireballs.push({ i, j, big_m / 5, big_s / count, 1 });
					fireballs.push({ i, j, big_m / 5, big_s / count, 3 });
					fireballs.push({ i, j, big_m / 5, big_s / count, 5 });
					fireballs.push({ i, j, big_m / 5, big_s / count, 7 });
				}
			}
		}
		map[i][j].clear();
	}
}
int main() 
{
	
	std::cin >> n >> m >> k;
	//fireballs.resize(m);
	for (int i = 0; i < m; i++) 
	{
		int r, c, m, s, d;
		std::cin >> r >> c >> m >> s >> d;
		fireballs.push({ r,c,m,s,d });
		//std::cin >> fireballs[i].r >> fireballs[i].c >> fireballs[i].m >> fireballs[i].s >> fireballs[i].d;
	}

	for (int turn = 1; turn <= k; turn++)
	{
		//print_map();

		int qsize = fireballs.size();
		for (int i = 0; i < qsize; i++)
		{
			fireball fb = fireballs.front();
			fireballs.pop();
			fb.move();
			fireballs.push(fb);
		}

		//print_map();

		merge();

		//print_map();
	}

	int answer = 0;
	
	while(!fireballs.empty())
	{
		fireball fb = fireballs.front();
		answer += fb.m;
		fireballs.pop();
	}

	std::cout << answer;
	return 0;
}