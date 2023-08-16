#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

int idx;
int num; 
string str;
vector<string> _vec(8);
vector<string> split() //:기준으로 나눠서 vector에 넣기
{
    vector<string> _vector;
    string curstr = "";

    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == ':')
        {
            if(curstr == "")
            {
                idx = num;
                //_vector[num] = "0000";
            }
            else
            {
                _vector.push_back(curstr);
                curstr = "";
                num++;
            }
            
        }
        else
        {
            curstr += str[i];
        }
    }
    _vector.push_back(curstr);
    return _vector;
}
int main()
{           
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> str;
    _vec = split();

    int pos = 0;
    int pos1 = 0;
    while(pos1 + pos < 8)
    {
        if(pos1 + pos == idx && _vec.size() != 8)
        {
            for(int j = 0; j < 8 - _vec.size(); j++)
            {
                cout << "0000";
                if((pos1 + pos + j) != 7) cout << ':';
            }
            pos += (8 - _vec.size());
        }
        else
        {
            if(_vec[pos1].size() != 4)
            {
                int num = 4 - _vec[pos1].size();
                for(int j = 0; j < num; j++) cout << '0';
                cout << _vec[pos1];
                if(pos1 + pos != 7) cout << ':';
            }
            else
            {
                cout << _vec[pos1];
                if(pos1 + pos != 7) cout << ':';
            }
            pos1++;
        }
        
    }
    
}
