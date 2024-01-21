#include <iostream>
#include <vector>

using namespace std;

int T;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, c, target;
    cin >> T;

    // Test case
    while(T--){
        int dp[10005] = {0, };
        vector<int> coins;

        // input
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> c;
            coins.push_back(c);
        }
        cin >> target;
        
        // dp
        dp[0] = 1;
        for(int i=0; i<n; i++){
            for(int j=coins[i]; j<=target; j++){
                dp[j] += dp[j-coins[i]]; // coins[i]원을 가지고 j원 만들 수 있는 경우를 더해줌.
            }
        }
        
        cout << dp[target] << '\n';
    }
    
    
    return 0;
}
