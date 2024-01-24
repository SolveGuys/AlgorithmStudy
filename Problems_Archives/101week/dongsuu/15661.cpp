#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>

using namespace std;

int N;
int ability[21][21];
bool isSelected[21];
int eachTeamCount;
int minDiff = INT_MAX;

void func(int cnt, int idx){
    if(cnt >= 1){
        // 각 팀 세팅
        vector<int> teamA;
        vector<int> teamB;
        int sumA = 0;
        int sumB = 0;
        for(int i=0; i<N; i++){
            if(isSelected[i]){
                teamA.push_back(i);
            } else {
                teamB.push_back(i);
            }
        }
        
        // 각 팀 점수 계산
        for(int i=0; i<teamA.size() - 1; i++){
            for(int j=i+1; j<teamA.size(); j++){
                sumA += (ability[teamA[i]][teamA[j]] + ability[teamA[j]][teamA[i]]);
            }
        }
        
        for(int i=0; i<teamB.size() - 1; i++){
            for(int j=i+1; j<teamB.size(); j++){
                sumB += (ability[teamB[i]][teamB[j]] + ability[teamB[j]][teamB[i]]);
            }
        }
        
        // 최소 차이 갱신
        int diff = std::abs(sumA - sumB);
        minDiff = std::min(minDiff, diff);
    }
    if(cnt == eachTeamCount) return ;
    
    for(int i=idx; i<N; i++){
        if(!isSelected[i]){
            isSelected[i] = true;
            func(cnt+1, i+1);
            isSelected[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    eachTeamCount = N / 2;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> ability[i][j];
        }
    }
    
    func(0, 0);
    
    cout << minDiff;
    
    
    return 0;
}
