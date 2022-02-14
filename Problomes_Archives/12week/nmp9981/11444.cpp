#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> Matrix;

ll n;
const ll r = 2;
const ll mod = 1000000007;
Matrix m(r,vector<ll>(r));
Matrix ans(r,vector<ll>(r));

//입력
void input(){
    cin>>n;
    m = {{1,1},{1,0}};//행렬 정의
}

//행렬의 곱셈
Matrix mul(Matrix p, Matrix q){
    Matrix temp(r,vector<ll>(r));
    for(int i=0;i<r;i++){
        for(int j=0;j<r;j++){
            for(int k=0;k<r;k++){
                temp[i][j]+=(p[i][k]*q[k][j]);
                temp[i][j]%=mod;
            }
        }
    }
    return temp;
}

//피보나치 수열
Matrix pibo(ll x){
    //재귀 종료
    if(x==1){
        return m;
    }
    //분할
    Matrix adj,func;
    func = pibo(x/2);
    if(x%2==0){
        adj = mul(func,func);
    }else{
        adj = mul(mul(func,func),m);
    }
    return adj;
}

int main()
{
    input();//입력
    ans = pibo(n);//피보나치 수열
    cout<<ans[1][0];
    return 0;
}
