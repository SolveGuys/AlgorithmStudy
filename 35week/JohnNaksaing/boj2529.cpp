#include <bits/stdc++.h>
std::string to_num(int* board, int n) 
{
	std::string answer = "";
	int dec = 1;
	for (int i = 0; i < n+1; i++) 
	{
		{ answer += (char)(board[i] + '0'); }
	}

	return answer;
}
bool promising(int* board, bool* bLess, int n) 
{
	for (int k = 0; k < n ; k++)
	{
		if ( bLess[k] && (board[k] > board[k + 1])) // bLess[k] == '<'
		{
			return false;
		}
		if (!bLess[k] && (board[k] < board[k + 1])) // bLess[k] == '>'
		{
			return false;
		}
	}	
	return true;
}

int main()
{
	int* board;
	int* board_big;
	bool* bLess;

	int n;
	std::cin >> n;

	//00112
	// < >
	//8 9 1
	board = new int[n+1];
	board_big = new int[n+1];
	bLess = new bool[n];
	int answer = 0;

	char c;
	for (int i = 0; i < n; i++)
	{
		std::cin >> c;
		bLess[i] = c == '<';
		board[i] = i;
		board_big[i] = (9 - i);
	}
	board[n] = n, board_big[n] = (9 - n);
    
	std::string min;
	do 
	{
		if (promising(board, bLess, n))
		{
			min = to_num(board, n);
			break;
		}
	} while (std::next_permutation(board, board + n+1));


	std::string max;
	do
	{
		if (promising(board_big, bLess, n)) 
		{
			max = to_num(board_big, n);
			break;
		}
	} while (std::prev_permutation(board_big, board_big + n+1));

	std::cout << max << '\n' << min;

	delete[] board, board_big, bLess;
	return 0;
}