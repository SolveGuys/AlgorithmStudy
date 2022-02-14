#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;//이름공간 선언

const int maxi = 100001;
vector<int> A;//입력 순서
int dp[5][5][maxi];//왼발, 오른발, 인덱스

//입력
void input(){
	while(true){
	    int x;
	    cin>>x;//수열 입력
	    if(x==0){
	        break;//입력종료
	    }else{
	        A.push_back(x);
	    }
	}
}

//에너지
int energe(int now, int next){
    if(now==0){//중앙시작
        return 2;
    }else if(now==next){//같으면
        return 1;
    }else if(abs(now-next)==2){//정반대
        return 4;
    }
    return 3;
} 

//댄스게임(재귀를 사용)
int play(int i,int j, int idx){
    if(idx==A.size()){//종료조건
        return 0;
    }
    //점화식
    if(dp[i][j][idx]!=-1){
        return dp[i][j][idx];
    }
    int left = play(A[idx],j,idx+1) + energe(i,A[idx]);//왼쪽
    int right = play(i,A[idx],idx+1) + energe(j,A[idx]);//오른쪽
    dp[i][j][idx] = min(left,right);//더 작은값
    return dp[i][j][idx];
}

int main(){
    //빠른 입출력
    ios::sync_with_stdio(false);

    input();//입력
    memset(dp,-1,sizeof(dp));//초기화
    cout<<play(0,0,0);//댄스게임
    return 0;
}
