#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

#define INF 4000000 // ????

int arr[201][201];

void flo(int n){
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    //초기화
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==j) arr[i][j]=0;
            else arr[i][j]=INF;
        }
    }
    
    for(int i=0;i<fares.size();i++)
    {
        arr[fares[i][0]][fares[i][1]]=fares[i][2];
        arr[fares[i][1]][fares[i][0]]=fares[i][2];
    }
    
    flo(n);
    
    for(int i=1;i<=n;i++)
    {
        answer=min(answer,arr[s][i]+arr[i][a]+arr[i][b]);
    }
    
    return answer;
}
