#include <iostream>
#include <vector>

using namespace std;

int main (){
    int n, tmp;
    long long x1, x2 ,xt , y1, y2, yt;
    vector<int> buildings;
    

    cin >> n;
    vector<int> look(n,0);
    for(int i = 0; i < n; i++){
        cin >> tmp;
        buildings.push_back(tmp);
    }

    for(int i = 0; i < n; i ++){
        x1 = i;
        y1 = buildings[i];
        for(int j = i +1 ; j < n; j++){
            x2 = j;
            y2 = buildings[j];
            if(i + 1 == j){
                look[i]++;
                look[j]++;
            }
            for(int k = i +1; k < j; k++){
                xt = k;
                yt = buildings[k];
                if((yt - y1) * (x2 -x1) >= (y2 - y1) * (xt-x1))
                    break;
                if(k == j - 1){
                    look[i]++;
                    look[j]++;
                }
            }
        }
    }
    int result = 0;
    for(auto i: look)
        if(result < i)
            result = i;

    cout << result;
    return 0;
}
