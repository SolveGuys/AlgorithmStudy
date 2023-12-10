#include <iostream>
using namespace std;

const int maxi = 101;
string minDP[maxi] = { "0","0","1","7","4","2","6","8","10","18","22","20"};//최소
string maxDP[maxi] = { "0","0","1","7" };//최대

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//min
inline int min(int x, int y) {
    return x < y ? x : y;
}
//성냥개비
void Matchstick() {
    //최소
    for (int i = 12; i < maxi; i++) {
        minDP[i] = minDP[i - 7] + "8";
        if (i == 17) minDP[i] = "200";
    }
    //최대
    for (int i = 4; i < maxi; i++) maxDP[i] = maxDP[i - 2] + "1";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    Matchstick();//성냥개비
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        cout << minDP[n] << " " << maxDP[n] << "\n";
    }
    return 0;
}
