#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, 0, -1}; //하 좌 우 위
int dy[4] = {0, -1, 1, 0};
int _n, _m, _x, _y, _r, _c, _k;
string ans[2502];
string a[4] = {"d", "l", "r", "u"};
vector<string> _res;
bool isT;

int get_dist(int x,int y,int a,int b){
    return abs(x-a) + abs(y-b);
}

void dfs(int cur, int nx, int ny)
{

    if(isT) return;
    int dist = get_dist(nx, ny, _r, _c); 
    if(_k - cur < dist) return; // 남은 움직임 수가 현재 위치에서 목표지점까지의 거리보다 적으면
    if((_k-cur-dist) % 2 == 1) return; //남은 움직임 수에서 현재 위치에서 목표지점까지의 거리를 뺐을 때 홀수번 남으면 
    
    
    if(cur == _k)
    {
        string _str = "";

        for(int i = 0; i < cur; i++)
        {
            _str+= ans[i];
        }
        if(nx == _r && ny == _c)
        {
            _res.push_back(_str);
            isT = true;
        }
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        ans[cur] = a[i]; 
        

        int tmx = nx; 
        int tmy = ny;
        
        //하 좌 우 위
        if(ans[cur] == "u")
        {
            tmx += dx[3];
        }
        if(ans[cur] == "d")
        {
            tmx += dx[0];
        }
        if(ans[cur] == "l")
        {
            tmy += dy[1];
        }
        if(ans[cur] == "r")
        {
            tmy += dy[2];
        }
        if(tmx <= 0 || tmx > _n || tmy <= 0 || tmy > _m)
        {
            continue;
        }
        dfs(cur+1, tmx, tmy);
    
    }    
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    _n = n; _m = m; _x = x; _y = y; _r = r, _c = c, _k = k;
    dfs(0, _x, _y);
    if(_res.size() == 0)
    {
        answer = "impossible";
    }
    else {
        sort(_res.begin(), _res.end());
        answer = _res[0];
    }
    
    
    return answer;
}
