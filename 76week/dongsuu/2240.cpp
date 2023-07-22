#include <iostream>
#include <algorithm>

using namespace std;

int T, W;
int dp[1001][3][31]; // [time][location][w]
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> T >> W;
    
    for(int i=1; i<=T; i++){
        cin >> num;
        for(int j=0; j<=W; j++){
            if(j == 0){ // 첫 번째는 이전 움직임 고려 X, 시작은 무조건 1번
                dp[i][1][j] = dp[i-1][1][j] + ((num == 1) ? 1 : 0);
            } else {
                // (이전에 움직이지 않고 , 현재 사과가 내가 있는 곳에 떨어지는가?) , (이전에 움직이고, 현재 사과가 내가 있는 곳에 떨어지는가?)
                dp[i][1][j] = std::max(dp[i-1][1][j] + ((num == 1) ? 1 : 0), dp[i-1][2][j-1] + ((num == 1) ? 1 : 0));
                dp[i][2][j] = std::max(dp[i-1][2][j] + ((num == 2) ? 1 : 0), dp[i-1][1][j-1] + ((num == 2) ? 1 : 0));
            }
            
            ans = std::max(dp[i][1][j], dp[i][2][j]);
        }
        
    }
    
    cout << ans;
    
    
    
    return 0;
}
