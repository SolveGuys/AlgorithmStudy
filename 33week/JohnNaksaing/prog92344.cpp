#include <string>
#include <vector>
#include <iostream>
using namespace std;
//int g_board[1001][1001];
int g_sum[1002][1002];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    for(auto& vec : skill)
    
    {   //vec : [type, r1, c1, r2, c2, degree]
        int type = vec[0], r1 = vec[1], c1 = vec[2], r2 = vec[3], c2 = vec[4], degree = vec[5] * (type == 2?1:-1);
        
        //cout << type << ' ' << r1 << ' ' << c1 <<' ' <<  r2 << ' ' << c2 << ' ' <<  degree << '\n';
        
        //한 줄에 쓰면 레퍼런스가 아니라 값으로 대입되는 것 같다.
        int& left_up = g_sum[r1][c1];
        int& right_up = g_sum[r1][c2+1];
        int& left_down = g_sum[r2+1][c1];
        int& right_down = g_sum[r2+1][c2+1];
        
        left_up     += degree,  right_up -= degree; 
        left_down   -= degree,  right_down += degree;
    }
    for(int i = 1; i < board.size(); i++)
    for(int j = 0; j < board[0].size(); j++)
    {
        g_sum[i][j] += g_sum[i-1][j]; 
    }
    for(int i = 0; i < board.size(); i++)
    for(int j = 1; j < board[0].size(); j++)
    {
        g_sum[i][j] += g_sum[i][j-1]; 
    }
    for(int i = 0; i < board.size(); i++)
    for(int j = 0; j < board[0].size(); j++)
    {
        if(g_sum[i][j] + board[i][j] > 0)
            answer++;
    }
    return answer;
}