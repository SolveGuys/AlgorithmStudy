#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <utility>


using namespace std;

int dist(string begin, string target)
{
    int count = 0;
    
    for(int i = 0; i < begin.size(); i++)
    {
        if(begin[i] != target[i])
            count++;
    }

    return count;
}


int solution(string begin, string target, vector<string> words)
{    
    int answer = 0;
    vector<bool> visited(words.size(),false);
    queue<pair<string,int>> Q;
    
    
    Q.push({begin,0});
    
    while(!Q.empty())
    {
        string current = Q.front().first;   
        int count = Q.front().second;
        Q.pop();
        
        if(current == target)
        {
            answer = count;
            break;
        }
        //cout << current << "\n";
        
        for(int i = 0; i < words.size(); i++)
        {
            if(visited[i])
                continue;
            
            auto word = words[i];
            //cout << " " << word;
            
            if(dist(current,word) == 1)
            {
                Q.push({word,count+1});
                
                visited[i] = true;
            }
        }
        
        //cout << " " << count << "\n";
    }
    
    return answer;
}