#include <string>
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> _vec;
int mx;
int cnt;
void func(int cur) // cur은 들고있는 계란의 index
{
    if(cur == n)  // 마지막 계란까지 확인했으면 끝
    {
        mx = max(mx, cnt);
        return;
    }
    
    if(_vec[cur].first <= 0 || cnt == n-1)
    {
        func(cur+1);
        return;
    } // 현재 들고 있는 계란이 깨졌으면, 또는 현재 계란이 한 개 빼고 다 깨졌으면 다음 계란 든다
    
    for(int i = 0; i < n; i++)
    {

        if(cur == i) continue; // 자기 자신을 깨려고 하면
        if(_vec[i].first <= 0) continue; // 깨려고 하는 계란 계졌으면, 다음 계란을 꺤다. 
        
        _vec[cur].first -= _vec[i].second;
        _vec[i].first -= _vec[cur].second;
        if(_vec[cur].first <= 0) cnt++;
        if(_vec[i].first <= 0) cnt++;

        func(cur+1);
        if(_vec[cur].first <= 0) cnt--;
        if(_vec[i].first <= 0) cnt--;
        _vec[cur].first += _vec[i].second;
        _vec[i].first += _vec[cur].second;
        
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n; 

    int s, w;
    for(int i = 0; i < n; i++)
    {
        cin >> s >> w;
        _vec.push_back(make_pair(s, w));
    }

    func(0);
    cout << mx;
}
