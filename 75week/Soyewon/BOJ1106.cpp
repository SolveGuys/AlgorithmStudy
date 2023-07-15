#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 100001

int c; // 호텔 고객 명수
int n; // 홍보할 수 있는 도시 개수
vector<pair<int, int>> city; // city[i].first: 홍보비, .second: 고객 수
int d[MAX]; // d[i]: i 만큼의 비용으로 얻을 수 있는 고객 수
int res = 987654321;

void dp()
{
    for(int i=0; i<n; i++)
    {
        for(int m=1; m<=MAX; m++)
        {
            if((m - city[i].first) >= 0)
            {
                d[m] = max(d[m], d[m - city[i].first] + city[i].second);
            }
        }
    }

    for(int i=1; i<=MAX; i++)
    {
        if(d[i]>=c)
        {
            cout << i;
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> c >> n;
    for(int i=0; i<n; i++)
    {
        int money, customer;
        cin >> money >> customer;
        city.push_back({money, customer});
    }

    dp();
    return 0;
}
