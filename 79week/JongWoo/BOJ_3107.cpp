#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ip;

    cin >> ip;

    // Parsing
    vector<string> v;
    string tmp;
    int len = static_cast<int>(ip.length());

    for (int i = 0; i < len; ++i)
    {
        if (ip[i] == ':')
        {
            if (!tmp.empty())
            {
                v.push_back(tmp);
                tmp.clear();
            }

            if ((i <= len - 2) && (ip[i + 1] == ':'))
            {
                v.push_back("::");
                ++i;
                continue;
            }
        }
        else
        {
            tmp.push_back(ip[i]);
        }
    }

    if (!tmp.empty())
    {
        v.push_back(tmp);
    }

    string answer;
    int numCnt = v.size() - 1; // - 1: ::

    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == "::")
        {
            // cnt: 2번 조건에 의해 생략된 그룹의 수
            // cnt = 전체 개수 - 처리하지 않은 숫자의 개수 - 처리한 숫자의 개수
            int cnt = 8 - (numCnt - i) - i;

            for (int j = 0; j < cnt; ++j)
            {
                answer += "0000:";
            }
        }
        else
        {
            answer += string(4 - v[i].length(), '0') + v[i] + ':';
        }
    }

    answer.pop_back(); // :
    cout << answer << '\n';
}
