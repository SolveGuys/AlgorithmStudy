#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int lock_main[100][100];
int keys[30][30];
int tmp[100][100];
int k[30][30];
int n,m;

void rotate()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            k[i][j]=keys[i][j];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            keys[i][j]=k[n-j-1][i];
        }
    }
}
// void show()
// {
//     cout<<"\n";
//     for(int i=50-n;i<50+m+n;i++)
//     {
//         for(int j=50-n;j<50+m+n;j++)
//         {
//             cout<<tmp[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
// }

bool check()
{
    for(int i=50;i<50+m;i++)
    {
        for(int j=50;j<50+m;j++)
        {
            if(tmp[i][j]!=1)
            {
                return false;
            }
        }
    }
    return true;
}

void go(int x,int y)
{
     int idx_x=0,idx_y=0;
    for(int i=x;i<x+n;i++)
    {
        idx_y=0;
        for(int j=y;j<y+n;j++)
        {
            tmp[i][j]+=keys[idx_x][idx_y];
            idx_y++;
        }
        idx_x++;
    }
    
}
int solve()
{
    memcpy(tmp,lock_main,sizeof(lock_main));
    
    for(int i=50-n;i<50+m+n;i++)
    {
        for(int j=50-n;j<50+m+n;j++)
        {
            memcpy(tmp,lock_main,sizeof(lock_main));
            go(i,j);
            //show();
            if(check())
            {
                return 1;
            }
        }
    }
    
    return 0;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    n=key.size();
    m=lock.size();
    
    for(int i=50;i<50+m;i++)
    {
        for(int j=50;j<50+m;j++)
        {
            lock_main[i][j]=lock[i-50][j-50];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            keys[i][j]=key[i][j];
        }
    }
    
    for(int i=0;i<4;i++)
    {
        if(solve())
        {
            return true;
        }
        rotate();
    }
    
    
    return answer;
}
