#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define endl '\n'
using namespace std;

int N, M; //세로 크기 N과 가로 크기 M (1 ≤ N, M ≤ 8)
vector<vector<int>> map;
vector<struct Cam> cam;

//0:→ 1:↓ 2:← 3:↑
const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { 1, 0, -1, 0 };

struct Pos {
    Pos() {}
    Pos(int _r, int _c) : r{ _r }, c{ _c } {}
    int r{};
    int c{};
};
class Cam {
public:
    Cam(Pos _pos, int _t);
    void Rotate(); // 카메라 회전
    void Init();   // 맵에 카메라 설치(초기화)
    int GetRCnt() { return rCnt; }
private:
    Pos pos;
    int t;
    int rCnt;
    vector<int> dir;
    void view(); // dir 방향으로 체킹
    void clear(); // dir 방향으로 체킹 해제 
};
Cam::Cam(Pos _pos, int _t) : pos{ _pos }, t{ _t }, dir{}
{
    if (_t == 1)
    {
        rCnt = 3;
        dir.push_back(0); // 0:→
    }
    else if (_t == 2)
    {
        rCnt = 1;
        dir.push_back(0); // 0:→
        dir.push_back(2); // 2:←
    }
    else if (_t == 3)
    {
        rCnt = 3;
        dir.push_back(0); // 0:→
        dir.push_back(3); // 3:↑
    }                        
    else if (_t == 4)        
    {                        
        rCnt = 3;            
        dir.push_back(0); // 0:→
        dir.push_back(2); // 2:←
        dir.push_back(3); // 3:↑
    }
    else
    {
        rCnt = 0;
        dir.push_back(0); // 0:→
        dir.push_back(1); // 1:↓
        dir.push_back(2); // 2:← 
        dir.push_back(3); // 3:↑ 
    }
}
void Cam::Rotate()
{
    clear();
    for (int& d : dir)
    {
        d++;
        d %= 4;
    }
    view();
}
void Cam::Init()
{
    view();
}
void Cam::view()
{
    for (int i : dir)
    {
        Pos next{ pos.r + dr[i], pos.c + dc[i] };
        while (map[next.r][next.c] >= 0)
        {
            map[next.r][next.c]++;
            next.r += dr[i];
            next.c += dc[i];
        }
    }
}
void Cam::clear()
{
    for (int i : dir)
    {
        Pos next{ pos.r + dr[i], pos.c + dc[i] };
        while (map[next.r][next.c] >= 0)
        {
            map[next.r][next.c]--;
            next.r += dr[i];
            next.c += dc[i];
        }
    }
}
void PrintMap()
{
    for (int i = 0; i < N + 2; ++i)
    {
        for (int j = 0; j < M + 2; ++j)
        {
            cout << setw(2) <<map[i][j] << " ";
        }
        cout << endl;
    }
}

int EmptyCnt()
{
    int retval{};
    for (int i = 1; i < N + 1; ++i)
    {
        for (int j = 1; j < M + 1; ++j)
        {
            if (map[i][j] == 0)
                retval++;
        }
    }
    //cout << retval << "▼" << endl;
    //PrintMap();
    //cout << endl;
    return retval;
}

int BT(int idx)
{
    if (idx == cam.size())
        return EmptyCnt();
    
    int rCnt = cam[idx].GetRCnt();
    // 초기 방향으로 탐색
    int retval = BT(idx + 1);
    // 회전가능하다면 회전 후 탐색
    for (int i = 0; i < rCnt; ++i)
    {
        cam[idx].Rotate();
        retval = min(retval, BT(idx + 1));
    }
    return retval;
}

int main()
{
    //입출력 성능향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> M;
    map.resize(N + 2);
    map[0].resize(M + 2, -9);
    map[N + 1].resize(M + 2, -9);

    for (int i = 1; i < N + 1; ++i)
    {
        map[i].resize(M + 2 , -9);
        for (int j = 1; j < M + 1; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == 6)
                map[i][j] = -9;
            else if (map[i][j] != 0)
            {
                cam.emplace_back(Pos(i, j), map[i][j]);
                map[i][j] += 10;
            }
        }
    }
    for (auto& c : cam)
    {
        c.Init();
    }
    cout << BT(0);

    return 0;
}