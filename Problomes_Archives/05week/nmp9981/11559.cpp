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
char maps[12][6];
int visit[12][6];//방문 기록
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int ans = 0;//연쇄 폭발 횟수

//입력
void input(){
	for(int i=0;i<12;i++){
		for(int j=0;j<6;j++){
			cin>>maps[i][j];
		}
	}
}

//초기화
void init(){
	for(int i=0;i<12;i++){
		for(int j=0;j<6;j++){
			visit[i][j] = 0;
		}
	}
}

//bfs탐색
bool bfs(int x,int y){
	init();//방문지점 초기화
	char color = maps[x][y];
	int cnt = 0;//개수 체크
	bool flag = false;//폭발이 일어나는가?
	visit[x][y] = 1;//방문체크
	queue<pair<int,int>> q;
	queue<pair<int,int>> boom;//폭발한 위치를 담는 큐
	q.push({x,y});
	boom.push({x,y});
	
	while(!q.empty()){
		int cx = q.front().first;
		int cy = q.front().second;
		cnt++;//개수 세기
		q.pop();
		
		//다음지점 탐색
		for(int i=0;i<4;i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			//범위내에 있고 미방문,색깔이 같으면
			if(nx>=0 && nx<12 && ny>=0 && ny<6){
				if(maps[nx][ny]==color && visit[nx][ny]==0){
					visit[nx][ny] = 1;//방문체크
					q.push({nx,ny});
					boom.push({nx,ny});//좌표 넣기
				}
			}
		}
	}
	
	//폭발이 일어나는가?
	if(cnt>=4){
		flag = true;
		//터졌으니 빈공간으로
		while(!boom.empty()){
			int bx = boom.front().first;
			int by = boom.front().second;
			maps[bx][by] = '.';
			boom.pop();
		}
	}
	return flag;
}

//내리기
void godown(){
	for(int j=0;j<6;j++){
		for(int i=11;i>=0;i--){
			if(maps[i][j] == '.'){
				//.가 안나올때까지
				for(int k=i-1;k>=0;k--){
					if(maps[k][j] != '.'){
						maps[i][j] = maps[k][j];
						maps[k][j] = '.';
						break;
					}
				}
			}
		}
	}
}

//뿌요뿌요
void puyo(){
    //연쇄가 일어나지 않을때까지 탐색
    while(true){
    	bool boom_flag = false;//터졌는가?
    	//맵 탐색
    	for(int i=11;i>=0;i--){
    		for(int j=0;j<6;j++){
    			if(maps[i][j] != '.'){
    				if(bfs(i,j)==true){
    						boom_flag = true;
    					}
    				}
    		}
    	}
    	//연쇄 폭발이 이루어 졌으면 한번 더
    	if(boom_flag == true){
    		godown();//내리기
    		ans++;
    	}else{
    		break;//반목문 종료
    	}
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    
    input();//입력
    puyo();//탐색하기
    cout<<ans;//출력
    return 0;
}
