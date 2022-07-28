#include <iostream>
int map[10][10];
int paper[6] {0,5,5,5,5,5};

int answer = 1e9;

void search(int i, int j, int count);

void fill(int i, int j, int size, bool cover) 
{
	for (int x = i; x < i + size; x++) 
	for (int y = j; y < j + size; y++)
	{
		map[x][y] = cover;
	}	
}

bool check(int i, int j, int size)
{
	bool bHit = (paper[size] - 1) >= 0;
	for (int x = i; x < i + size && bHit; x++)
	for (int y = j; y < j + size && bHit; y++)
	{
		bHit &= x >= 0 && x < 10 && y < 10 && x >= 0 && map[x][y];
	}
	return bHit;
}

int main()
{
	for (int i = 0; i < 10; i++)
	for (int j = 0; j < 10; j++)
	{
		std::cin >> map[i][j];
	}

	search(0,0,0);

	if (answer == 1e9)
	{
		std::cout << "-1";
	}
	else
	{
		std::cout << answer;
	}
	return 0;
}

void search(int i, int j, int count) 
{
	//all cleared
	if (i > 9 && j > 9) 
	{
		answer = std::min(answer,count);
		return;
	}
	
	//no use
	if (count > answer)
		return;

	if (j > 9)
	{
		search(i+1, 0, count);
		return;
	}

	if (map[i][j]) 
	{
		for (int size = 5; size > 0; size--) 
		{
			if (check(i,j,size)) 
			{
				fill(i, j, size, false);
				paper[size]--;
				
				search(i,j+1,count+1);
			
				fill(i, j, size, true);
				paper[size]++;
			}
		}
	}
	else 
	{
		search(i,j+1,count);
	}
}