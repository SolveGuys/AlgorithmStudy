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

using namespace std;//이름공간 선언

const int maxi = 2001;
int n,m,s,e;
int A[maxi];//수열
int dp[maxi][maxi];//i~j까지가 팰린드롬인가?

//팰린드롬인가?
void palindrom(){
    //초기값
    for(int i=1;i<=n;i++){
        dp[i][i] = 1;//수 1개면 팰린드롬
    }
    
    //이웃한 2개
    for(int i=1;i<n;i++){
        if(A[i]==A[i+1]){//두수가 같으면
            dp[i][i+1] = 1;
        }else{//두수가 다르면
            dp[i][i+1] = 0;
        }
    }
    
    //점화식
    for(int s=2;s<n;s++){//사이즈
        for(int i=1;i<=n-s;i++){//시작지점
            int j = i+s;//끝지점
            //시작과 끝지점이 같고 사이가 팰린드롬이라면
            if(A[i]==A[j] && dp[i+1][j-1]==1){
                dp[i][j] = 1;//팰린드롬
            }else{
                dp[i][j] = 0;//팰린드롬이 아님
            }
        }
    }
}

//입력
void input(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
}

//질문
void question(){
    //빠른 입출력
    cin.tie(0);
    cout.tie(0);
    
    cin>>m;
    //팰린드롬인가?
    for(int i=0;i<m;i++){
        cin>>s>>e;
        cout<<dp[s][e]<<"\n";
    }
}

int main(){
    //빠른 입출력
    ios::sync_with_stdio(false);
    
    input();//입력
    palindrom();//팰린드롬 여부 조사
    question();//팰린드롬인가?
    return 0;
}
