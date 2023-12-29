#include <iostream>
#include <string>

using namespace std;

int answer;
int n, k, p;
string x;
const int leds[] =
{
	0b011'1111, // 0
	0b000'1100, // 1
	0b111'0110, // 2
	0b101'1110, // 3
	0b100'1101, // 4
	0b101'1011, // 5
	0b111'1011, // 6
	0b000'1110, // 7
	0b111'1111, // 8
	0b101'1111, // 9
};

void DFS(int depth, int cnt, string& cur);
int Compare(int st, int en);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k >> p >> x;

	// 남은 자리수는 모두 0으로 채운다.
	string cur = string(k - x.length(), '0') + x;

	DFS(0, p, cur);
	cout << answer - 1 << '\n'; // 모두 그대로 둬서 cur가 x와 동일한 경우를 빼주어야 한다.
}

void DFS(int depth, int cnt, string& cur)
{
	if (depth == k)
	{
		int num = stoi(cur);

		if ((1 <= num) && (num <= n))
		{
			++answer;
		}

		return;
	}

	int idx = cur[depth] - '0';
	char tmp = cur[depth];

	for (int i = 0; i < 10; ++i)
	{
		if (idx == i)
		{
			DFS(depth + 1, cnt, cur);
		}
		else
		{
			int newCnt = cnt - Compare(idx, i);

			if (newCnt >= 0)
			{
				cur[depth] = i + '0';
				DFS(depth + 1, newCnt, cur);
				cur[depth] = tmp;
			}
		}
	}
}

int Compare(int st, int en)
{
	int cnt = 0;
	int mixed = leds[st] ^ leds[en]; // XOR: 같으면 0, 다르면 1

	while (mixed > 0)
	{
		if (mixed & 1)
		{
			++cnt;
		}

		mixed >>= 1;
	}

	return cnt;
}
