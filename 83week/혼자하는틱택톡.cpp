#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> board) {
    int answer = -1;
    
    int onum = 0; int xnum = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == 'O') onum++;
            if(board[i][j] == 'X') xnum++;
        }
    }
    
    if(onum - xnum > 1 || onum - xnum < 0)
    {
        return 0;
    }
    
    
    //가로
    bool isT= false;
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
        {
            isT = true;
        }        
    }
    
    //세로
    bool isT1= false;
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
        {
            isT1 = true;
        }
    }
    
    //대각선
    bool isT2= false;
    if((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
    {
        isT2 = true;
    }
    
    //if((isT && isT1) || (isT && isT2) && (isT1 && isT2)) return 0;
    if(isT || isT1 || isT2) 
    {
        if(onum != xnum+1) return 0;
    }  
    
    
    //가로
    isT= false;
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
        {
            isT = true;

        }
        
    }

    //세로
    isT1= false;
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
        {
            isT1 = true;
        }
        
    }
    
    //대각선
    isT2= false;
    if((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X'))
    {
        isT2 = true;        
    }

    if(isT || isT1 || isT2) 
    {
        if(onum > xnum) return 0;
    } 

    
    answer = 1;
    return answer;
}
