#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxi = 101;
int parents[maxi];

//비용 기준 정렬
bool cmp(vector<int> a,vector<int> b){
    if(a[2] == b[2]) return a[0]<b[0];//비용이 같으면
    return a[2]<b[2];
}
//초기화
void init(int n){
    for(int i=0;i<n;i++) parents[i] = i;
}
//부모 노드
int find(int x){
    if(parents[x] == x) return parents[x];//자기 자신이 루트 노드
    parents[x] = find(parents[x]);
    return parents[x];
}
//노드 연결
void connect(int a,int b){
    if(b>a) parents[b] = a;
    else parents[a] = b;
}
//크루스칼 알고리즘
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int node = 0;
    init(n);//초기화
    sort(costs.begin(),costs.end(),cmp);//정렬
    for(int i=0;i<costs.size();i++){
        int x = costs[i][0];//시작
        int y = costs[i][1];//끝
        int fee = costs[i][2];//비용
        
        int a = find(x);//x의 부모 노드
        int b = find(y);//y의 부모 노드
        if(a!=b){
            connect(a,b);//노드 연결
            answer+=fee;//비용 누적
            node++;//연결한 노드의 수 증가
        }
        
        //노드 연결완료
        if(node == n-1){
            break;
        }
    }
    return answer;
}
