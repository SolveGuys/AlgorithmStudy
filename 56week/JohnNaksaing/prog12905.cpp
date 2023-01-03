#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    int r = board.size();
    int c = board[0].size();
    
    if(r < 2 || c < 2) 
        return 1;
    
    for(int i = 1; i < r; i++)
    for(int j = 1; j < c; j++)
    {
        if(!board[i][j])
            continue;
        
        int& here = board[i][j];
        int& lfup = board[i-1][j-1];
        int& up = board[i-1][j];
        int& left = board[i][j-1];
        
        int smol = std::min(lfup,min(up,left));
        
        here = smol + 1;
        
        answer = max(answer,here);
    }
    
    if(answer == 0)
        return 0;
    else
        return answer * answer;
}