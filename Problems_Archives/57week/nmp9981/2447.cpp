#include <iostream>
using namespace std;

int n;
//패턴
void Pattern(int num,int x,int y) {
    if ((x / num) % 3 == 1 && (y / num) %3== 1) cout << " ";//가운데 빈 공간
    else if (num / 3 == 0) cout << "*";
    else Pattern(num / 3, x, y);
    return;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;//입력
    //패턴
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) Pattern(n, i, j);
        cout << "\n";
    }
    return 0;
}
