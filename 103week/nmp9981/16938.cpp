#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,l,r,X;
int caseNum = 0;//경우의 수
const int maxi = 15;
vector<int> level;//난이도
vector<int> problem;//문제
bool isSelect[maxi];//선택 여부

//입력
void input() {
    cin >> n>>l>>r>>X;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        level.push_back(a);
    }
    sort(level.begin(), level.end());//정렬
}
//문제선택
void SelectProblem(int idx,int cnt,int sum) {
    //문제 선택
    if (cnt >= 2) {
        if (sum >= l && sum <= r) {//난이도 합
            if (problem[cnt - 1] - problem[0] >= X) caseNum++;//난이도 차
        }
    }

    //다음 문제
    for (int i = idx; i < n; i++) {
        if (isSelect[i]) continue;//이미 선택

        problem.push_back(level[i]);//미리 정렬했으므로 알아서 오름차순으로 된다.
        isSelect[i] = true;
        SelectProblem(i+1,cnt + 1, sum + level[i]);//다음 문제
        isSelect[i] = false;
        problem.pop_back();
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    SelectProblem(0,0,0);//문제 선택
    cout << caseNum;//출력
    return 0;
}
