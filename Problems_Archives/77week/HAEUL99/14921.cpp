#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;
int arr[100002];
int comp[100002];
int main()
{           
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    cin >> n;

    fill(arr, arr+n, -1);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        comp[i] = (-1) * arr[i];
    }
    int mn = INT_MAX;


    for(int i = 0; i < n; i++)
    {
        int a;
        int a1;
        int a2;


        a = *lower_bound(arr, arr+n, comp[i]);
        a1 = *prev(lower_bound(arr, arr+n, comp[i]));
        a2 = *(lower_bound(arr, arr+n, comp[i]) + 1);

        if(lower_bound(arr, arr+n, comp[i]) == &arr[i])
            a = -1;
        if((prev(lower_bound(arr, arr+n, comp[i]))) == &arr[i])
            a1 = -1;
        if((lower_bound(arr, arr+n, comp[i]) + 1) == &arr[i])
            a2 = -1;

        int b, b1, b2;
        if(a == -1 || (a == 0 && arr[i] != 0)) b = INT_MAX;
        else b = a + arr[i];
        if(a1 == -1 || (a1 == 0 && arr[i] != 0)) b1 = INT_MAX;
        else b1 = a1 + arr[i];
        if(a2 == -1 || (a2 == 0 && arr[i] != 0)) b2 = INT_MAX;
        else b2 = a2 + arr[i];



        int res = min({abs(b), abs(b1), abs(b2)});
        if(res == abs(b)) res = b;
        else if (res == abs(b1)) res = b1;
        else if (res == abs(b2)) res = b2;
        else continue;

        if(abs(mn) > abs(res))
        {
            mn = res;
        }
        
    }    

    cout << mn;

}
