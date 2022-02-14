#include <iostream>
#include <vector>
#include <algorithm>
constexpr int monToInt[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

int DayToInt(int mm, int dd)
{
    int retval{};
    retval += monToInt[mm];
    retval += dd;
    return retval;
}

struct Flower {
    int begin{};
    int end{};
    bool operator<(const Flower& other)
    {
        if (begin < other.begin) return true;
        else if (begin == other.begin) return end < other.end;

        return false;
    }
};
int main()
{
    //입출력 성능향상을 위한 설정
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int N; // N(1 ≤ N ≤ 100, 000)
    std::cin >> N;
    std::vector<Flower> flowers(N);
    for (int i = 0; i < N; ++i)
    {
        int mm, dd;
        std::cin >> mm >> dd;
        flowers[i].begin = DayToInt(mm, dd);
        std::cin >> mm >> dd;
        flowers[i].end = DayToInt(mm, dd);
    }
    sort(flowers.begin(), flowers.end());

    // 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상 피어 있도록

    int answer{};
    int cur{};
    cur = DayToInt(3, 1);

    int i = 0;
    while (cur <= DayToInt(11, 30))
    {
        int prev = cur;
        bool bValid = false;
        for (; i < N && flowers[i].begin <= prev; i++)
        {
            if (cur < flowers[i].end)
            {
                cur = flowers[i].end;
                bValid = true;
            }
        }
        if (bValid == false)
        {
            answer = 0;
            break;
        }
        answer++;
    }
    std::cout << answer << '\n';
}