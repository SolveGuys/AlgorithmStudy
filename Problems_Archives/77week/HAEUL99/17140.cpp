#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int arr[202][202];
int r,c,k;
int ans;
int cur_r, cur_c; //현재 r, c개수

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}
int main()
{           
    cin >> r >> c >> k;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    r--;
    c--;
    
    cur_r = 3; //행 개수
    cur_c = 3; //열 개수
    
    
    
    int val;
    int num;
    while(true)
    {
        if(arr[r][c] == k) break;
        if(ans == 100)
        {
            cout << -1;
            return 0;
        }
        ans++;

        if(cur_r >= cur_c)
        {
            int mc = 0;
            for(int i = 0; i < cur_r; i++)
            {
                map<int, int> _map; //키가 수, 값이 수의 개수
                for(int j = 0; j < cur_c; j++)
                {
                    val = arr[i][j];
                    if(val == 0) continue;
                    _map[val] = _map[val] + 1;
                }
                
                
                // for(auto pair: _map)
                //     cout << pair.first << ' ' << pair.second << '\n';
                // cout << '\n';
                //수의 개수가 커지는 순서로 정렬, 같다면 수가 커지게 정렬
                vector<pair<int, int>> sortmap(_map.begin(), _map.end());
                sort(sortmap.begin(), sortmap.end(), cmp);
                //cout << static_cast<int>(sortmap.size()) << endl;
        
                for(int j = 0; j < static_cast<int>(sortmap.size()); j++)
                {
                    arr[i][j*2] = sortmap[j].first;
                    arr[i][j*2+1] = sortmap[j].second;
                }
                int cnt = static_cast<int>(sortmap.size()) * 2;
                for(int j = cnt; j < cur_c; j++)
                    arr[i][j] = 0;
                
                mc = max(mc, static_cast<int>(sortmap.size()));
            }
            cur_c = mc * 2;
            
        }
        else
        {
            int mr = 0;
            for(int j = 0; j < cur_c; j++)
            {
                map<int, int> _map; //키가 수, 값이 수의 개수
                for(int i = 0; i < cur_r; i++)
                {
                    val = arr[i][j];
                    if(val == 0) continue;
                    _map[val] = _map[val] + 1;
                }
                //수의 개수가 커지는 순서로 정렬, 같다면 수가 커지게 정렬
                vector<pair<int, int>> sortmap(_map.begin(), _map.end());
                sort(sortmap.begin(), sortmap.end(), cmp);
                
                for(int i = 0; i < static_cast<int>(sortmap.size()); i++)
                {
                    arr[i*2][j] = sortmap[i].first;
                    arr[i*2+1][j] = sortmap[i].second;
                }
                int cnt = static_cast<int>(sortmap.size()) * 2;
                for(int i = cnt; i < cur_r; i++)
                    arr[i][j] = 0;
                mr = max(mr, static_cast<int>(sortmap.size()));
            }
            cur_r = mr * 2;
            
        }
       
    }

    cout << ans;
    
}
