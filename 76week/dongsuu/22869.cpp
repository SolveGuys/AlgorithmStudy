#include <iostream>

using namespace std;

int N, K;
int arr[5001];
int dp[5001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    
    dp[1] = 1; // 시작지점(1)은 무조건 갈 수 있음
    
    // j -> i로 갈 수 있는지
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        
        for(int j=1; j<i; j++){
            if(dp[j] == 0) continue; // 해당 징검다리 못가는 경우는 패스
            if((i-j) * (1 + std::abs(arr[j] - arr[i])) <= K){ // 갈 수 있는 경우
                dp[i] = 1;
            }
        }
    }
    
    // Answer
    if(dp[N] == 1){
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    
    return 0;
}
