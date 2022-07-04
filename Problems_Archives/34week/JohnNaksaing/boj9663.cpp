#if 0

#include<stdio.h>
int a[]={1,1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596,2279184};
main(int N){scanf("%d",&N);printf("%d",a[N]);}

#endif

#include <iostream>

void print(int* board, int n, int here)
{
    std::cout << here << ": ";
    for (int i = 0; i < n; i++)
        std::cout << board[i] << ' ';

    std::cout << '\n';
}

bool promising(int i, int* board)
{
    bool bValid = true;

    for (int k = 0; k < i && bValid; k++)
    {
        if (board[i] == board[k] || (std::abs(board[i] - board[k]) == i - k))
            bValid = false;
    }
    return bValid;
}

void dfs(int here, int* board, int n, int& answer)
{
    if (here == n)
    {
        //print(board,n, here);
        answer++;
        return;
    }
    for (int j = 0; j < n; j++)
    {
        board[here] = j;
        if (promising(here, board))
        {
            dfs(here + 1, board, n, answer);
        }
    }
}

int main()
{
    int* board;
    int n;
    std::cin >> n;

    board = new int[n];
    int answer = 0;
    for (int i = 0; i < n; i++) 
    {
        board[i] = -1;
    }
    dfs(0, board, n, answer);

    std::cout << answer;

    delete[] board;
    return 0;
}