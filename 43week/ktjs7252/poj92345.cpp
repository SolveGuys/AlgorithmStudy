#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int visited[6][6];
int n,m;

bool check(int x){
    if(x%2==0)
    {
        return true;
    }
    return false;
}
int find(vector<vector<int>> &board,int ax,int ay,int bx,int by,int idx)
{
    if(check(idx)){
        if(visited[ax][ay]==1 ||board[ax][ay]==0) return idx;
        
        int lose=1000;
        int win=-1;
        int cant_go=0;
        for(int i=0;i<4;i++)
        {
            int x=ax+dx[i];
            int y=ay+dy[i];
            if(x<0 || y<0 || x>=n || y>=m) continue;
            if(visited[x][y]==1|| board[x][y]==0) continue;
            
            visited[ax][ay]=1;
            int tmp=find(board,x,y,bx,by,idx+1);
            visited[ax][ay]=0;
            cant_go=1;
            
            if(!check(tmp)){
                lose=min(lose,tmp);
            }
            else{
                win=max(win,tmp);
            }
        }
        if(cant_go==0) return idx;
        if(lose<1000) return lose;
        else{
            return win;
        }
    }
    else{
        if(visited[bx][by]==1 || board[bx][by]==0) return idx;
        
        int lose=1000;
        int win=-1;
        int cant_go=0;
        for(int i=0;i<4;i++)
        {
            int x=bx+dx[i];
            int y=by+dy[i];
            if(x<0 || y<0 || x>=n || y>=m) continue;
            if(visited[x][y]==1 || board[x][y]==0) continue;
            visited[bx][by]=1;
            int tmp=find(board,ax,ay,x,y,idx+1);
            visited[bx][by]=0;
            cant_go=1;
            if(check(tmp)){
                lose=min(lose,tmp);
            }
            else{
                win=max(win,tmp);
            }
        }
        if(cant_go==0) return idx;
        if(lose<1000) return lose;
        else{
            return win;
        }
    }
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int ax=aloc[0];
    int ay=aloc[1];
    int bx=bloc[0];
    int by=bloc[1];
    int sign=0;
    n = board.size(), m = board[0].size();
    
    int answer=find(board,ax,ay,bx,by,0);
    
    
    return answer;
}
