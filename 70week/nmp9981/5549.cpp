#include <iostream>
using namespace std;

struct Pos {
    int x, y, dist;//좌표 거리
};
int m,n,k;
const int maxi = 1002;
string world[maxi];//지도
int areaCount[maxi][maxi][3];//정글,바다,얼음 개수

//입력
void input() {
    cin >> m>>n>>k;
    for (int i = 0; i < m; i++) cin >> world[i];
}
//지역 개수 : (1,1)부터 (i,j)까지
void AreaCount() {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (world[i - 1][j - 1] == 'J') {
                areaCount[i][j][0] = areaCount[i - 1][j][0] + areaCount[i][j - 1][0] - areaCount[i - 1][j - 1][0] + 1;
                areaCount[i][j][1] = areaCount[i - 1][j][1] + areaCount[i][j - 1][1] - areaCount[i - 1][j - 1][1];
                areaCount[i][j][2] = areaCount[i - 1][j][2] + areaCount[i][j - 1][2] - areaCount[i - 1][j - 1][2];
            }
            else if (world[i - 1][j - 1] == 'O') {
                areaCount[i][j][0] = areaCount[i - 1][j][0] + areaCount[i][j - 1][0] - areaCount[i - 1][j - 1][0];
                areaCount[i][j][1] = areaCount[i - 1][j][1] + areaCount[i][j - 1][1] - areaCount[i - 1][j - 1][1] + 1;
                areaCount[i][j][2] = areaCount[i - 1][j][2] + areaCount[i][j - 1][2] - areaCount[i - 1][j - 1][2];
            }
            else if (world[i - 1][j - 1] == 'I') {
                areaCount[i][j][0] = areaCount[i - 1][j][0] + areaCount[i][j - 1][0] - areaCount[i - 1][j - 1][0];
                areaCount[i][j][1] = areaCount[i - 1][j][1] + areaCount[i][j - 1][1] - areaCount[i - 1][j - 1][1];
                areaCount[i][j][2] = areaCount[i - 1][j][2] + areaCount[i][j - 1][2] - areaCount[i - 1][j - 1][2] + 1;
            }
        }
    }
}
//탐색
void Search() {
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << areaCount[x2][y2][0] - areaCount[x1-1][y2][0] - areaCount[x2][y1-1][0] + areaCount[x1-1][y1-1][0] << " ";//정글
        cout << areaCount[x2][y2][1] - areaCount[x1-1][y2][1] - areaCount[x2][y1-1][1] + areaCount[x1-1][y1-1][1] << " ";//바다
        cout << areaCount[x2][y2][2] - areaCount[x1-1][y2][2] - areaCount[x2][y1-1][2] + areaCount[x1-1][y1-1][2] << " ";//얼음
        cout << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    AreaCount();//지역 카운트
    Search();//탐색
    return 0;
}
