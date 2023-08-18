#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

//9:49
string str;
int typeLan()
{
    int res = -1; //0: error, 1: c++, 2: java
    if(str[0] == '_' || str[str.size()-1] == '_' || (str[0] >= 'A' && str[0] <= 'Z')) 
    {
        res = 0;
        return res;
    }
    
    int _num = 0;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z' && res == -1)
        {
            res = 2;
        } 
        else if(str[i] == '_' && res == -1)
        {
            res = 1;
            _num = i;
        }
        else if(str[i] == '_' && res == 1)
        {
            if(_num == i-1)
            {
                res = 0;
                return res;
            }
        }
        else if(res!= -1)
        {
            if(res == 2)
            {
                if(str[i] == '_')
                {
                    res = 0;
                    return res;
                }
            }
            if(res == 1)
            {
                if(str[i] >= 'A' && str[i] <= 'Z')
                {
                    res = 0;
                    return res;
                }
            }

            
        }
    }
    int lnum = 0;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z') lnum++;
    }
    if(lnum == str.size()) res = 3;
    return res;
}

vector<string> split_()
{
    vector<string> ret;
    string cur = "";
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '_')
        {
            ret.push_back(cur);
            cur = "";
        }
        else
        {
            cur += str[i];
        }
    }
    ret.push_back(cur);
    return ret;
}

vector<string> splitU()
{
    vector<string> ret;
    string cur = "";
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            ret.push_back(cur);
            cur = str[i];
        }
        else
        {
            cur += str[i];
        }
    }
    ret.push_back(cur);
    return ret;
}

int main()
{           
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    int lang = typeLan(); 
    //cout << lang;
    //lang 1이면 2로, 2면 1로
    if(lang == 1)
    {
        vector<string> _ve = split_();
        for(int i = 0; i < _ve.size(); i++)
        {
            if(i != 0) cout << static_cast<char>(toupper(_ve[i][0]));
            else cout << _ve[i][0];
            for(int j = 1; j < _ve[i].size(); j++)cout << _ve[i][j];
        }

    }
    else if(lang == 2)
    {
        vector<string> _ve = splitU();
        for(int i = 0; i < _ve.size(); i++)
        {
            cout << static_cast<char>(tolower(_ve[i][0]));
            //cout << _ve[i][0];c_identifier
            for(int j = 1; j < _ve[i].size(); j++) cout << _ve[i][j];
            if(i != _ve.size()-1) cout << '_';
        }
    }
    else if(lang == 3)
    {
        cout << str;
    }
    else
    {
        cout << "Error!";
    }


    
    
    
}
