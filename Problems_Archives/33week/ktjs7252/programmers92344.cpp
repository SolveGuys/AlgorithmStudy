#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int arr[1001][1001];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n=board.size();
    int m=board[0].size();
    
    for(int i=0;i<skill.size();i++)
    {
        if(skill[i][0]==1)
        {
            arr[skill[i][1]][skill[i][2]]-=skill[i][5];
            arr[skill[i][3]+1][skill[i][4]+1]-=skill[i][5];
            arr[skill[i][3]+1][skill[i][2]]+=skill[i][5];
            arr[skill[i][1]][skill[i][4]+1]+=skill[i][5];
        }
        else
        {
            arr[skill[i][1]][skill[i][2]]+=skill[i][5];
            arr[skill[i][3]+1][skill[i][4]+1]+=skill[i][5];
            arr[skill[i][3]+1][skill[i][2]]-=skill[i][5];
            arr[skill[i][1]][skill[i][4]+1]-=skill[i][5];
        }
    }
    
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++) 
        {
            arr[i][j]+=arr[i-1][j];
        }
    }
    
    for(int i=0;i<n;i++) //왼쪽에서 오른쪽
    {
        for(int j=1;j<m;j++)
        {
            arr[i][j]+=arr[i][j-1];
        }
    }
    
    for(int i=0;i<board.size();i++) //누적합으로 계산
    {
        for(int j=0;j<board[0].size();j++)
        {
            //cout<<arr[i][j]+board[i][j]<<" ";
            if(board[i][j]+arr[i][j]>0)
            {
                answer++;
            }
        }
        //cout<<"\n";
    }
    
    
    return answer;
}
