#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

const int maxi = 500001;
int plusStart[maxi];//+1을 먼저 곱하기 시작
int minusStart[maxi];//-1을 먼저 곱하기 시작
ll plusSum[maxi];//+1을 먼저 곱한 누적합
ll minusSum[maxi];//-1을 먼저 곱한 누적합

//max
inline ll max(ll x,ll y){
    return x>y?x:y;
}
//펄스 수열 곱하기
void PerseProduct(vector<int> &s){//참조로 매개변수를 받음
    for(int i=0;i<s.size();i++){
        plusStart[i] = s[i]*pow(-1,i+2);
        minusStart[i] = s[i]*pow(-1,i+1);
    }
    //누적합
    plusSum[0] = plusStart[0];minusSum[0] = minusStart[0];
    for(int i=1;i<s.size();i++){
        plusSum[i] = plusSum[i-1]+plusStart[i];
        minusSum[i] = minusSum[i-1]+minusStart[i];
    }
}
//펄스 부분 수열 합구하기
ll PerseSubSum(int maxSize){
    //부분 수열 오른쪽
    ll plusRight = plusSum[0];ll minusRight = minusSum[0];//합
    int plusRightIndex = 0;int minusRightIndex = 0;//위치
    for(int i=1;i<maxSize;i++){
        if(plusRight<plusSum[i]) {
            plusRight = plusSum[i];
            plusRightIndex = i;
        }
        if(minusRight<minusSum[i]) {
            minusRight = minusSum[i];
            minusRightIndex = i;
        }
    }
    //부분 수열 왼쪽
    ll plusLeft = 0;ll minusLeft = 0;//합
    for(int i=0;i<plusRightIndex ;i++){
        if(plusLeft>plusSum[i]) plusLeft = plusSum[i];
    }
    for(int i=0;i<minusRightIndex ;i++){
        if(minusLeft>minusSum[i]) minusLeft = minusSum[i];
    }
    //최종 결과
    return max(plusRight-plusLeft, minusRight-minusLeft);
}
long long solution(vector<int> sequence) {
    PerseProduct(sequence);//펄스 수열 곱하기
    return PerseSubSum(sequence.size());//펄스 부분 수열 합 구하기
}
