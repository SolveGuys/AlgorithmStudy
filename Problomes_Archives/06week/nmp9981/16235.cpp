#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

using namespace std;//이름공간 선언
const int maxi = 11;
const int inf = -1001;
int n,m,k;
int A[maxi][maxi];//추가 양분
int food[maxi][maxi];//양분
vector<int> tree[maxi][maxi];//나무
int dx[8] = {0,0,-1,1,-1,-1,1,1};//축이동
int dy[8] = {1,-1,0,0,1,-1,1,-1};

//입력
void input(){
	cin>>n>>m>>k;//지도 크기,나무 개수,년도
	//양분 초기값
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			food[i][j] = 5;
			tree[i][j].clear();//나무 연령 초기화
		}
	}
	//추가 양분 입력
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>A[i][j];
		}
	}
	//나무 심기
	for(int i=0;i<m;i++){
		int x,y,t;
		cin>>x>>y>>t;
		tree[x][y].push_back(t);
	}
}

//봄,여름
void spring_summer(){
	queue<pair<pair<int,int>,int>> died;//죽은나무 모음
	//나이어린순으로 정렬
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sort(tree[i][j].begin(),tree[i][j].end());
		}
	}
	//양분을 먹기
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//나무가 존재
			if(tree[i][j].size()>0){
				//어린것부터 먹임
				for(int k=0;k<tree[i][j].size();k++){
					//양분 섭취 가능
					if(food[i][j]>=tree[i][j][k]){
						food[i][j]-=tree[i][j][k];
						tree[i][j][k]+=1;//나이 증가
					}else{
						//죽은 나무처리
						died.push({{i,j},tree[i][j][k]});//위치,나이
						tree[i][j].erase(tree[i][j].begin()+k);
						k--;
					}
				}
			}
		}
	}
	//죽은나무가 존재하면 양분 추가공급
	while(!died.empty()){
		int d_x = died.front().first.first;
		int d_y = died.front().first.second;
		int d_age = died.front().second;
		food[d_x][d_y]+=(d_age/2);
		died.pop();
	}
}
//가을
void fall(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<tree[i][j].size();k++){
				//나이가 5의 배수라면
				if(tree[i][j][k]%5 == 0 && tree[i][j][k]>0){
					//번식(8방탐색)
					for(int dir=0;dir<8;dir++){
						int nx = i + dx[dir];
						int ny = j + dy[dir];
						//범위내에 들면
						if(nx>0 && nx<=n && ny>0 && ny<=n){
							//번식하기 
							tree[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}
}
//겨울
void winter(){
	//추가 양분 지급
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			food[i][j] += A[i][j];
		}
	}
}

//생존한 나무의 개수 구하기
int survive(){
	int cnt = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cnt+=tree[i][j].size();
		}
	}
	return cnt;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    
    input();//입력
    //시간증가
    for(int ti=1;ti<=k;ti++){
    	spring_summer();
    	fall();
    	winter();
    }
    cout<<survive();//생존한 나무의 개수
    return 0;
}
