#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,D,K,C;
vector<int> table;
vector<int> eat;
int ans;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
  
    // Input
    cin >> N >> D >> K >> C;
    for(int i=0; i<N; i++){
        cin >> num;
        table.push_back(num);
    }
    
    int st = 0;
    int en = 0;
    int sum = 0;

  // 투포인터
    while(1){
        if(st == table.size()) break; // exit

        // find answer
        if(sum == K){
            int cnt = 0;
            int visited[30001] = {0, };

          // 중복 제거해서 개수 count
            for(int i=st; i<en; i++){
                if(!visited[table[i%N]]){
                    visited[table[i%N]] = 1;
                    cnt++;
                }
            }
            if(!visited[C]) cnt++;
            ans = std::max(ans, cnt);
            
            eat.erase(eat.begin());
            st++;
            sum--;
        }

      // 먹은 초밥 개수가 K개 보다 작을 경우
        if(sum < K){
            eat.push_back(table[en%N]); // 환형이므로 %연산 필요.
            en++;
            sum++;
        } else { // 그 이상되면
            eat.erase(eat.begin());
            st++;
            sum--;
        }
    }
    
    cout << ans;
    
    
    
    return 0;
}
