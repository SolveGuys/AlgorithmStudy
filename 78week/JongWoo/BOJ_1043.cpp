#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n, m;

// 진실을 아는 사람의 수와 번호
int k;
unordered_set<int> knows;

// 각 파티에 오는 사람의 번호
vector<vector<int>> parties;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> k;

    for (int i = 0; i < k; ++i)
    {
        int num = 0;

        cin >> num;
        knows.insert(num);
    }

    for (int i = 0; i < m; ++i)
    {
        int cnt = 0;

        cin >> cnt;
        
        vector<int> party(cnt);
        bool isFound = false;

        for (int j = 0; j < cnt; ++j)
        {
            cin >> party[j];

            if (knows.find(party[j]) != knows.end())
            {
                isFound = true;
            }
        }

        if (isFound)
        {
            for (int num : party)
            {
                knows.insert(num);
            }
        }
        else
        {
            parties.push_back(move(party));
        }
    }

    int answer = 0;

    for (const auto& party : parties)
    {
        bool isFound = false;

        for (int num : party)
        {
            if (knows.find(num) != knows.end())
            {
                isFound = true;
                break;
            }
        }

        if (!isFound)
        {
            ++answer;
        }
    }

    cout << answer << '\n';
}
