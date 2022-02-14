#include <iostream>
#include <map>
#include <array>
#include <algorithm>
#include <vector>
#define endl '\n'

using Mat = std::array<std::array<int, 101>, 101>;
void PrintMat(const Mat& mat, int row, int col)
{
    std::cout << "row: " << row << " col: " << col << endl;
    for (int i = 0; i <= row; ++i)
    {
        for (int j = 0; j <= col; ++j)
        {
            std::cout << mat[i][j] << " ";
        }
        std::cout << endl;
    }
    std::cout << endl;
}
void SortOneLine(std::map<int, int>& map, std::vector<std::pair<int, int>>& vec)
{
    vec.reserve(map.size());

    auto iter = map.begin();
    while (iter != map.end() && vec.size() < 50)
    {
        vec.push_back(*iter);
        iter++;
    }
    auto comp = [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
    {
        if (lhs.second < rhs.second) return true;
        else if (lhs.second == rhs.second && lhs.first < rhs.first) return true;
        return false;
    };
    std::sort(vec.begin(), vec.end(), comp);
}
void OperatorC(Mat& mat, int& row, int& col)
{

    row = 0;
    for (int i = 1; i <= col; ++i)
    {
        std::map<int, int> map;
        for (int j = 1; j <= mat[0][i]; j++)
        {
            if (mat[j][i] == 0) continue;
            map[mat[j][i]]++;
            mat[j][i] = 0;
        }

        mat[0][i] = std::min((int)(map.size() * 2), 100);
        std::vector<std::pair<int, int>> vec;
        SortOneLine(map, vec);

        for (int j = 1; j <= mat[0][i]; j += 2)
        {
            mat[j][i] = vec[j / 2].first;
            mat[j+1][i] = vec[j / 2].second;
        }

        row = std::max(row, mat[0][i]);

        for (int j = 1; j <= mat[0][i]; ++j)
        {
            mat[j][0] = i;
        }
    }

}
void OperatorR(Mat& mat, int& row, int& col)
{
    col = 0;
    for (int i = 1; i <= row; ++i)
    {
        std::map<int, int> map;
        for (int j = 1; j <= mat[i][0]; j++)
        {
            if (mat[i][j] == 0) continue;
            map[mat[i][j]]++;
            mat[i][j] = 0;
        }
        mat[i][0] = std::min((int)(map.size() * 2), 100);
        std::vector<std::pair<int, int>> vec;
        SortOneLine(map, vec);

        for (int j = 1; j <= mat[i][0]; j += 2)
        {
            mat[i][j] = vec[j / 2].first;
            mat[i][j + 1] = vec[j / 2].second;
        }
        col = std::max(col, mat[i][0]);
        for (int j = 1; j <= mat[i][0]; ++j)
        {
            mat[0][j] = i;
        }

    }
}

void MatSort(Mat& mat, int& row, int &col)
{
    if (row >= col)
        OperatorR(mat, row, col);
    else
        OperatorC(mat, row, col);
}

int main()
{    
    //입출력 성능향상을 위한 설정
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    Mat mat{};
    int r, c, k; // (1 ≤ r, c, k ≤ 100)
    std::cin >> r >> c >> k;
    for (int i = 1; i < 4; ++i)
    {
        for (int j = 1; j < 4; ++j)
        {
            std::cin >> mat[i][j];
        }
    }
    for (int i = 1; i <= 100; ++i)
    {
        mat[0][i] = 3;
        mat[i][0] = 3;
    }
    int row, col;
    row = col = 3;
    int answer{};
    while (mat[r][c] != k)
    {
        answer++;
        if (answer > 101)
        {
            answer = -1;
            break;
        }
        MatSort(mat, row, col);
    }
    
    std::cout << answer << endl;
    return 0;
}