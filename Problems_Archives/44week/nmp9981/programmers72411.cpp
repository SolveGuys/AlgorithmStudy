#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int maxi = 11;const int maxiOrders = 21;
int maxiCount[maxi];//각 자릿수별 최대 등장 횟수
map<string,int> wordHouse;//각 단어가 몇번 등장했는지
vector<string> menu[maxi][maxiOrders];//단어 string이 몇자리수이고 몇개인가?

//조합 구하기
void WordComb(int idx,string order,string word){
    //조합이 만들어졌다면(길이 2 이상)
    if(word.size()>=2){
        wordHouse[word]++;//단어의 등장횟수 추가
        //각 자릿수별 최대 등장횟수 갱신
        maxiCount[word.size()] = max(maxiCount[word.size()],wordHouse[word]);
        menu[word.size()][wordHouse[word]].push_back(word);//word는 몇자리수이고 몇개인가?
    }
    //다음 지점
    for(int i=idx;i<order.size();i++){
        word.push_back(order[i]);//글자 추가
        WordComb(i+1,order,word);//재귀
        word.pop_back();//글자 제거
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;//정답 벡터
    //조합구하기
    for(string order:orders){
        sort(order.begin(),order.end());//정렬
        WordComb(0,order,"");//order에 대한 조합구하기
    }
    //가장 많이 주문한 메뉴 구하기
    for(int i:course){
        if(maxiCount[i]<2) continue;//길이가 2미만인 것은 제외
        for(string j:menu[i][maxiCount[i]]) answer.push_back(j);//단어 넣기
    }
    sort(answer.begin(),answer.end());//오름차순 출력
    return answer;
}
