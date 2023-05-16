#include <iostream>
using namespace std;

int n,m,a,b;
const int maxi = 21;
string board[maxi];//보드판
int minCost = 2100000000;

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n>>m;
    cin >> a >> b;
    for (int i = 0; i < n; i++) cin >> board[i];
}
//ㄷ영역인가?
bool isDigeut(int i,int j,int r,int c,int len) {
    if (j >= c && j < c + 3 * len && i >= r && i < r + len) return true;//위
    else if (j >= c && j < c + len && i >= r + len && i < r + 2 * len) return true;//가운데
    else if (j >= c && j < c + 3 * len && i >= r + 2 * len && i < r + 3 * len) return true;//아래
    return false;
}
//ㄷ덮기
int CoverDigeut(int r,int c,int len) {
    int cost = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isDigeut(i, j, r, c, len)) {
                if (board[i][j] == '.') cost += a;//흰->검
            }
            else {
                if (board[i][j] == '#') cost += b;//검->흰
            }
        }
    }
    return cost;
}
//ㄷ만들기
void MakeDigeut() {
    //사이즈
    for (int k = 1; k <= 6; k++) {
        if (min(n, m) < 3 * k) continue;//범위 초과
        //시작 지점
        for (int i = 0; i <= n-3*k; i++) {
            for (int j = 0; j <= m-3*k; j++) minCost = min(minCost, CoverDigeut(i,j,k));//ㄷ덮기
        }
    }
    cout << minCost;//출력
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    MakeDigeut();//ㄷ만들기
    return 0;
}
