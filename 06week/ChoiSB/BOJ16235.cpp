#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <deque>
#define endl '\n'
// Tree Class
class Tree
{
public:
    Tree(int age) : mAge(age) {}
    int GetAge() const { return mAge; }
    void GrowUp() { mAge++; }
private:
    int mAge;
};

// Node Class
class Node
{
public:
    Node(class Map* map) : mMap(map), mFood(5) {} // 처음에 양분은 모든 칸에 5만큼 들어있다.
    void SetFoodSupply(int food) { mFoodSupply = food; }
    void AddTree(int age) { mTrees.emplace_front(age); }
    int GetNumOfTrees() { return mTrees.size(); }
    void SetPosition(int row, int col) { mRow = row; mCol = col; }
    void UpdateSpring();
    void UpdateSummer();
    void UpdateAutumn();
    void UpdateWinter();
private:
    Map* mMap;
    int mFood{}; // 현재 양분 량
    int mFoodSupply{}; // 매해 양분 공급량
    int mFoodFromDeadTrees{}; // 봄에 죽은 나무로 부터 얻는 양분 
    int mRow{}, mCol{};
    std::deque<Tree> mTrees;
};


// Map Class
class Map
{
public: 
    Map(int N, int M) : mN(N), mM(M) {}
    void InputFoods();
    void InputTrees();
    void UpdateOneYear();
    int GetNumOfTrees();
    void InitNodes();
    void AddTreeAtAdj(int row, int col);
private:

    int mN, mM;
    std::vector<std::vector<Node>> mNodes;

};
void Map::AddTreeAtAdj(int row, int col)
{
    static constexpr std::array<int, 8> dr = { 1,1,0,-1,-1,-1,0,1 };
    static constexpr std::array<int, 8> dc = { 0,1,1,1,0,-1,-1,-1 };

    for (int i = 0; i < 8; ++i)
    {
        // 인접 노드의 row, col
        const int nRow = row + dr[i];
        const int nCol = col + dc[i];
        // map의 범위를 초과할 경우 continue
        if (nRow < 0 || nRow >= mN) continue;
        if (nCol < 0 || nCol >= mN) continue;
        // 조건을 만족할 경우 nRow, nCol 위치에 1살 나무 추가
        mNodes[nRow][nCol].AddTree(1);
    }
}

void Node::UpdateSpring()
{
    auto iter = mTrees.begin();
    // 모든 나무에 양분 제공, 성장
    while (iter != mTrees.end())
    {
        // 양분이 부족할 경우 break
        if (mFood < iter->GetAge()) break;
        mFood -= iter->GetAge();
        iter->GrowUp();
        iter++;
    }
    auto erase_iter = iter;
    // 죽은 나무들로 부터 발생하는 양분 계산
    while (iter != mTrees.end())
    {
        mFoodFromDeadTrees += (int)(iter->GetAge() / 2);
        iter++;
    }
    // 죽은 나무 제거
    mTrees.erase(erase_iter, mTrees.end());
}
void Node::UpdateSummer()
{
    // 죽은 나무로 부터 얻은 양분 추가
    mFood += mFoodFromDeadTrees;
    mFoodFromDeadTrees = 0;
}
void Node::UpdateAutumn()
{
    auto iter = mTrees.begin();
    while (iter != mTrees.end())
    {
        // 나이가 5의 배수일 경우 인접 노드에 나무 추가
        if (iter->GetAge() % 5 == 0)
        {
            // 현재 위치의 인접 위치에 나무 추가
            mMap->AddTreeAtAdj(mRow, mCol);
        }
        iter++;
    }
}
void Node::UpdateWinter()
{
    // 양분 제공
    mFood += mFoodSupply;
}
void Map::InitNodes()
{
    // N * N 노드 생성
    mNodes.resize(mN); 
    for (int r = 0; r < mN; r++)
    {
        mNodes[r].resize(mN, this);
        for (int c = 0; c < mN; c++)
            mNodes[r][c].SetPosition(r, c);
    }     
}
void Map::InputFoods()
{
    for (int r = 0; r < mN; r++)
    {
        for (int c = 0; c < mN; c++)
        {
            // 매해 겨울마다 추가될 양분양 입력
            int supply;
            std::cin >> supply; // 1 ≤ A[r][c] ≤ 100
            mNodes[r][c].SetFoodSupply(supply);
        }
    }
}
void Map::InputTrees()
{
    for (int i = 0; i < mM; ++i)
    {
        // 1 ≤ 입력으로 주어지는 나무의 나이 ≤ 10
        // 입력으로 주어지는 나무의 위치는 모두 서로 다름
        int r, c, age;
        std::cin >> r >> c >> age;
        mNodes[r-1][c-1].AddTree(age);
    }
}
void Map::UpdateOneYear()
{
    // 봄
    for (int r = 0; r < mN; r++)   
        for (int c = 0; c < mN; c++)
            mNodes[r][c].UpdateSpring();
    // 여름
    for (int r = 0; r < mN; r++)
        for (int c = 0; c < mN; c++)
            mNodes[r][c].UpdateSummer();
    // 가을
    for (int r = 0; r < mN; r++)
        for (int c = 0; c < mN; c++)
            mNodes[r][c].UpdateAutumn();
    // 겨울
    for (int r = 0; r < mN; r++)
        for (int c = 0; c < mN; c++)
            mNodes[r][c].UpdateWinter();

}
int Map::GetNumOfTrees()
{
    int retval{};
    for (int r = 0; r < mN; r++)
    {
        for (int c = 0; c < mN; c++)
        {
            retval += mNodes[r][c].GetNumOfTrees();
        }
    }
    return retval;
}

int main()
{    
    //입출력 성능향상을 위한 설정
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int N, M, K; // 1 ≤ N ≤ 10 / 1 ≤ M ≤ N2 / 1 ≤ K ≤ 1, 000
    std::cin >> N >> M >> K;
    Map map(N, M);    // N*N 맵 생성. 나무 개수 M개
    map.InitNodes(); // 노드 초기화
    map.InputFoods(); // 매해 겨울마다 추가될 양분값 입력
    map.InputTrees(); // 나무 정보 입력

    while (K--)
    {   // K해 동안 UpdateOneYear 함수 호출
        map.UpdateOneYear();
    }
    // 남아있는 나무수 출력
    std::cout << map.GetNumOfTrees() << endl;


    return 0;
}