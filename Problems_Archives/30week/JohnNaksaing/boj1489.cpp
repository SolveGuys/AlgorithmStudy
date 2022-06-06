#include <bits/stdc++.h>
#include <bitset>
class _wheels 
{
	static const unsigned char clock_12 = 0x80;
	static const unsigned char clock_3 = 0x20;
	static const unsigned char clock_9 = 0x2;
	static const unsigned char clock_11 = 0x1;
private:
	unsigned char wheels[4]{0};
	bool visited[4]{false};
	bool valid_left(int idx);
	bool valid_right(int idx);
public:
	_wheels() 
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 8 - 1; j >= 0; j--)
			{
				int c;
				scanf("%1d",&c);
				wheels[i] |= (c << (j));
			}
		}
	}
	int get_score() 
	{
		int get = 0;
		for (int i = 0; i < 4; i++) 
		{
			get |= ((bool)(wheels[i] & clock_12)) << i;
		}
		return get; 
	}
	void spin(int idx, int dir);
	void print();
	void reset();
};
void _wheels::reset()
{
	memset(visited,false,sizeof(visited));
}
void _wheels::print()
{
	for (int i = 0; i < 4; i++)
		std::cout << std::bitset<8>(wheels[i]) << ' ';
	std::cout << '\n';
}

bool _wheels::valid_left(int idx) 
{
	if (idx == 0 )//|| visited[idx])
		return false;

	return (bool)(wheels[idx - 1] & clock_3) ^ (bool)(wheels[idx] & clock_9);
}

bool _wheels::valid_right(int idx) 
{
	if (idx == 3 )//|| visited[idx])
		return false;

	return (bool)(wheels[idx] & clock_3) ^ (bool)(wheels[idx + 1] & clock_9);
}

void _wheels::spin(int idx, int dir) 
{
	if (visited[idx])	return;

	bool bLeft = valid_left(idx);
	bool bRight = valid_right(idx);

	if (dir == 1) 
	{
		bool lsb = wheels[idx] & clock_11;
		wheels[idx] >>= 1;
		wheels[idx] |= (lsb << 7);
	}
	else if (dir == -1) 
	{
		bool msb = wheels[idx] & clock_12;
		wheels[idx] <<= 1;
		wheels[idx] |= (msb);
	}
    visited[idx] = true;

	if (bLeft)
		spin(idx - 1, dir * -1);
	if (bRight)
		spin(idx + 1, dir * -1);
}

int main()
{
	_wheels wheels;
	int k;
	scanf("%d",&k);
	while (k--) 
	{
		wheels.reset();
		int idx, dir;
		scanf("%d %d",&idx,&dir);

		wheels.spin(idx-1, dir);
	}
	printf("%d",wheels.get_score());
	return 0;
}