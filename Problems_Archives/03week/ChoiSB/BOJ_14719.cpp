#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

void InputData(int& H, int& W, vector<int>& blocks)
{
    cin >> H >> W;
    blocks.resize(W);
    for (int i = 0; i < W; ++i)
    {
        cin >> blocks[i];
    }
}
int Solve(const int H, const int W, const vector<int>& blocks)
{
    int retval{};
    const auto maxIter = max_element(blocks.begin(), blocks.end());
    const int maxIdx = distance(blocks.begin(), maxIter);

    // 왼쪽에서 오른쪽으로 탐색. (시작점에서 가장큰 블록이 있는곳 까지)
    int left = blocks.front();
    int temp{};
    for (int i = 1; i <= maxIdx; i++)
    {
        if (left > blocks[i])
        {
            temp += left - blocks[i];
        }
        else
        {
            retval += temp;
            left = blocks[i];
            temp = 0;
        }
    }
    // 오른쪽에서 왼쪽으로 탐색. (시작점에사 가장 큰 블록이 있는곳 까지)
    int right = blocks.back();
    temp = 0;
    for (int i = W - 2; i >= maxIdx; i--)
    {
        if (right > blocks[i])
        {
            temp += right - blocks[i];
        }
        else
        {
            retval += temp;
            right = blocks[i];
            temp = 0;
        }
    }

    return retval;
}
int main()
{
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int H, W; // (1 ≤ H, W ≤ 500)
    vector<int> blocks;
    InputData(H, W, blocks);
    int answer = Solve(H, W, blocks);
    cout << answer;
    return 0;
}