#include <iostream>
#include <algorithm>

using namespace std;

int k;
int states[6];
bool isVisited[6];

void Simulate(int num, int dir);
void Rotate(int num, int dir);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			char c = 0;

			cin >> c;
			
			if (c == '1')
			{
				states[i] |= (1 << j);
			}
		}
	}

	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		int num = 0, dir = 0;

		cin >> num >> dir;
		Simulate(num, dir);
		fill(isVisited, isVisited + 6, false);
	}

	int answer = 0, base = 1;

	for (int i = 1; i <= 4; ++i)
	{
		if (states[i] & 1)
		{
			answer += base;
		}

		base *= 2;
	}

	cout << answer << '\n';
}

void Simulate(int num, int dir)
{
	isVisited[num] = true;

	int left = num - 1;
	int right = num + 1;

	if ((left >= 1) && (!isVisited[left]))
	{
		int pole = (states[num] & (1 << 6)) >> 6;
		int leftPole = (states[left] & (1 << 2)) >> 2;

		// 극이 다른 경우에만 연쇄적으로 움직인다.
		if (pole != leftPole)
		{
			Simulate(left, -dir);
		}
	}
	
	if ((right <= 4) && (!isVisited[right]))
	{
		int pole = (states[num] & (1 << 2)) >> 2;
		int rightPole = (states[right] & (1 << 6)) >> 6;

		// 극이 다른 경우에만 연쇄적으로 움직인다.
		if (pole != rightPole)
		{
			Simulate(right, -dir);
		}
	}

	Rotate(num, dir);
}

void Rotate(int num, int dir)
{
	switch (dir)
	{
	case 1: // 시계 방향
	{
		int lastBit = states[num] & (1 << 7);

		states[num] <<= 1;

		if (lastBit > 0)
		{
			states[num] |= 1;
		}
	}
		break;
	case -1: // 반시계 방향
	{
		int firstBit = states[num] & 1;

		states[num] >>= 1;

		if (firstBit > 0)
		{
			states[num] |= (1 << 7);
		}
	}
		break;
	}
}
