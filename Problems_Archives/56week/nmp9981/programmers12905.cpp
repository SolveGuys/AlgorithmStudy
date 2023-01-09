#include <iostream>
#include <vector>
using namespace std;

int row,col;//행,열 크기
int maxLen = 0;//정사각형 최대 길이
const int maxi = 1001;
int square[maxi][maxi];//정사각형 최대 길이

//max
int inline max(int x,int y){
    return x>y?x:y;
}
//min
int inline min(int x,int y){
    return x>y?y:x;
}
//초기화
void init(vector<vector<int>> board){
    row = board.size();col = board[0].size();//행,열 크기
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            square[i][j] = board[i][j];
            maxLen = max(maxLen,board[i][j]);
        }
    }
}
//넓이 구하기
int Area(vector<vector<int>> board){
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(board[i][j]==1){
                square[i][j] = 1+min(square[i-1][j-1],min(square[i][j-1],square[i-1][j]));
                maxLen = max(maxLen,square[i][j]);
            }
        }
    }
    return maxLen*maxLen;//넓이
}
int solution(vector<vector<int>> board)
{
    init(board);//초기화
    return Area(board);//넓이 구하기
}
