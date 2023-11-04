#include <string>
#include <vector>
using namespace std;

string answer = "";
vector<int> num;
int trans[3] = {4,1,2};

string solution(int n) {
    //숫자 구하기
    while(n>0){
        num.push_back(trans[n%3]);
        n = (n-1)/3;
    }
    //문자열을 원래대로
    for(int i=num.size()-1;i>=0;i--) answer+=to_string(num[i]);
    return answer;
}
