#include <bits/stdc++.h>
using namespace std;

int n;
char board[7][7];
char tmp[7][7];
pair<int, int> xarr[50];
int mask[50];
vector<pair<int, int>> _vec;

bool Up(int x, int y)
{
    while(x > 0)
    {
        x--;
        if(tmp[x][y] == 'S')
            return true;
        if(tmp[x][y] == 'O')
            return false;
    }
    return false;
}

bool Down(int x, int y)
{
    while(x < n-1)
    {
        x++;
        if(tmp[x][y] == 'S')
            return true;
        if(tmp[x][y] == 'O')
            return false;
    }
    return false;
}

bool Right(int x, int y)
{
    while(y < n-1)
    {
        y++;
        if(tmp[x][y] == 'S')
            return true;
        if(tmp[x][y] == 'O')
            return false;
    }
    return false;
}

bool Left(int x, int y)
{
    while(y > 0)
    {
        y--;
        if(tmp[x][y] == 'S')
            return true;
        if(tmp[x][y] == 'O')
            return false;
    }
    return false;
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int xsize = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 'X')
            {
                xarr[xsize].first = i;
                xarr[xsize].second = j;
                xsize++;
            }
            if(board[i][j] == 'T')
            {
                _vec.push_back(make_pair(i, j));
            }

        }
    }


    bool isComp = false;
    // xsize 에서 3자리 고르기
    for(int i = 3; i < xsize ; i++)
    {
        mask[i] = 1;
    }

    do
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                tmp[i][j] = board[i][j];
            }
        }


        for(int i = 0; i < xsize; i++)
        {
            if(mask[i] == 0)
            {
                int x = xarr[i].first;
                int y = xarr[i].second;
                tmp[x][y] = 'O';
            }
        }

        isComp = false;
        for(int i = 0; i < _vec.size(); i++)
        {
            int x = _vec[i].first;
            int y = _vec[i].second;

            isComp = isComp || Up(x, y) || Down(x, y) || Right(x, y) || Left(x, y);
        }
        
        if(isComp == false)
        {
            
            cout << "YES";
            return 0;
        }


    }while(next_permutation(mask, mask + xsize));

    cout << "NO";

}
