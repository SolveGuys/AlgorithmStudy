#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str;

string JavaToCpp(const string& str);
string CppToJava(const string& str);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str;

    string answer;

    if (str.find('_') != string::npos)
    {
        answer = CppToJava(str);
    }
    else
    {
        answer = JavaToCpp(str);
    }

    cout << answer << '\n';
}

string JavaToCpp(const string& str)
{
    string ret;

    // 대문자의 위치를 기록한다.
    int len = static_cast<int>(str.length());
    vector<int> upperPos;

    for (int i = 0; i < len; ++i)
    {
        if (isupper(str[i]))
        {
            upperPos.push_back(i);
        }
    }

    // 1. 첫 단어는 소문자인지 검사한다.
    if (upperPos.empty())
    {
        return str;
    }
    // 첫 문자가 대문자인 경우 Java 형식을 위반한다.
    else if (upperPos.front() == 0)
    {
        return "Error!";
    }

    // 2. 다음 단어부터는 첫 문자만 대문자인지 검사한다.
    string part = str.substr(0, upperPos.front()) + '_';

    ret = part;

    for (int i = 0; i < upperPos.size() - 1; ++i)
    {
        part = str.substr(upperPos[i], upperPos[i + 1] - upperPos[i]);
        part[0] = tolower(part[0]);
        ret += part + '_';
    }

    part = str.substr(upperPos.back());
    part[0] = tolower(part[0]);
    ret += part;

    return ret;
}

string CppToJava(const string& str)
{
    string ret, tmp;
    int len = static_cast<int>(str.length());
    vector<string> splits;

    for (int i = 0; i < len; ++i)
    {
        if (str[i] == '_')
        {
            if ((tmp.empty()) || (i == len - 1))
            {
                return "Error!";
            }

            splits.push_back(move(tmp));
            tmp.clear();
        }
        else
        {
            if (isupper(str[i]))
            {
                return "Error!";
            }

            tmp.push_back(str[i]);
        }
    }

    if (!tmp.empty())
    {
        splits.push_back(move(tmp));
    }

    ret = splits[0];

    for (int i = 1; i < splits.size(); ++i)
    {
        splits[i][0] = toupper(splits[i][0]);
        ret += splits[i];
    }

    return ret;
}
