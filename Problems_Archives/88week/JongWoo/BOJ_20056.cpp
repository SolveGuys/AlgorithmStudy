#include <iostream>
#include <queue>

using namespace std;

struct FireBall
{
	int x;
	int y;
	int mass;
	int speed;
	int dir;
};

int n, m, k;
queue<FireBall> board[52][52];
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;

	queue<FireBall> q;

	for (int i = 0; i < m; ++i)
	{
		int x = 0, y = 0, m = 0, s = 0, d = 0;

		cin >> x >> y >> m >> s >> d;
		q.push({ x, y, m, s, d });
	}

	for (int i = 0; i < k; ++i)
	{
		while (!q.empty())
		{
			FireBall fb = q.front();

			q.pop();

			int shiftX = (fb.speed * dx[fb.dir]) % n + n;
			int shiftY = (fb.speed * dy[fb.dir]) % n + n;

			fb.x = (fb.x + shiftX - 1) % n + 1;
			fb.y = (fb.y + shiftY - 1) % n + 1;
			board[fb.x][fb.y].push(fb);
		}

		for (int x = 1; x <= n; ++x)
		{
			for (int y = 1; y <= n; ++y)
			{
				int siz = static_cast<int>(board[x][y].size());

				if (siz == 0)
				{
					continue;
				}
				else if (siz == 1)
				{
					q.push(board[x][y].front());
					board[x][y].pop();
				}
				else
				{
					int totMass = 0, totSpeed = 0;
					bool isOdd = true, isEven = true;

					while (!board[x][y].empty())
					{
						bool flag = board[x][y].front().dir % 2 == 0;

						isOdd &= (board[x][y].front().dir % 2 == 1);
						isEven &= (board[x][y].front().dir % 2 == 0);
						totMass += board[x][y].front().mass;
						totSpeed += board[x][y].front().speed;
						board[x][y].pop();
					}

					totMass /= 5;

					if (totMass == 0)
					{
						continue;
					}

					totSpeed /= siz;

					if ((isOdd) || (isEven))
					{
						for (int i = 0; i < 8; i += 2)
						{
							q.push({ x, y, totMass, totSpeed, i });
						}
					}
					else
					{
						for (int i = 1; i < 8; i += 2)
						{
							q.push({ x, y, totMass, totSpeed, i });
						}
					}
				}
			}
		}
	}

	int answer = 0;

	while (!q.empty())
	{
		answer += q.front().mass;
		q.pop();
	}

	cout << answer << '\n';
}
