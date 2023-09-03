#include <iostream>
#include <unordered_map>

typedef long long ll;
using namespace std;


ll N, P, Q;
unordered_map<ll, ll> map;

ll func(ll key){
    if(map[key] > 0){
        return map[key];
    }
    return map[key] = func(key/P) + func(key/Q);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> P >> Q;
    map[0] = 1;
    cout << func(N);
    
    return 0;
}