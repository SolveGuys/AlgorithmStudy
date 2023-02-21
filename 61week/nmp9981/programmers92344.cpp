#include <string>
#include <vector>
using namespace std;

int row,col;
const int maxi = 1001;
int temp[maxi][maxi];//내구도 변화량

//스킬 사용
void Skill(vector<vector<int>>& skill){
    int skillSize = skill.size();
    for(int i=0;i<skillSize;i++){
        int degree = skill[i][5];
        if(skill[i][0]==1) degree*=-1;//공격
        
        temp[skill[i][1]][skill[i][2]]+=degree;
        temp[skill[i][1]][skill[i][4]+1]-=degree;
        temp[skill[i][3]+1][skill[i][2]]-=degree;
        temp[skill[i][3]+1][skill[i][4]+1]+=degree;
    }
}
//누적합
void Csum(vector<vector<int>>& board){
    row = board.size();col = board[0].size();
    //가로 방향
    for(int i=0;i<row;i++){
        for(int j=1;j<col;j++) temp[i][j]+=temp[i][j-1];
    }
    //세로 방향
    for(int i=1;i<row;i++){
        for(int j=0;j<col;j++) temp[i][j]+=temp[i-1][j];
    }
}
//건물 개수
int NotDestroy(vector<vector<int>>& board){
    int cnt = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]+temp[i][j]>0) cnt++;
        }
    }
    return cnt;
}
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    Skill(skill);//스킬 사용
    Csum(board);//누적합
    return NotDestroy(board);//파괴되지 않은 건물 개수
}
