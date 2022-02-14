#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void RotateKey(std::vector<std::vector<int>>& key)
{
	const int M = key.size();

	std::vector<std::vector<int>> key_ref = key;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			key[i][j] = key_ref[M -1 - j][i];
		}
	}
}

//key를 lock[x][y]부터 출발
bool bFit(
    const vector<vector<int>>& key,
    vector<vector<int>> board,
    int x_offset, int y_offset // key offset
    , int N
){

    const int M = key.size(); 
    const int B = board.size();

    for(int i = x_offset; (i < M-1+N) && (i < M+x_offset); i++)
    for(int j = y_offset; (j < M-1+N) && (j < M+y_offset); j++)
    {
        board[i][j] += key[i-x_offset][j-y_offset];
    }

    for(int i = M-1; i < M-1+N; i++)
    for(int j = M-1; j < M-1+N; j++)
    {
        if(board[i][j]!=1) return false;
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    int M = key.size(); 
    int N = lock.size(); //M은 항상 N 이하입니다.
    
    int B = M + 2 * (N - 1);
    vector<vector<int>> board(B,vector<int>(B,0));
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            board[i + M-1][j + M-1] = lock[i][j];
        }
    }
    
    for(int dir = 0; dir < 4; dir++)
    {
        //i,j = key offset
        for(int i = 0; i < N+M-1; i++)
        for(int j = 0; j < N+M-1; j++)
        {
            
            if(bFit(key,board,i,j,N)) return true;
        }
        
        RotateKey(key);
    }
    
    return false;
}