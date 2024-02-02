#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
vector<int> alpha[26];
int answer = 0x3fffffff;

void DFS(int idx, int cursor, int tot);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;

	for (int i = 0; i < s.length(); ++i)
	{
		alpha[s[i] - 'a'].push_back(i);
	}

	int cursor = 0;

	for (int i = 0; i < 26; ++i)
	{
		if (!alpha[i].empty())
		{
			// i: 현재 처리해야할 문자의 인덱스(a: 0, b: 1, ...)
			// alpha[i].back(): 현재 처리해야할 문자의 마지막 위치
			// alpha[i].back() + alpha[i].size(): 현재 처리해야할 문자의 마지막 위치까지 이동 + 현재 처리할 문자를 만날 때마다 누른 엔터키의 횟수
			// 초기 커서는 0에 있으므로 현재 처리해야할 문자의 마지막 위치로 이동하여 모든 문자를 처리한다.
			cursor = static_cast<int>(alpha[i].back());
			DFS(i, cursor, cursor + alpha[i].size());
			break;
		}
	}

	cout << answer << '\n';
}

void DFS(int idx, int cursor, int tot)
{
	// 'z'까지 처리했다면 더이상 처리할 알파벳이 존재하지 않으므로 tot 값 갱신
	if (idx == 26)
	{
		answer = min(answer, tot);
		return;
	}

	for (int i = idx + 1; i < 26; ++i)
	{
		if (alpha[i].empty())
		{
			continue;
		}

		int front = alpha[i].front();
		int back = alpha[i].back();
		int diff = back - front;
		int toFront = abs(front - cursor);
		int toBack = abs(back - cursor);

		if (diff == 0)
		{
			DFS(i, back, tot + toFront + diff + alpha[i].size());
		}
		else
		{
			// 현재 처리해야할 문자의 가장 앞까지 이동하며 모든 문자 처리 -> 현재 처리해야할 문자의 가장 뒤까지 이동하며 모든 문자 처리
			// => 최종적인 커서는 back에 위치
			// => 이동 횟수: 앞까지 이동 횟수 + 앞에서 뒤까지 이동 횟수 + 현재 처리해야할 문자를 만날 때마다 누른 엔터키의 횟수
			DFS(i, back, tot + toFront + diff + alpha[i].size());

			// 현재 처리해야할 문자의 가장 뒤까지 이동하며 모든 문자 처리 -> 현재 처리해야할 문자의 가장 앞까지 이동하며 모든 문자 처리
			// => 최종적인 커서는 front에 위치
			// => 이동 횟수: 뒤까지 이동 횟수 + 뒤에서 앞까지 이동 횟수 + 현재 처리해야할 문자를 만날 때마다 누른 엔터키의 횟수
			DFS(i, front, tot + toBack + diff + alpha[i].size());
		}

		return;
	}

	// 문자열을 구성하는 가장 마지막 문자가 'z'가 아닌 경우 현재 깊이에서 더이상 DFS 탐색을 진행하지 않기 때문에 return 되지 않고 여기까지 진입
	// => 이때도 answer 값을 갱신
	answer = min(answer, tot);
}
