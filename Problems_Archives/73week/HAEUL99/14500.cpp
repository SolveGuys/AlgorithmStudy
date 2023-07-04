#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <set>
#include <cstring>
#include <string>
#include <stdio.h>
#include <limits.h>
//#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[502][502];
int paper[8][5][5];
pair<int, int> pa_rc[8]; // r, c
int rotArr[8];


void Init()
{
    rotArr[0] = 2;
    rotArr[1] = 1;
    rotArr[2] = 4;
    rotArr[3] = 4;
    rotArr[4] = 2;
    rotArr[5] = 2;
    rotArr[6] = 4;
    // 1번째 
    pa_rc[0].first = 1;
    pa_rc[0].second = 4;
    paper[0][0][0] = 1; 
    paper[0][0][1] = 1; 
    paper[0][0][2] = 1; 
    paper[0][0][3] = 1; 

    //2번째
    pa_rc[1].first = 2;
    pa_rc[1].second = 2;
    paper[1][0][0] = 1; 
    paper[1][0][1] = 1; 
    paper[1][1][0] = 1; 
    paper[1][1][1] = 1;

    //3번째
    pa_rc[2].first = 3;
    pa_rc[2].second = 2;
    paper[2][0][0] = 1; 
    paper[2][1][0] = 1; 
    paper[2][2][0] = 1; 
    paper[2][2][1] = 1;

    //4번째
    pa_rc[3].first = 3;
    pa_rc[3].second = 2;
    paper[3][0][1] = 1; 
    paper[3][1][1] = 1; 
    paper[3][2][1] = 1;
    paper[3][2][0] = 1; 

    //5번째
    pa_rc[4].first = 3;
    pa_rc[4].second = 2;
    paper[4][0][0] = 1; 
    paper[4][1][0] = 1; 
    paper[4][1][1] = 1;
    paper[4][2][1] = 1; 

    //6번째
    pa_rc[5].first = 3;
    pa_rc[5].second = 2;
    paper[5][0][1] = 1; 
    paper[5][1][0] = 1; 
    paper[5][1][1] = 1;
    paper[5][2][0] = 1; 


    //7번째
    pa_rc[6].first = 2;
    pa_rc[6].second = 3;
    paper[6][0][0] = 1; 
    paper[6][0][1] = 1; 
    paper[6][0][2] = 1;
    paper[6][1][1] = 1; 

}

int calVal(int x, int y, int ct, int nr, int nc) // (x, y)에 테트로미노(0,0)부터 시작하여 붙일수있으면 true를 반환 그리고 mx값 갱신
{
    int v = 0;
    for(int i = 0; i < nr; i++)
    {
        for(int j = 0; j < nc; j++)
        {
            if(paper[ct][i][j] == 1)
            {
                v += board[x + i][y + j];
            }
        }
    }
    return v;
}

void rotate(int ct, int nr, int nc)
{
    int tmp[4][4];

    for(int i = 0; i < nr; i++)
    {
        for(int j = 0; j < nc; j++)
        {
            tmp[i][j] = paper[ct][i][j];
        }
    }
    for(int i = 0; i < nc; i++)
    {
        for(int j = 0; j < nr; j++)
        {
            paper[ct][i][j] = tmp[nr-j-1][i];
        }
    }   

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    Init();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int k = 7; // 저장하고 있을 스티커 수
    int ct = 0; //현재 페이퍼
    
    int mx =0;
    while(k--) //퍼이퍼 만큼 반복
    {
        int mr = rotArr[ct];//로테이션 해야하는 총 횟수

        int nr = pa_rc[ct].first;
        int nc = pa_rc[ct].second;
        for(int rot = 0; rot < mr; rot++)
        {           
            for(int i = 0; i <= n - nr; i++)
            {
                for(int j = 0; j <= m - nc; j++)
                {
                    int curVal = calVal(i, j, ct, nr, nc);
                    mx = max(curVal, mx);
                }
            }
            rotate(ct, nr, nc);
            swap(nr, nc);
        }
        
        ct++;
    }
    std::cout << mx;



}
