#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsGameOver(const vector<string>& board, char turn);

int solution(vector<string> board)
{
    int answer = 1;
    int oCnt = 0, xCnt = 0;
    
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            switch (board[i][j])
            {
                case 'O':
                    ++oCnt;
                    break;
                case 'X':
                    ++xCnt;
                    break;
            }
        }
    }
    
    if ((xCnt > oCnt) || (oCnt - xCnt > 1))
    {
        answer = 0;
    }
    else
    {
        int diff = oCnt - xCnt;

        if (IsGameOver(board, 'O'))
        {
            if (diff != 1)
            {
                answer = 0;
            }
        }
        
        if (IsGameOver(board, 'X'))
        {
            if (diff != 0)
            {
                answer = 0;
            }
        }
    }
    
    return answer;
}

bool IsGameOver(const vector<string>& board, char turn)
{
    for (int i = 0; i < 3; ++i)
    {
        // 가로, 세로
        if (((board[i][0] == turn) && ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))) ||
            ((board[0][i] == turn) && ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))))
        {
            return true;
        }
        
        // 대각선
        if (((board[1][1] == turn) && ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))) ||
            ((board[1][1] == turn) && ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))))
        {
            return true;
        }
    }
    
    return false;
}
