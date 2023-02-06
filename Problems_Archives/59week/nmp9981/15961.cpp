#include <iostream>
#include <vector>
using namespace std;

int n,d,k,c;
const int maxi = 3001;
vector<int> sushi;//초밥
int Eat[maxi];//범위내에 초밥이 몇개 있는가?

//입력
void input() {
    cin >> n>>d>>k>>c;
    for (int i = 0; i < n; i++) {
        int menu;
        cin >> menu;
        sushi.push_back(menu);
    }
    //슬라이딩 윈도우를 위해 한줄 추가
    for (int i = 0; i < n; i++) {
        sushi.push_back(sushi[i]);
    }
}
//초밥 먹기
void EatSushi() {
    Eat[c]++;//쿠폰
    int kind = 1;//초밥 종류 개수
    //처음 k개
    for (int i = 0; i < k; i++) {
        Eat[sushi[i]]++;
        if (Eat[sushi[i]] == 1) kind++;
    }

    int eatSize = kind;//최대 가짓수
    for (int i = k; i < 2 * n; i++) {//마지막 초밥
        //추가
        Eat[sushi[i]]++;
        if (Eat[sushi[i]] == 1) kind++;
        //제거
        Eat[sushi[i - k]]--;
        if (Eat[sushi[i - k]] == 0) kind--;
        
        //최대 가짓수
        if (kind > eatSize) eatSize = kind;
    }
    cout << eatSize;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    EatSushi();//초밥 먹기
    return 0;
}
