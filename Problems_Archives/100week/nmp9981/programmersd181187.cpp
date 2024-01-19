#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

//내부의 점
ll InsidePoint(ll r1, ll r2){
    ll countPoints = 0;//점의 개수
    for(int y=1;y<=r2;y++){//y좌표 기준
        int maxX = (int)sqrt(r2*r2-(ll)y*y);
        int minX = r1>=y?ceil(sqrt(r1*r1-(ll)y*y)):0;
        countPoints+=(maxX-minX+1);
    }
    return 4*countPoints;
}
long long solution(int r1, int r2) {
    return InsidePoint(r1,r2);
}
