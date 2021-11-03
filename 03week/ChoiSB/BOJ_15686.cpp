#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
constexpr int INF = 87'654'321;
struct Pos
{
    Pos(int _r, int _c) : r{ _r }, c{ _c }{}
    Pos() {}
    int r;
    int c;
};
struct Chicken
{
    Chicken(int _r, int _c) : pos{ _r, _c } {}
    Pos pos;
    bool selected{};
};

void InputData(vector<Pos>& houses, vector<Chicken>& chickens, int N)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
                houses.emplace_back(i, j);
            else if (temp == 2)
                chickens.emplace_back(i, j);
        }
    }
}
int GetMinDistance(const Pos& house, const vector<Chicken>& chickens)
{
    const int r = house.r;
    const int c = house.c;
    int retval{ INF };
    for (const auto& chicken : chickens)
    {
        if (chicken.selected == false) continue;
        retval = min(retval, abs(r - chicken.pos.r) + abs(c - chicken.pos.c));
    }
    return retval;
}

int CityChickenDist(vector<Pos>& houses, vector<Chicken>& chickens)
{
    int retval{};
    for (const auto& house : houses)
    {
        const int result = GetMinDistance(house, chickens);
        retval += result;
    }            
    return retval;
}

int BT(vector<Pos>& houses, vector<Chicken>& chickens, int idx, int numOfChicken, int M)
{
    int retval{ INF };
    if (numOfChicken == M)
    {
        retval = CityChickenDist(houses, chickens);
        return retval;
    }
    for (size_t i = idx; i < chickens.size(); ++i)
    {
        // i번째 치킨집을 이미 탐색했다면 continue
        if (chickens[i].selected == true) continue;

        // i번째 치킨집 선택
        chickens[i].selected = true;

        // 다음 탐색 
        retval = min(retval, BT(houses, chickens, i + 1, numOfChicken + 1, M));

        // i번째 치킨집 복구
        chickens[i].selected = false;
    }
    return retval;
}
int main()
{
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, M; // N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)
    cin >> N >> M;
    vector<Chicken> chickens;
    vector<Pos> houses;
    InputData(houses, chickens, N);

    int answer = BT(houses, chickens, 0, 0, M);
    cout << answer << endl;

    return 0;
}