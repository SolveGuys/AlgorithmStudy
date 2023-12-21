#include <iostream>
#include <queue>

using namespace std;

const int MAX = 202;

int n, k;
int st, en; // 올리는 위치, 내리는 위치
int cnt; // 내구도가 0인 칸의 개수
int durabilities[MAX]; // 내구도
queue<int> robots; // 로봇이 있는 컨베이어 벨트의 인덱스
bool onRobot[MAX]; // 로봇이 있는 컨베이어 벨트 여부

void Rotate();
void Move();
void Put();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	st = 1, en = n;

	for (int i = 1; i <= 2 * n; ++i)
	{
		cin >> durabilities[i];
	}

	int answer = 0;

	while (cnt < k)
	{
		++answer;

		Rotate();
		Move();
		Put();
	}

	cout << answer << '\n';
}

void Rotate()
{
	--st, --en;

	if (st < 1)
	{
		st = 2 * n;
	}

	if (en < 1)
	{
		en = 2 * n;
	}
}

void Move()
{
	int qSize = static_cast<int>(robots.size());

	for (int i = 0; i < qSize; ++i)
	{
		int cur = robots.front();

		onRobot[cur] = false;
		robots.pop();

		if (cur == en)
		{
			continue;
		}

		int nxt = cur % (2 * n) + 1;

		if ((!onRobot[nxt]) && (durabilities[nxt] >= 1))
		{
			--durabilities[nxt];

			if (durabilities[nxt] == 0)
			{
				++cnt;
			}

			if (nxt == en)
			{
				continue;
			}

			onRobot[nxt] = true;
			robots.push(nxt);
		}
		else
		{
			onRobot[cur] = true;
			robots.push(cur);
		}
	}
}

void Put()
{
	if ((!onRobot[st]) && (durabilities[st] >= 1))
	{
		--durabilities[st];

		if (durabilities[st] == 0)
		{
			++cnt;
		}

		onRobot[st] = true;
		robots.push(st);
	}
}
