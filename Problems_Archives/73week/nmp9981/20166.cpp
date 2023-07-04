#include <iostream>
#include <map>
using namespace std;

int n,m,k;
const int maxi = 11;
string world[maxi];//지도
string likeStr;//좋아하는 문자열
map<string, int> wordCnt;//단어 개수
//8방 탐색
int dx[8] = { -1,1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,-1,1,1,-1,1,-1 };

//입력
void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin>>world[i];
}

//문자열 연결
void Connect(int x, int y, string str,int depth) {
    if (depth == 5) return;//길이 초과
    wordCnt[str]++;//개수 세기

    //다음 지점
    for (int k = 0; k < 8; k++) {
        int nx = (x + dx[k]+n)%n;
        int ny = (y+dy[k]+m)%m;

        Connect(nx, ny, str + world[nx][ny],depth+1);//다음 문자열
    }
}
//문자열 저장
void StringSave() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string firstStr = "";
            Connect(i, j, firstStr+world[i][j], 0);//시작 지점
        }
    }
}
//경우의 수
void CaseNum() {
    while (k--) {
        cin >> likeStr;//좋아하는 문자열 입력
        cout << wordCnt[likeStr] << "\n";//출력
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    StringSave();//문자열 저장
    CaseNum();//경우의 수
    return 0;
}
