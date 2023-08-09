#include <iostream>

using namespace std;
#define MAX 50001

/*
최대 100,000
1 4 9 16 25 36 ... 100: 10,000 400: 160,000
300: 90,000
(a+b)(a-b) = 400+399 = 799
a+b = 100,000
=> a+(a-1) = 100,000
2a = 100002
a = 50001
(a)
*/
int main()
{
    int g;

    cin >> g;

    int st = 1; // 기억 속 몸무게
    int en = 2; // 현재 몸무게
    bool flag = false;

    while(st<=MAX && en<=MAX && st<en)
    {
        int diff = en*en - st*st;
        if(diff < g)
        {
            en++;
        }
        else if(diff == g)
        {
            flag = true;
            cout << en << '\n';
            st++;
        }
        else
        {
            st++;
        }
    }

    if(!flag)
        cout << "-1";
    return 0;
}
