#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, K;
int arr[601][601];

// compare
bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second < p2.second) return true;
    else if(p1.second > p2.second) return false;
    else {
        return p1.first < p2.first;
    }

}

// R연산
int operateR(int r, int c){
    int max_col = 0;
    
    for(int i=0; i<r; i++){
        vector<pair<int, int>> v;
        int temp[101] = {0, };
        // 나온 수 개수 count
        for(int j=0; j<c; j++){
            temp[arr[i][j]]++;
        }
        
        // 해당 수가 몇 번 나왔는지 Pair로 저장
        for(int j=1; j<101; j++){
            if(temp[j] > 0){
                v.push_back({j, temp[j]});
            }
        }
        
        // 정렬
        std::sort(v.begin(), v.end(), comp);
        
        // 할당
        int idx = 0;
        for(int k=0; k<v.size(); k++){
            arr[i][k+idx] = v[k].first;
            arr[i][k+1+idx] = v[k].second;
            idx++;
        }
        
        // 할당 후 남은 곳들은 0으로
        for(int k=v.size()*2; k<101; k++)
            arr[i][k] = 0;
        
        // 최대 column 수 계산
        max_col = std::max(max_col, (int) v.size()*2);
    }
    
    return max_col;
    
}

// C연산
int operateC(int r, int c){
    int max_row = 0;
    
    for(int i=0; i<c; i++){
        int temp[101] = {0, };
        vector<pair<int, int>> v;
        for(int j=0; j<r; j++){
            temp[arr[j][i]]++;
        }
        
        for(int j=1; j<101; j++){
            if(temp[j] > 0){
                v.push_back({j, temp[j]});
            }
        }
        std::sort(v.begin(), v.end(), comp);
        
        int idx = 0;
        for(int k=0; k<v.size(); k++){
            arr[k+idx][i] = v[k].first;
            arr[k+idx+1][i] = v[k].second;
            idx++;
        }
        
        for(int k=v.size()*2; k<101; k++)
            arr[k][i] = 0;
        
        max_row = std::max(max_row, (int) v.size()*2);
    }
    
    return max_row;
}

void print(int r, int c){
    cout << "=======================" << endl;
    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    
    cout << endl;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C >> K;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }
    
    int time = 0;
    int max_row = 3;
    int max_col = 3;
    
    while(1){
        if(arr[R-1][C-1] == K) break;
        if(time > 100){
            time = -1;
            break;
        }
        
        // R연산
        if(max_row >= max_col){
            max_col = std::max(operateR(max_row, max_col), max_col);
//            print(max_row, max_col);
        } else {
            // C연산
            max_row = std::max(max_row, operateC(max_row, max_col));
//            print(max_row, max_col);
        }
        
        time++;
    }
    
    cout << time;
    
    return 0;
}
