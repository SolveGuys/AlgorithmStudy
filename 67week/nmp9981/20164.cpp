#include <iostream>
#include <string>
using namespace std;

int n;
const int inf = 999999;
string num;
int maxCount = 0;
int minCount = inf;

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//min
inline int min(int x, int y) {
    return x > y ? y : x;
}

//입력
void input() {
    cin >> n;
    num = to_string(n);
}

//숫자 나누기
void CutNum(string num,int cnt) {
    //한자리수
    if (num.size() == 1) {
        int oddCount = 0;
        if ((num[0] - '0') % 2 == 1) oddCount = 1;
        maxCount = max(maxCount, cnt+oddCount);
        minCount = min(minCount, cnt+oddCount);
        return;
    }
    //두자리수
    if (num.size() == 2) {
        //홀수 개수
        int oddCount = 0;
        for (int i = 0; i < num.size(); i++) {
            if ((num[i] - '0') % 2 == 1) oddCount++;
        }
        string sum = to_string((num[0] - '0') + (num[1] - '0'));
        CutNum(sum, cnt+oddCount);
    }
    //3등분
    if (num.size() >= 3) {
        //홀수 개수
        int oddCount = 0;
        for (int i = 0; i < num.size(); i++) {
            if ((num[i] - '0') % 2 == 1) oddCount++;
        }
        //3등분 하기
        for (int i = 1; i < num.size() - 1; i++) {//두번째 시작 지점
            for (int j = i + 1; j < num.size(); j++) {//세번째 시작 지점
                //3개의 문자열
                string first = num.substr(0, i);
                string second = num.substr(i, j-i);
                string third = num.substr(j);
                
                //합
                string sum = to_string(stoi(first) + stoi(second) + stoi(third));
                
                //홀수 개수 합치기
                CutNum(sum, cnt+oddCount);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    CutNum(num,0);//숫자 나누기
    cout << minCount << " " << maxCount;//출력
    return 0;
}
