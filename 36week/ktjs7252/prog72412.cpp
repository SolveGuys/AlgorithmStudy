#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

// vector<int> lan[50001]; //cpp 1, java 2, python 3
// vector<int> field[50001]; //backend 1 front 2
// vector<int> career[50001]; //junior 1, senior 1
// vector<int> food[50001]; // chicken 1 pizza 2
// vector<int> score[50001];
int lan[50001];
int field[50001];
int career[50001];
int food[50001];
int score[50001];
int n;
int tmp[10];
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    n=info.size();
    for(int i=0;i<info.size();i++)
    {
        if(info[i].find("cpp")!=string::npos) 
        {
            //lan[i].push_back(1);
            lan[i]=1;
        }
        if(info[i].find("java")!=string::npos)
        {
            //lan[i].push_back(2);
            lan[i]=2;
        }
        if(info[i].find("python")!=string::npos)
        {
            //lan[i].push_back(3);
            lan[i]=3;
        }
        if(info[i].find("backend")!=string::npos)
        {
            //field[i].push_back(1);
            field[i]=1;
        }
        if(info[i].find("frontend")!=string::npos)
        {
            //field[i].push_back(2);
            field[i]=2;
        }
        if(info[i].find("junior")!=string::npos)
        {
            //career[i].push_back(1);
            career[i]=1;
        }
        if(info[i].find("senior")!=string::npos)
        {
            //career[i].push_back(2);
            career[i]=2;
        }
        if(info[i].find("chicken")!=string::npos)
        {
            //food[i].push_back(1);
            food[i]=1;
        }
        if(info[i].find("pizza")!=string::npos)
        {
            //food[i].push_back(2);
            food[i]=2;
        }
        int start=0;
        int end=info[i].find(" ");
        
        while(end!=string::npos)
        {
            start=end+1;
            end=info[i].find(" ",start);
        }
        //score[i].push_back(stoi(info[i].substr(start,end-start)));
        score[i]=stoi(info[i].substr(start,end-start));
    }
    
    for(int i=0;i<query.size();i++)
    {
        memset(tmp,0,sizeof(tmp));
        if(query[i].find("cpp")!=string::npos) 
        {
            tmp[0]=1;
        }
        if(query[i].find("java")!=string::npos)
        {
            tmp[0]=2;
        }
        if(query[i].find("python")!=string::npos)
        {
            tmp[0]=3;
        }
        if(query[i].find("backend")!=string::npos)
        {
            tmp[1]=1;
        }
        if(query[i].find("frontend")!=string::npos)
        {
            tmp[1]=2;
        }
        if(query[i].find("junior")!=string::npos)
        {
            tmp[2]=1;
        }
        if(query[i].find("senior")!=string::npos)
        {
            tmp[2]=2;
        }
        if(query[i].find("chicken")!=string::npos)
        {
            tmp[3]=1;
        }
        if(query[i].find("pizza")!=string::npos)
        {
            tmp[3]=2;
        }
        int start=0;
        int end=query[i].find(" ");
        //vector<string> k;
        while(end!=string::npos)
        {
            start=end+1;
            end=query[i].find(" ",start);
        }
        
        string k=query[i].substr(start,end-start);
        if(k=="-")
        {
            tmp[4]=0;
        }
        else
        {
            tmp[4]=stoi(k);
        }
        //printf("%d %d %d %d %d\n",tmp[0],tmp[1],tmp[2],tmp[3],tmp[4]);
        //배열에 전부 넣어줌
        int counting=0;
        for(int j=0;j<n;j++)
        {
            if(tmp[0]>0 && tmp[0]!=lan[j])
            {
                continue;
            }
            if(tmp[1]>0 && tmp[1]!=field[j])
            {
                continue;
            }
            if(tmp[2]>0 && tmp[2]!=career[j])
            {
                continue;
            }
            if(tmp[3]>0 && tmp[3]!=food[j])
            {
                continue;
            }
            if(tmp[4]>0 && tmp[4]>score[j])
            {
                continue;
            }
            counting++;
        }
        answer.push_back(counting);
        
    }
    
    
    return answer;
}
