#include <iostream>
#include <unordered_map>

using namespace std;

struct Robot
{
	int x;
	int y;
	int dir;
};

int a, b, n, m;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
Robot robots[102];
unordered_map<char, int> dirs =
{
	{ 'N', 0 },
	{ 'E', 1 },
	{ 'S', 2 },
	{ 'W', 3 }
};

bool Simulate(int num, char cmd, int cnt);
bool IsCollidedByWall(int x, int y);
int IsCollidedByRobot(int num, int x, int y);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a >> b >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		char dir = 0;

		cin >> robots[i].x >> robots[i].y >> dir;
		robots[i].dir = dirs[dir];
	}

	bool isCollided = false;

	for (int i = 0; i < m; ++i)
	{
		int num = 0, cnt = 0;
		char cmd = 0;

		cin >> num >> cmd >> cnt;
		
		if (isCollided = Simulate(num, cmd, cnt))
		{
			break;
		}
	}

	if (!isCollided)
	{
		cout << "OK\n";
	}
}

bool Simulate(int num, char cmd, int cnt)
{
	bool isCollided = false;

	if (cmd == 'L')
	{
		cnt %= 4;
		robots[num].dir = (robots[num].dir - cnt + 4) % 4;
	}
	else if (cmd == 'R')
	{
		cnt %= 4;
		robots[num].dir = (robots[num].dir + cnt) % 4;
	}
	else
	{
		int nx = robots[num].x;
		int ny = robots[num].y;

		for (int i = 0; i < cnt; ++i)
		{
			nx += dx[robots[num].dir];
			ny += dy[robots[num].dir];

			if (IsCollidedByWall(nx, ny))
			{
				isCollided = true;
				cout << "Robot " << num << " crashes into the wall\n";
				break;
			}

			int collidedNum = IsCollidedByRobot(num, nx, ny);

			if (collidedNum != -1)
			{
				isCollided = true;
				cout << "Robot " << num << " crashes into robot " << collidedNum << '\n';
				break;
			}
		}

		robots[num].x = nx;
		robots[num].y = ny;
	}

	return isCollided;
}

bool IsCollidedByWall(int x, int y)
{
	return ((x < 1) || (x > a) || (y < 1) || (y > b));
}

int IsCollidedByRobot(int num, int x, int y)
{
	int collidedNum = -1;

	for (int i = 1; i <= n; ++i)
	{
		if (i == num)
		{
			continue;
		}

		if ((x == robots[i].x) && (y == robots[i].y))
		{
			collidedNum = i;
			break;
		}
	}

	return collidedNum;
}
