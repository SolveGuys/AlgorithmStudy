#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <set>
#include <cmath>
const std::array<std::string, 5> numbers
{
    "###...#.###.###.#.#.###.###.###.###.###",
    "#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
    "#.#...#.###.###.###.###.###...#.###.###",
    "#.#...#.#.....#...#...#.#.#...#.#.#...#",
    "###...#.###.###...#.###.###...#.###.###"
};

void AddCandidate(int pos, std::vector<int>& candidate, std::array<std::string, 5>& number_plate, int N)
{
    for (int n = 0; n < 10; n++)
    {
        bool is_candidate = true;
        for (int r = 0; r < 5; ++r)
        {
            for (int c = 0; c <  3; c++)
            {
                if (numbers[r][c + (n * 4)] == '.' && number_plate[r][c + (pos * 4)] == '#')
                {
                    is_candidate = false;
                    goto is_not_candidate; // 다중 반복문시 break 대신 사용할 수 있습니다. 
                }
            }
        }
    is_not_candidate:

        if (is_candidate)
            candidate.push_back(n * (int)std::pow(10, N - pos - 1));
    }
}

int main()
{
    //입출력 성능향상을 위한 설정
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    std::array<std::string, 5> number_plate;
    std::vector<std::vector<int>> candidate_numbers;
    int N; // N은 9보다 작거나 같은 자연수

    std::cin >> N;
    candidate_numbers.resize(N);
    for (int i = 0; i < 5; i++)
        std::cin >> number_plate[i];

    long long cnt = 1;
    for (int i = 0; i < N; ++i)
    {
        AddCandidate(i, candidate_numbers[i], number_plate, N);
        cnt *= candidate_numbers[i].size();
    }
    if (cnt == 0)
    {
        // 가능한 층 번호가 없음.
        std::cout << -1 << '\n';
        return 0;
    }

    long long sum{};
    for (int i = 0; i < N; ++i)
    {
        long long temp{};
        for (int c : candidate_numbers[i])
        {
            temp += c;
        }
        sum += temp * (cnt / candidate_numbers[i].size());
    }
   
    double answer = sum / (double)cnt;

    std::cout << answer << '\n';
    return 0;
}