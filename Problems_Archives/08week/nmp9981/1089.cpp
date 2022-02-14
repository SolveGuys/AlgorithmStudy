#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <set>

using namespace std;//이름공간 선언

int n,row_size;
string board[5];//전광판
vector<int> num[9];//나올 수 있는 숫자
bool is_possi = true;//평균을 구할 수 있는가?
//0~9까지의 숫자
string number[10][5] = {
    {"###","#.#","#.#","#.#","###"},
    {"..#","..#","..#","..#","..#"},
    {"###","..#","###","#..","###"},
    {"###","..#","###","..#","###"},
    {"#.#","#.#","###","..#","..#"},
    {"###","#..","###","..#","###"},
    {"###","#..","###","#.#","###"},
    {"###","..#","..#","..#","..#"},
    {"###","#.#","###","#.#","###"},
    {"###","#.#","###","..#","###"}
};
            
//입력
void input(){
    //입력
    cin>>n;
    row_size = 4*n-1;
    for(int i=0;i<5;i++){
        //string으로 정의했으므로 각 줄을 한번에 입력
        cin>>board[i];
    }
}

//전광판 숫자
void board_num(){
    //벡터에 넣기
    for(int idx=0;idx<n;idx++){//벡터 순서
        string digit[5][3];//숫자판 1개
        for(int i=0;i<5;i++){
            for(int j=0;j<3;j++){
                digit[i][j] = board[i][4*idx+j];
            }
        }
        
        //나올수 없는 숫자를 제거
        bool chk[10];//나올 수 있는 숫자인가?
        memset(chk,true,sizeof(chk));
        
        //영역 탐색
        for(int i=0;i<5;i++){
            for(int j=0;j<3;j++){
                //#으로 나올 수 없는 숫자를 가려냄
                if(digit[i][j] =="#"){
                    //0~9까지 검사
                    for(int k=0;k<=9;k++){
                        //#위치에 .이 있으면 나올 수 없는 숫자
                        if(number[k][i][j] =='.'){
                            chk[k] = false;
                        }
                    }
                }
            }
        }
        //가능한 숫자를 넣기
        int cnt = 0;
        for(int k=0;k<=9;k++){
            if(chk[k]==true){
                num[idx].push_back(k);
                cnt++;//숫자 개수
            }
        }
        //가능한 숫자의 개수가 없다면
        if(cnt==0){
            is_possi = false;
            return;
        }
    }
}

//평균 구하기
double board_average(){
    double total = 0;//평균
    for(int i=0;i<n;i++){
        int sum = 0;//각 자릿수의 합
        for(int j=0;j<num[i].size();j++){
            sum+=num[i][j];//각 자릿수의 합 구하기
        }
        //각 자릿수의 평균을 누적해줌
        total += ((double)sum/(double)num[i].size())*pow(10,n-1-i);//총합 구하기
    }
    return total;
}

int main(){
    //빠른 입출력
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();//입력
    board_num();//전광판 숫자
    if(is_possi==true){//평균을 구할 수 있는가?
        printf("%.5lf",board_average());//상대오차 10^-5까지
    }else{
        cout<<-1;
    }
    return 0;
}
