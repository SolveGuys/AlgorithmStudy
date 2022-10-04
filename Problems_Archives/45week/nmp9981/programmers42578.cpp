#include <string>
#include <vector>
#include <map>
using namespace std;

map<string,int> wear;//옷의 종류, 개수

int solution(vector<vector<string>> clothes) {
    int answer = 1;//곱셈 항등원
    for(int i=0;i<clothes.size();i++) wear[clothes[i][1]]++;//옷 종류별로 구분
    for(auto iter : wear) answer*=(iter.second+1);//각 옷을 안입는 경우 포함하는 경우의 수
    return answer-1;//모두 안입는 경우 제외
}
