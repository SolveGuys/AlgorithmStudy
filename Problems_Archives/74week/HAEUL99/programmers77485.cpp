#include <string>
#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;
int board[102][102];
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int cnt = 1;
    for(int i = 1; i < rows + 1; i++)
    {
        for(int j = 1; j < columns + 1; j++)
        {
            board[i][j] = cnt++;
        }
    }
    
    for(int k = 0; k < queries.size(); k++)
    {
        int curx = queries[k][0];
        int cury = queries[k][1];
        int curx1 = queries[k][2];
        int cury1 = queries[k][3];

        int tmp1 = board[curx][cury1];
        int tmp2 = board[curx1][cury];
   
        for(int j = cury1; j > cury; j--)
        {
            board[curx][j] = board[curx][j-1];
    
        }
        
        for(int j = cury; j < cury1; j++)
        {
            board[curx1][j] = board[curx1][j+1];
  
        }
    
        for(int i = curx; i < curx1; i++)
        { 
            if(i == curx1 - 1) board[i][cury] = tmp2;
            else board[i][cury] = board[i+1][cury];
        
        }
        
        for(int i = curx1; i > curx; i--)
        {
            if(i == curx + 1) board[i][cury1] = tmp1;
            else board[i][cury1] = board[i-1][cury1];
     
        }

        int mn = INT_MAX;
        for(int j = cury; j <= cury1; j++)
        {
            mn = min(mn, board[curx][j]);
        }
        
        for(int j = cury; j <= cury1; j++)
        {
            mn = min(mn, board[curx1][j]);
        }
        
        for(int i = curx; i <= curx1; i++)
        {
            mn = min(mn, board[i][cury]);
        }
        
        for(int i = curx; i <= curx1; i++)
        {
            mn = min(mn, board[i][cury1]);
        }
            
        answer.push_back(mn);
        
    }
    
    return answer;
}

