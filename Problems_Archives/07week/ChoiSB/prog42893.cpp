#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
using PagesMap = map<string, class PageInfo*>;

// 입력받은 문자열을 모두 소문자로 변환
void ToSmall(string& str)
{
    const int diff = 'A' - 'a';
    for(char& c : str)
        if('A' <= c && c <= 'Z')
            c -= diff;
}
// str[pos] 부터 하나의 알파벳 단어 추출. 
string GetWord(const string& str, int& pos)
{
    string retval;
    if(pos >= str.size()) return retval;

    while(pos < str.size())
    {
        if('a' <= str[pos] && str[pos] <= 'z')
        {
            retval += str[pos];
            pos++;

        }else //특수문자를 만나면 break
            break;
    }
    // str이 특수문자로 시작한 경우
    if(retval.size() == 0)
    {
            retval += str[pos];
            pos++;
    }
    return retval;
}
class PageInfo{
public:
    PageInfo(PagesMap& pages_map, string page, int idx);
    void AddExternalLinks();
    void CalBasicPoint(const string& target);
    void CalLinkPoint();
    int GetIndex() const {return mIdx;}
    double GetMatchingPoint() const {return mMatchingPoint;}
private:
    // method
    void RegisterURL();
    void AddMatchingPoint(double amount) {mMatchingPoint += amount;}

    // attributes
    PagesMap& mPagesMap;
    string mHtml;
    int mIdx{};
    int mBasicPoint{};
    double mMatchingPoint{};
    vector<PageInfo*> mLinks{};

};
PageInfo::PageInfo(PagesMap& pages_map, string page, int idx) 
    : mPagesMap(pages_map), mHtml(move(page)), mIdx(idx)
{
    RegisterURL();
}

void PageInfo::CalLinkPoint()
{
    double linkPoint = (double) mBasicPoint / (double) mLinks.size();
    for(PageInfo* link : mLinks)
    {
        if(link != nullptr)
        {
            //cout << mIdx << "가 " <<link->mIdx << "에 링크점수 " << linkPoint << "점 추가 "<< endl; 
            link->AddMatchingPoint(linkPoint);
        }
    }
}
void PageInfo::AddExternalLinks()
{
    string a_str("<a href=\"https://");
    int start_pos{};
    while((start_pos = mHtml.find(a_str, start_pos)) != string::npos)
    {
        start_pos += a_str.size();
        int end_pos = mHtml.find("\">", start_pos);
        string URL(mHtml, start_pos, end_pos - start_pos);
        auto iter = mPagesMap.find(URL);
        if(iter != mPagesMap.end())
        {
            // Pages Map에 등록된 링크라면 해당 링크의 주소를 mLinks 배열에 저장
            mLinks.push_back(iter->second);
        }
        else
        {
            // Pages Map에 등록되지 않은 링크는 mLinks 배열에 nullptr로 저장
            mLinks.push_back(nullptr);
        }
    }
}
void PageInfo::RegisterURL()
{    
    // URL 추출
    string meta_str("<meta property=\"og:url\" content=\"https://");
    int start_pos = mHtml.find(meta_str);
    start_pos += meta_str.size();
    int end_pos = mHtml.find("\"/>", start_pos);
    string URL(mHtml, start_pos, end_pos - start_pos);
    // 추출한 URL을 map에 등록
    mPagesMap[URL] = this;    
}
void PageInfo::CalBasicPoint(const string& target)
{
    int pos{};
    string word;
    while((word = GetWord(mHtml, pos)) != "")
    {
        if(word == target)// word를 발견한 경우
            mBasicPoint++;
    }
    mMatchingPoint += (double) mBasicPoint;
    //cout << mBasicPoint << endl;
}
int solution(string word, vector<string> pages) {
    int answer = 0;
    PagesMap pages_map;
    // 주어진 입력을 모두 소문자로 변환
    ToSmall(word);
    for(string& html : pages)
        ToSmall(html);

    // PageInfo 생성
    vector<PageInfo> page_infos;
    page_infos.reserve(pages.size());
    for(int i = 0 ; i < pages.size(); ++i)
    {
        page_infos.emplace_back(pages_map, move(pages[i]), i);
    }

    for(auto& info : page_infos)
    {
        // 외부링크 연결
        info.AddExternalLinks();
    }
    for(auto& info : page_infos)
    {
        // 기본 점수 계산
        info.CalBasicPoint(word);
        // 링크 점수 계산
        info.CalLinkPoint();
    }

    auto comp = [](const PageInfo& lhs, const PageInfo& rhs)
    {
        if(lhs.GetMatchingPoint() < rhs.GetMatchingPoint()) return true;
        else if(lhs.GetMatchingPoint() == rhs.GetMatchingPoint() &&
               lhs.GetIndex() > rhs.GetIndex()) return true;
        else return false;
    };
    auto iter = max_element(page_infos.begin(), page_infos.end(), comp);
    answer = iter->GetIndex();
    return answer;
}