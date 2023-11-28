#include <iostream>
using namespace std;

int n;
const int maxi = 100001;
const int inf = 1000001;
int num[maxi];//수열
int score[inf];//점수
bool isNum[inf];//숫자가 수열에 존재 하는가?

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        isNum[num[i]] = true;
    }
}
//수 나누기
void DivideNum() {
    for (int i = 0; i < n; i++) {
        int number = num[i];
        //num[i]의 배수
        for (int j = number * 2; j < inf; j += number) {
            if (!isNum[j]) continue;//숫자가 존재하지 않음
            score[j] -= 1;
            score[number] += 1;
        }
    }
    //출력
    for (int i = 0; i < n; i++) cout << score[num[i]] << " ";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    DivideNum();//수 나누기
    return 0;
}
