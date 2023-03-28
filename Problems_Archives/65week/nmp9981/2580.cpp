#include <iostream>
#include <vector>
using namespace std;

const int maxi = 9;
int sudoku[maxi][maxi];//스도쿠
int blankSize;
vector<pair<int,int>> blank;

//입력
void input(){
    for(int i=0;i<maxi;i++){
        for(int j=0;j<maxi;j++){
            cin>>sudoku[i][j];
            if(sudoku[i][j]==0) blank.push_back({i,j});
        }
    }
    blankSize = blank.size();
}
//열
bool col(int x,int y,int num){
    for(int j=0;j<maxi;j++){
        if(num==sudoku[x][j]) return false;
    }
    return true;
}
//행
bool row(int x,int y,int num){
    for(int i=0;i<maxi;i++){
        if(num==sudoku[i][y]) return false;
    }
    return true;
}
//박스
bool box(int x,int y,int num){
    int startX = (x/3)*3;
    int startY = (y/3)*3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(num==sudoku[startX+i][startY+j]) return false;
        }
    }
    return true;
}
//출력
void output(){
    for(int i=0;i<maxi;i++){
        for(int j=0;j<maxi;j++)cout<<sudoku[i][j]<<" ";
        cout<<"\n";
    }
}
//풀이
void solve(int idx){
    //빈칸 모두 채움
    if(idx==blankSize){
        output();//출력
        exit(0);//종료
    }
    //다움 숫자
    for(int k=1;k<=maxi;k++){
        int nx = blank[idx].first;
        int ny = blank[idx].second;
        if(!box(nx,ny,k)) continue;
        if(!col(nx,ny,k)) continue;
        if(!row(nx,ny,k)) continue;
        
        sudoku[nx][ny] = k;
        solve(idx+1);
        sudoku[nx][ny] = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    input();//입력
    solve(0);
    return 0;
}
