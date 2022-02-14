#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node{
    bool bBoard{};
    bool bColumn{};
};
using Map = vector<vector<Node>>;
class Frame{
public:
    Frame(Map& _map, int _x, int _y, int _type) : mMap(_map), x(_x), y(_y), type(_type){}
    virtual ~Frame() {};
    virtual bool IsValid() = 0;
    bool operator<(const Frame& other);
    bool IsEqual(int _x, int _y, int _type);
    int GetX() const {return x;}
    int GetY() const {return y;}
    int GetType() const {return type;}
protected:
    Map& mMap;
    int x;
    int y;
    int type;
};
bool Frame::IsEqual(int _x, int _y, int _type)
{
    return (x == _x) && (y == _y) && (type == _type);
}
bool Frame::operator<(const Frame& other)
{
    if(x < other.x) return true;
    else if(x == other.x && y < other.y) return true;
    else if(x == other.x && y == other.y && type < other.type) return true;
    return false;
}
class Board : public Frame{
public:
    Board(Map& map, int x, int y);
    ~Board() override;
    bool IsValid() override;
};
Board::Board(Map& map, int x, int y) 
    : Frame(map, x, y, 1) 
{
    //cout << x << "," <<y<<" 에 보 설치" << endl;
    mMap[x][y].bBoard = true;
}
Board::~Board()
{
    //cout << x << "," <<y<<" 에 보 해체" << endl;
    mMap[x][y].bBoard = false;  
}
bool Board::IsValid()
{
    const int N = mMap.size();
    bool retval = false;
    // 왼쪽 아래에 기둥이 있는 경우
    if(y > 0 && mMap[x][y-1].bColumn)
        retval = true;
    // 오른쪽 아래에 기둥이 있는 경우
    else if(y > 0 && x < N - 1 && mMap[x+1][y-1].bColumn)
        retval = true;
    // 양쪽에 보가 있는 경우
    else if(x > 0 && x < N - 1 && mMap[x-1][y].bBoard && mMap[x+1][y].bBoard)
        retval = true;
    //cout << "유효성 검사: "<< x <<"," <<y << " 보 " << retval << endl;
    return retval;
}
class Column : public Frame{
  public:
    Column(Map& map, int x, int y);
    ~Column() override;
    bool IsValid() override;
};
Column::Column(Map& map, int x, int y)
    : Frame(map, x, y, 0) 
{
    //cout << x << "," <<y<<" 에 기둥 설치" << endl;
    mMap[x][y].bColumn = true;       
}
Column::~Column()
{
    //cout << x << "," <<y<<" 에 기둥 해체" << endl;
    mMap[x][y].bColumn = false;
}

bool Column::IsValid()
{
    const int N = mMap.size();
    bool retval = false;
    // 기둥이 바닥인 경우
    if(y == 0)
        retval = true;
    // 기둥 아래에 다른 기둥이 있는 경우
    else if(y > 0 && mMap[x][y-1].bColumn)
        retval = true;
    // 기둥 아래에 보의 왼쪽편이 있는 경우
    else if(mMap[x][y].bBoard)
        retval = true;
    // 기둥 아래에 보의 오른쪽편이 있는 경우
    else if(x > 0 && mMap[x-1][y].bBoard)
        retval = true;

    //cout << "유효성 검사: "<< x <<"," <<y << " 기둥 " << retval << endl;
    return retval;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    Map map(n + 1, vector<Node>(n+1));


    vector<Frame*> frames;
    for(const auto& cmd : build_frame)
    {
        //cout <<"명령: " << cmd[0] << "," << cmd[1] << "에 " << cmd[2] << "를 " << cmd[3] << endl; 

        if(cmd[3] == 0) // 삭제
        {
            auto iter = frames.begin();
            while(iter != frames.end())
            {
                if((*iter)->IsEqual(cmd[0], cmd[1], cmd[2]))
                {
                    //cout << (*iter)->GetX() << "," << (*iter)->GetY() << "발견" << endl;

                    iter_swap(iter, frames.end() - 1);
                    delete frames.back();
                    frames.pop_back();
                    break;
                }
                iter++;
            }
            // 모든 프레임들에 대한 유효성 검사
            for(auto frame : frames)
            {
                // 유효하지 않은 명령이라면 복구
                if(frame->IsValid() == false)
                {
                    if(cmd[2] == 0)// 기둥
                        frames.emplace_back(new Column(map, cmd[0], cmd[1]));
                    else    // 보
                        frames.emplace_back(new Board(map, cmd[0], cmd[1]));                    
                    break;
                }
            }

        }
        else // 설치
        {
            if(cmd[2] == 0)// 기둥
                frames.emplace_back(new Column(map, cmd[0], cmd[1]));
            else    // 보
                frames.emplace_back(new Board(map, cmd[0], cmd[1]));

            // 유효성 검사
            if(frames.back()->IsValid() == false)
            {
                delete frames.back();
                frames.pop_back();
            }

        }
    }

    auto comp = [](Frame* lhs, Frame* rhs)
    {
        return (*lhs) < (*rhs);  
    };
    sort(frames.begin(), frames.end(), comp);
    answer.reserve(frames.size());
    for(auto frame : frames)
    {
        answer.push_back({frame->GetX(), frame->GetY(), frame->GetType()});
        delete frame; // 동적할당한 frame들 해제
    }
    return answer;
}