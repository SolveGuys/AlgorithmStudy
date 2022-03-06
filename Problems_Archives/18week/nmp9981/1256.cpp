#include <iostream>
using namespace std;
typedef unsigned long long ll;

ll n,m,k;
const int maxi = 201;
ll dp[maxi][maxi];//조합배열
ll sum[maxi];//경우의 수 합
bool select_z[maxi];//문자열

//조합
void combi(){
    dp[1][1] = 1;dp[1][0] = 1;
    for(int i=2;i<maxi;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || j==i){
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        }
    }
}

//사전 순서 구하기
void dict(){
    ll cur = m+n;
    for(int diff=m-1;diff>0;diff--){//개수차이
        ll cut = 0;
        for(int i=diff;i<cur;i++){//z가 자리잡는 경우의 수
            //z기록하기
            if(cut+dp[i][diff]>k){//z를 기록할 시점
                k-=cut;
                select_z[i+1] = true;
                cur = i+1;//다음 위치 갱신
                break;
            }else if(cut+dp[i][diff]==k){//zzzaa..aa
                for(int k=0;k<=diff;k++){
                    select_z[i+1-k] = true;
                }
                return;
            }else cut+=dp[i][diff];//누적
        }
    }
    select_z[k] = true;//마지막 z
}
//역순 출력
void output(){
    for(int i=m+n;i>=1;i--){
        if(select_z[i]==true) cout<<"z";
        else cout<<"a";
    }
}
int main(){
    ios_base::sync_with_stdio(0);//빠른 입력
    cin.tie(0);
    
    combi();//조합 구하기
    cin>>n>>m>>k;//입력
    if(dp[n+m][m]<k){//범위초과
        cout<<-1;
        return 0;
    }
    dict();//사전순서 구하기
    output();//출력
    return 0;
}
