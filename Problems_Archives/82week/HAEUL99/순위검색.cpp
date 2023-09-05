
#include <bits/stdc++.h>

using namespace std;
vector<int> a[3][2][2][2]; //언어/직군/경력/소울푸드
vector<int> xa;
vector<int> ya;
vector<int> za;
vector<int> wa;
int ans;
int certainscore;
int res[4];
vector<string> split(string& str)
{
    string tmp = "";
    vector<string> ret;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == ' ')
        {
            ret.push_back(tmp);
            tmp = "";
        }
        else
        {
            tmp += str[i];

        }
    }
    ret.push_back(tmp);
    return ret;
}

void dfs(int cur)
{
    if(cur == 4)
    {
        int cx = res[0];  int cy = res[1];  int cz = res[2];  int cw = res[3];
        
        for(int i =0; i < a[cx][cy][cz][cw].size(); i++)
        {
            if(a[cx][cy][cz][cw][i] >= certainscore)
            {
                 ans+=  a[cx][cy][cz][cw].size() - i;
                 break;
            }
        }
        return;
    }
    
    if(cur == 0)
    {
        for(int i = 0; i < xa.size(); i++)
        {
            res[cur] = xa[i];
            dfs(cur+1);
        }
    }
    if(cur == 1)
    {
        for(int i = 0; i < ya.size(); i++)
        {
            res[cur] = ya[i];
            dfs(cur+1);
        }
    }
    if(cur == 2)
    {
        for(int i = 0; i < za.size(); i++)
        {
            res[cur] = za[i];
            dfs(cur+1);
        }
    }
    
    if(cur == 3)
    {
        for(int i = 0; i < wa.size(); i++)
        {
            res[cur] = wa[i];
            dfs(cur+1);
        }
    }
    
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(int i = 0; i < info.size(); i++)
    {
        vector<string> vec = split(info[i]);
        int x,y,z,w;
        if(vec[0] == "java") x = 0;
        else if(vec[0] == "python") x = 1;
        else x = 2;
        
        if(vec[1] == "backend") y = 0;
        else y = 1;
        
        if(vec[2] == "junior") z = 0;
        else z = 1;
        
        if(vec[3] == "pizza") w = 0;
        else w = 1;
        
        int score = stoi(vec[4]);
        
        a[x][y][z][w].push_back(score);
    }
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                for(int p = 0; p < 2; p++)
                {
                    sort(a[i][j][k][p].begin(), a[i][j][k][p].end());
                }
            }
        }
    }
    
    for(int i = 0; i < query.size(); i++)
    {
        vector<string> vec = split(query[i]);
        xa.clear(); ya.clear(); za.clear(); wa.clear();
        ans = 0;
        int x = -1; int y = -1; int z = -1; int w = -1;
        if(vec[0] == "java") x = 0;
        else if(vec[0] == "python") x = 1;
        else if (vec[0] == "cpp") x = 2;
        else
        {
            x = -1;
        }
        
        if(vec[2] == "backend") y = 0;
        else if(vec[2] == "frontend") y = 1;
        else
        {
            y = -1;
        }
        
        if(vec[4] == "junior") z = 0;
        else if(vec[4] == "senior") z = 1;
        else 
        {
            z = -1;
        }
        
        if(vec[6] == "pizza") w = 0;
        else if(vec[6] == "chicken") w = 1;
        else 
        {
            w = -1;
        }
        
        certainscore = stoi(vec[7]);

        if(x == -1) {xa.push_back(0); xa.push_back(1); xa.push_back(2); }
        else xa.push_back(x); 
        if(y == -1) {ya.push_back(0); ya.push_back(1); }
        else ya.push_back(y); 
        if(z == -1) {za.push_back(0); za.push_back(1); }
        else za.push_back(z); 
        if(w == -1) {wa.push_back(0); wa.push_back(1); }
        else wa.push_back(w);
        
        dfs(0);
        answer.push_back(ans);
        
        
    }
    
    
    return answer;
}
