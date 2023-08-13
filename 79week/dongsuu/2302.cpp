#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

ll N, M;
ll seat[42]; // 좌석 (일반: 0, vip: 1)
ll dp[42]; // dp[i] : vip석 사이의 일반 자리 i개 있을 때 가능한 경우의 수
vector<int> counts; // vip ___ vip (vip석 사이에 있는 일반 자리 개수)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // Input
    ll vip;
    cin >> N >> M;
    seat[0] = 1; seat[N+1] = 1; // 양 끝값 vip석으로 초기화
    for(int i=0; i< M; i++){
        cin >> vip;
        seat[vip] = 1; // vip석은 1로 세팅
    }
    
    int cnt = 0; // vip석 ____ vip석 에서 ____의 개수
    int maxCount = -1; // 좌석번호에 관계없이 vip석 사이의 수 만 동일하면 같은 값을 가질 것이므로 최대 수로만 계산하여 나머지는 memo 활용
    for(int i=1; i<=N+1; i++){
        if(seat[i] == 0){ // vip석 사이의 개수 세기
            cnt++;
        }
        else if(seat[i] == 1){ // 끝 vip석 나오면 cnt를 counts 벡터에 넣어주고, cnt최대값 갱신, cnt초기화 진행
            counts.push_back(cnt);
            maxCount = std::max(maxCount, cnt);
            cnt = 0;
        }
    }
    
    dp[0] = 1; // 모두 vip석이 나올 수 있으므로(vip석 사이에 count가0) dp[0]를 0으로 초기화
    dp[1] = 1; // vip _ vip => 1가지
    dp[2] = 2; // vip __ vip => 2가지
    // 최대 수로 dp 계산
    for(int i=3; i<=maxCount; i++){
        dp[i] = dp[i-1] + dp[i-2]; // vip석 사이에 i개 좌석일 때 가능한 자리 경우의 수
    }
    
    
    ll result = 1;
    for(int i=0; i<counts.size(); i++){ // vip석 사이 개수를 counts에 담아뒀고, dp계산도 다 되어있을테니 다 곱해주면 총 경우의 수가 나옴.
        result *= dp[counts[i]];
    }
    
    cout << result;
    
    
    return 0;
}

