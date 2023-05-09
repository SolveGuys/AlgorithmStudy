#include <string>
#include <vector>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;
const int maxi = 100001;
ll Tile[maxi];//경우의 수
ll addTile[maxi];//추가량

//타일 채우기
void TileCover(){
    Tile[0] = 1;
    Tile[1] = 1;
    Tile[2] = 3;
    for(int i=3;i<maxi;i++){
        Tile[i] = Tile[i-1]+2*Tile[i-2]+5*Tile[i-3];//기본 케이스
        //추가 케이스
        if(i>=6) addTile[i] = (2*Tile[i-4]+2*Tile[i-5]+4*Tile[i-6]+addTile[i-3])%mod;
        else{
            if(i==4) addTile[4] = 2;
            else if(i==5) addTile[5] = 4;
        }
        //테이스 개수
        Tile[i]+=addTile[i];
        Tile[i]%=mod;
    }
}
int solution(int n) {
    TileCover();//타일 채우기
    return Tile[n];
}
