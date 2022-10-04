#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

ll sum1,sum2 = 0;
queue<ll> q1,q2;//큐

//큐의 합 구하기
void SumQueue(vector<int> queue1, vector<int> queue2){
    for(int i=0;i<queue1.size();i++){
        q1.push((ll)queue1[i]);//쿠에 넣기
        q2.push((ll)queue2[i]);
        sum1+=(ll)queue1[i];//각 큐의 원소합 구해주기
        sum2+=(ll)queue2[i];
    }
}
int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    SumQueue(queue1,queue2);//총합 구하기
    //큐 나누기
    for(int i=0;i<queue2.size()*5;i++){//횟수
        if(sum1==sum2){
            answer = i;
            break;
        }else if(sum1<sum2){//큐2->큐1
            ll num = q2.front();//맨앞 원소 빼기
            q2.pop();
            q1.push(num);//원소 넣기
            sum2-=num;//합 조정
            sum1+=num;
        }else if(sum1>sum2){//큐1->큐2
            ll num = q1.front();//맨앞 원소 빼기
            q1.pop();
            q2.push(num);//원소 넣기
            sum1-=num;//합 조정
            sum2+=num;
        }
    }
    return answer;
}
