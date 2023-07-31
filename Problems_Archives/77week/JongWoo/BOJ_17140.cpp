#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int r, c, k;
int row, col;
int arr[201][201];

void Rsort();
void Csort();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> k;
    row = col = 3;

    for (int i = 1; i <= row; ++i)
    {
        for (int j = 1; j <= col; ++j)
        {
            cin >> arr[i][j];
        }
    }

    int answer = 0;

    while ((answer <= 100) && (arr[r][c] != k))
    {
        if (row >= col)
        {
            Rsort();
        }
        else
        {
            Csort();
        }

        ++answer;
    }

    cout << ((answer > 100) ? -1 : answer) << '\n';
}

void Rsort()
{
    int maxCol = 0;

    for (int i = 1; i <= row; ++i)
    {
        int freq[101] = {};
        set<pair<int, int>> s; // <freq, index>

        for (int j = 1; j <= col; ++j)
        {
            ++freq[arr[i][j]];
        }

        for (int j = 1; j <= 100; ++j)
        {
            arr[i][j] = 0;

            if (freq[j] > 0)
            {
                s.emplace(freq[j], j);
            }
        }

        int j = 1;

        for (const auto& p : s)
        {
            arr[i][j] = p.second;
            arr[i][j + 1] = p.first;
            j += 2;
        }

        maxCol = max(maxCol, 2 * static_cast<int>(s.size()));
    }

    col = maxCol;
}

void Csort()
{
    int maxRow = 0;

    for (int i = 1; i <= col; ++i)
    {
        int freq[101] = {};
        set<pair<int, int>> s; // <freq, index>

        for (int j = 1; j <= row; ++j)
        {
            ++freq[arr[j][i]];
        }

        for (int j = 1; j <= 100; ++j)
        {
            arr[j][i] = 0;

            if (freq[j] > 0)
            {
                s.emplace(freq[j], j);
            }
        }

        int j = 1;

        for (const auto& p : s)
        {
            arr[j][i] = p.second;
            arr[j + 1][i] = p.first;
            j += 2;
        }

        maxRow = max(maxRow, 2 * static_cast<int>(s.size()));
    }

    row = maxRow;
}
