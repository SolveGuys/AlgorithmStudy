#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[26][26];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int visited[26][26];
stack<pair<int, int>> s;
vector<int> house_count;
int village;

int dfs(int startX, int startY){
    
    int cnt = 0;
    
    s.push({startX, startY});
    visited[startX][startY] = 1;
    cnt++;
    
    while(!s.empty()){
        auto [x, y] = s.top();
        s.pop();
        
        for(int i=0; i<4; i++){
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            
            if(nextX < 0 || nextY < 0 || nextX >= N || nextY >= N) continue;
            
            if(!visited[nextX][nextY] && map[nextX][nextY] == 1){
                visited[nextX][nextY] = 1;
                s.push({nextX, nextY});
                cnt++;
            }
        }
    }
    
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> s;
        for(int j=0; j<s.size(); j++){
            map[i][j] = s[j] - '0';
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j] && map[i][j] == 1){
                int cnt = dfs(i, j);
                house_count.push_back(cnt);
                village++;
            }
        }
    }
    
    std::sort(house_count.begin(), house_count.end(), less<int>());
    
    cout << village << '\n';
    for(int i=0; i<house_count.size(); i++){
        cout << house_count[i] << '\n';
    }
    
    return 0;
}
