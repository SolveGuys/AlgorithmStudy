#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n;
const int maxi = 26;
int apartmentSet = 0;//아파트 단지 세트 개수
string world[maxi];//지도
bool visit[maxi][maxi];//방문 여부
vector<int> house;//집 개수
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> world[i];
}
//집 개수
int HouseCount(int i, int j) {
    visit[i][j] = true;
    queue<pair<int, int>> q;
    q.push({ i,j });
    int cnt = 1;//1개는 있다.

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;//범위 조건
            if (visit[nx][ny]) continue;//방문 조건
            if (world[nx][ny] == '0') continue;//집이 있는가?

            visit[nx][ny] = true;
            cnt++;
            q.push({ nx,ny });
        }
    }
    house.push_back(cnt);
    return 1;//덩어리 1개
}
//아파트 단지 탐색
void Apartment(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (world[i][j] == '1' && !visit[i][j]) apartmentSet+=HouseCount(i, j);
        }
    }
    //출력
    cout << apartmentSet << "\n";
    sort(house.begin(), house.end());//오름차순 정렬
    for (int i = 0; i < house.size(); i++) cout << house[i] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Apartment();//아파트 단지 탐색
    return 0;
}
