#include <iostream>
using namespace std;

int n,k,q;
const int maxi = 10001;
int notRead[maxi];//읽지 않은 사람의 수
char sender[maxi];//발신자
bool isRead[26];//읽었는가?

//입력
void Input() {
    cin >> n>>k>>q;
    for (int i = 1; i <= k; i++) cin >> notRead[i] >> sender[i];
}
//읽지 않은 사람의 수
void NotRead() {
    //모두 읽음
    if (notRead[q] == 0) {
        cout << -1;
        return;
    }
    //메세지
    int people = notRead[q];
    for (int i = 1; i <= k; i++) {
        if (people <= notRead[i]) {
            isRead[sender[i] - 'A'] = true;
        }
    }
    //읽지 않음
    for (int i = 1; i < n; i++) {
        if (!isRead[i]) cout << char(i + 'A') << " ";//아스키 코드 사용
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();//입력
    NotRead();//읽지 않은 사람의 수
    return 0;
}
