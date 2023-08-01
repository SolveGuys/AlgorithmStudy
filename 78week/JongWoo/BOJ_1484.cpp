#include <iostream>
#include <vector>

using namespace std;

int g;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> g;

    vector<int> answer;
    int en = 1;

    for (int st = 1; st < g; ++st)
    {
        while ((en < g) && (en * en - st * st < g))
        {
            ++en;
        }

        if (en == g)
        {
            break;
        }

        if (en * en - st * st == g)
        {
            answer.push_back(en);
        }
    }

    if (answer.empty())
    {
        cout << -1 << '\n';
    }
    else
    {
        for (int w : answer)
        {
            cout << w << '\n';
        }
    }
}
