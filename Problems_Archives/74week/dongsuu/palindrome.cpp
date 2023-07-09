#include <iostream>
#include <string>
using namespace std;

int dp[2505][2505]; // [구간][시작점]

int solution(string s)
{
    int answer=0;
    
    for(int i=0; i<=s.size(); i++){
        // 구간 1인 경우 -> 모두 팰린드롬
        dp[1][i] = 1;
        answer = 1;
        
        if(s[i] == s[i-1]){
            // 구간 2인 경우 -> 이전 수와 같으면 팰린드롬
            dp[2][i-1] = 1;
            answer = 2;
        }
    }
    
    // 구간 3인 경우 -> 시작점과 끝점 같고, 그 사이 부분도 팰린드롬이면 팰린드롬이다.
    for(int i=3; i<=s.size(); i++){
        for(int j=0; j<=s.size()-i; j++){
            if(s[j] == s[i+j-1] && dp[i-2][j+1]){
                dp[i][j] = 1;
                answer = i;
            }
        }
    }
    

    return answer;
}
