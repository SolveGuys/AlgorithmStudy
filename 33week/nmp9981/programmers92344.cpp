#include <string>
#include <vector>
using namespace std;

const int maxi = 1002;
int temp[maxi][maxi];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int row = board.size();//행의 길이
    int col = board[0].size();//열의 길이
    
    //진행
    for(int i=0;i<skill.size();i++){
        int degree = skill[i][5];
        if(skill[i][0]==1) degree*=-1;//공격일 경우
        //공격,회복의 시작, 종료지점 기록
        temp[skill[i][1]][skill[i][2]] += degree;
        temp[skill[i][1]][skill[i][4]+1] += -degree;
        temp[skill[i][3]+1][skill[i][2]] += -degree;
        temp[skill[i][3]+1][skill[i][4]+1] += degree;//두번 종료햇으므로 한번 +
    }
    //가로 누적합
    for(int i=0;i<=row;i++){
        for(int j=1;j<=col;j++) temp[i][j]+=temp[i][j-1];
    }
    //세로 누적합
    for(int i=1;i<=row;i++){
        for(int j=0;j<=col;j++) temp[i][j]+=temp[i-1][j];
    }
    //건물 개수 세기
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]+temp[i][j]>0) answer++;
        }
    }
    return answer;
}
