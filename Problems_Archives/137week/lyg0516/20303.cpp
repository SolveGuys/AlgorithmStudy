#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int getParent(int n, vector<int>& parents){
    
    if(n == parents[n])
        return n;
    return parents[n]  = getParent(parents[n], parents);
}

void unionParent(int n1, int n2, vector<int>& parents){
    if(getParent(n1, parents) > getParent(n2, parents)){
        parents[getParent(n1, parents)] = getParent(n2, parents);
        return;
    }
    parents[getParent(n2, parents)] = getParent(n1, parents);
}

int main(){
    int N, M, K, tmp, tmp1, tmp2;
    vector<int> candies(1, 0);
    vector<int> parents(1, 0);
    unordered_map<int, pair<int,int>> candiesAndNumberAtParent;
    vector<pair<int,int>> canidesNumberVector(1, {0,0});

    cin >> N >> M >> K;
    
    for(int i = 1; i <= N; i++){
        cin >> tmp;
        candies.push_back(tmp);
        parents.push_back(i);
    }
    
    for(int i = 0; i < M; i++){
        cin >> tmp1 >> tmp2;
        unionParent(tmp1, tmp2, parents);
    }

    for(int  i = 1; i <= N; i++){
        if(candiesAndNumberAtParent.find(getParent(i, parents)) == candiesAndNumberAtParent.end())
            candiesAndNumberAtParent[getParent(i, parents)] = {1 ,candies[i]};
        else{
            tmp1 = candiesAndNumberAtParent[getParent(i ,parents)].first;
            tmp2 = candiesAndNumberAtParent[getParent(i, parents)].second;
            candiesAndNumberAtParent[getParent(i, parents)] = {tmp1 + 1, tmp2 + candies[i]};
        }
    }
    for(auto p: candiesAndNumberAtParent){
        canidesNumberVector.push_back({p.second.first, p.second.second});
    }
    vector<vector<int>> dp(canidesNumberVector.size() + 1,vector<int>(K + 1 , 0) );
    for(int i = 1; i < canidesNumberVector.size(); i++){
        for(int j = 1; j < K; j++ ){
            if(j < canidesNumberVector[i].first){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            else{
                dp[i][j] = max(max(dp[i - 1][j - canidesNumberVector[i].first] + canidesNumberVector[i].second, dp[i-1][j]), dp[i][j-1]);
            }
        }
    }
    cout << dp[canidesNumberVector.size()-1][K-1];

    return 0;
}
