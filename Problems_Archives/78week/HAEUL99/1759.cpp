#include <bits/stdc++.h>
using namespace std;

int l, c;
char arr[20];
char ans[20];
int mask[20];

bool isMoeum(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }
    return false;
}

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> l >> c;
    
    for(int i = 0; i < c; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + c);

    for(int i = l; i < c; i++)
    {
        mask[i] = 1;
    }

    do
    {
        int cnt = 0;
        int ja = 0;
        int mo = 0;
        for(int i = 0; i < c; i++)
        {
            if(mask[i] == 0)
            {  
                if(isMoeum(arr[i]))
                    mo++;
                else 
                    ja++;
                ans[cnt++] = arr[i];
            }

        }
        if(mo >= 1 && ja >= 2)
        {
            for(int i = 0; i < l; i++)
            {
                cout << ans[i];
            }
            cout << '\n';
        }

        

    }while(next_permutation(mask, mask + c));

}
