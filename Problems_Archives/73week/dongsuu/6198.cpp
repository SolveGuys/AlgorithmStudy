#include <iostream>
#include <stack>

using namespace std;

typedef long long ll;

int N;
stack<ll> buildings;
ll ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll height;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> height;
        if(i == 0 || buildings.empty()){
            buildings.push(height);
            continue;
        }
        
        while(!buildings.empty() && buildings.top() <= height){
            buildings.pop();
        }
        ans += buildings.size();
        buildings.push(height);
    }
    
    cout << ans;
    
    
    return 0;
}
