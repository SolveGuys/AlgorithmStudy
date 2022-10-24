#include <string>
#include <vector>
typedef long long ll;
using namespace std;
const int maxi = 5001;
const ll mod = 1000000007;
ll dp[maxi];//타일경우의 수

//타일 배치
void tile(){
    dp[2] = 3;dp[0] = 1;//초기값
    for(int i=4;i<maxi;i+=2){
        dp[i] = 3*dp[i-2];
        for(int j=i-4;j>=0;j-=2) dp[i]+=(2*dp[j]);
        dp[i]%=mod;//mod로 나눈 나머지
    }
}
int solution(int n) {
    ll answer = 0;
    if(n%2==0) {//짝수일 경우만 설치 가능
        tile();//타일 배치
        answer = dp[n];
    }
    return answer;
}
