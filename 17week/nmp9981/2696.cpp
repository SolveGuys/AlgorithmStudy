#include <iostream>
#include <queue>
using namespace std;

int t,n,x;
//중앙값 구하기
void medi(){
	priority_queue<int> max_pq;
	priority_queue<int,vector<int>,greater<int>> min_pq;
	
	cin>>n;
	cout<<n/2+1<<"\n";//중앙값 개수
	for(int i=1;i<=n;i++){
		//원소 넣기
		cin>>x;
		if(max_pq.size()==min_pq.size()){
			max_pq.push(x);
		}else{
			min_pq.push(x);
		}
		//원소가 1개인 경우
		if(min_pq.empty()){
			cout<<max_pq.top()<<" ";
			continue;
		}
		//swap
		if(max_pq.top()>min_pq.top()){
			int temp = max_pq.top();
			max_pq.pop();
			max_pq.push(min_pq.top());
			min_pq.pop();
			min_pq.push(temp);
		}
		//중앙값 구하기
		if(i%2==1){
			cout<<max_pq.top()<<" ";
		}
		//출력이 10개 이상인가?
		if(i%20==0){
			cout<<"\n";
		}
	}
}

int main(){
	cin>>t;
	while(t--){
		medi();//중앙값 구하기
	}
	return 0;
}
