#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1'000;

struct Node
{
	int screen;
	int clipBoard;
	int t;
};

int s;
bool isVisited[MAX + 1][MAX + 1]; // isVisited[screen][clipBoard]

int BFS(int st);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	cout << BFS(1) << '\n';
}

int BFS(int st)
{
	int ret = 0x3ffffff;
	queue<Node> q;

	isVisited[st][0] = true;
	q.push({ st, 0, 0 });

	while (!q.empty())
	{
		Node cur = q.front();

		q.pop();

		if (cur.screen == s)
		{
			ret = cur.t;
			break;
		}

		// 1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
		if ((cur.screen > 0) && (!isVisited[cur.screen][cur.screen]))
		{
			isVisited[cur.screen][cur.screen] = true;
			q.push({ cur.screen, cur.screen, cur.t + 1 });
		}

		// 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
		if ((cur.clipBoard > 0) && (cur.screen + cur.clipBoard <= MAX) && (!isVisited[cur.screen + cur.clipBoard][cur.clipBoard]))
		{
			isVisited[cur.screen + cur.clipBoard][cur.clipBoard] = true;
			q.push({ cur.screen + cur.clipBoard, cur.clipBoard, cur.t + 1 });
		}

		// 3. 화면에 있는 이모티콘 중 하나를 삭제한다.
		if ((cur.screen - 1 >= 1) && (!isVisited[cur.screen - 1][cur.clipBoard]))
		{
			isVisited[cur.screen - 1][cur.clipBoard] = true;
			q.push({ cur.screen - 1, cur.clipBoard, cur.t + 1 });
		}
	}

	return ret;
}
