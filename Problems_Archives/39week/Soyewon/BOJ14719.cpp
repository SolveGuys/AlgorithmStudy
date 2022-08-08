#include <iostream>
#include <algorithm>

#define MAX 501

using namespace std;


int h, w; // 세로길이 h, 가로길이 w
int height[MAX]; // 각 가로 당 블럭높이
int res = 0; // 총 빗물 양

void rain()
{
	int leftMax;
	int rightMax;

	for (int i = 2; i < w; i++)
	{
		leftMax = height[i];
		rightMax = height[i];

		for (int j = 1; j < i; j++) // 좌측 블록 최대높이 구하기
		{
			leftMax = max(leftMax, height[j]);
		}

		for (int j = i + 1; j <= w; j++)
		{
			rightMax = max(rightMax, height[j]); // 우측 블록 최대높이 구하기
		}

		res += ( min(leftMax, rightMax)-height[i] ); // 빗물 최대 높이 구하기
	}

	cout << res;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h >> w;
	for (int i = 1; i <= w; i++)
	{
		cin >> height[i];
	}

	rain();
	return 0;
}
