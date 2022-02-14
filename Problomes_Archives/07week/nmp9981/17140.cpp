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

int r,c,k;
int col_size,row_size;//행,열 사이즈
const int maxi = 101;//최대 크기
int A[maxi][maxi];//A배열

//입력
void input(){
	cin>>r>>c>>k;
	col_size = 3;//초기 배열 사이즈
	row_size = 3;
	//초기배열
	for(int i=1;i<=3;i++){
	    for(int j=1;j<=3;j++){
	        cin>>A[i][j];
	    }
	}
}

//행연산
void R(){
    //각 행마다 진행
    for(int i=1;i<=row_size;i++){
        int num[maxi];//각 숫자의 개수
        memset(num,0,sizeof(num));//초기화
        for(int j=1;j<=col_size;j++){
            num[A[i][j]]++;
        }
        
        vector<pair<int,int>> v;//정렬용
        for(int k=1;k<maxi;k++){
            if(num[k]>0){
                //정렬의 용이성을 위해 반대로 넣어줌
                v.push_back({num[k],k});//개수,숫자    
            }
        }
        sort(v.begin(),v.end());//정렬
        
        //배열 갱신
        for(int j=0;j<v.size();j++){
            int vx = v[j].first;//개수
            int vy = v[j].second;//숫자
            A[i][2*j+1] = vy;
            A[i][2*j+2] = vx;
        }
        //벡터 뒷부분은 0으로
        int new_size = 2*v.size();
        col_size = max(col_size,new_size);//열 사이즈 갱신
        for(int j=new_size+1;j<=col_size;j++){
            A[i][j] = 0;
        }
        
        //범위 초과
        if(col_size>100){
            col_size = 100;
        }
    }
}
//열연산
void C(){
    //각 열마다 진행
    for(int j=1;j<=col_size;j++){
        int num[maxi];//각 숫자의 개수
        memset(num,0,sizeof(num));//초기화
        for(int i=1;i<=row_size;i++){
            num[A[i][j]]++;
        }
        
        vector<pair<int,int>> v;//정렬용
        for(int k=1;k<maxi;k++){
            if(num[k]>0){
                //정렬의 용이성을 위해 반대로 넣어줌
                v.push_back({num[k],k});//개수,숫자    
            }
        }
        sort(v.begin(),v.end());//정렬
        
        //배열 갱신
        for(int i=0;i<v.size();i++){
            int vx = v[i].first;//개수
            int vy = v[i].second;//숫자
            A[2*i+1][j] = vy;
            A[2*i+2][j] = vx;
        }
        
        //벡터 뒷부분은 0으로
        int new_size = 2*v.size();
        row_size = max(row_size,new_size);//열 사이즈 갱신
        for(int i=new_size+1;i<=row_size;i++){
            A[i][j] = 0;
        }
        
        //범위 초과
        if(row_size>100){
            row_size = 100;
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);

    input();//입력
    for(int t=0;t<=100;t++){
        //목표 발견
        if(A[r][c]==k){
            cout<<t;
            return 0;
        }
        //RC연산
        if(row_size>=col_size){
            R();
        }else{
            C();
        }
        /*
        //결과
        for(int i=1;i<=row_size;i++){
            for(int j=1;j<=col_size;j++){
                cout<<A[i][j]<<" ";
            }
            cout<<"\n";
        }
        */
    }
    cout<<-1;//목표를 발견하지 못함
    return 0;
}
