#include <iostream>
#include <cstring>
using namespace std;

string password;//암호
const int maxi = 5001;
const int mod = 1000000;
int interpret[maxi];//해석하는 경우의 수

//입력
void input() {
    cin >> password;
    password = ' ' + password;
    interpret[0] = 1;
}
//해석
int Interpret() {
    //첫글자 검사
    int firstAlpha = password[1] - '0';
    if (firstAlpha != 0) interpret[1] = 1;
    else return 0;

    //각 글자별로 검사
    for (int i = 2; i < password.size(); i++) {
        int num = password[i] - '0';
        if (num == 0) {//마지막 글자가 0
            int alpha = (password[i - 1] - '0') * 10;
            if (alpha / 10 == 1 || alpha / 10 == 2) interpret[i] = interpret[i - 2];//j,t
            else return 0;
        }
        else {//마지막 글자가 0이 아닌 경우
            int alpha = (password[i - 1] - '0') * 10 + num;
            if (password[i - 1] != '0') {//이전 알파벳이 0이 아닌 경우
                //마지막 두 글자가 알파벳이 가능한가?
                if (alpha <= 26 && alpha >= 1) interpret[i] = (interpret[i - 1] + interpret[i - 2]) % mod;
                else interpret[i] = interpret[i - 1];
            }
            else interpret[i] = interpret[i - 1];//ex) 07
        }
    }
    return interpret[password.size() - 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    cout << Interpret();//해석
    return 0;
}
