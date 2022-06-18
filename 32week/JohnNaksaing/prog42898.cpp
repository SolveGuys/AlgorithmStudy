#include <string>
#include <vector>
#include <iostream>

int solution(int m, int n, std::vector<std::vector<int>> puddles) {
    int answer = 0;
    long int way[m+1][n+1];
    
    for(int i = 0; i <= m; i++){
        way[i][0] = 0;
    }
    for(int i = 0; i <= n; i++){
        way[0][i] = 0;
    }
        
    for(int i = 0; i < puddles.size(); i++){
        way[puddles[i][0]][puddles[i][1]] = -1;
    }
    
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++){
            way[1][1] = 1;
            //if(i == 1 && j == 1) {continue;}
            
            if(way[i][j] == -1){
                way[i][j] = 0;
                continue;
            }
            
            way[i][j] = ( way[i-1][j] + way[i][j-1] )  % 1000000007;
        }
    }
    
    /*
    for(int i = 0; i <= m; i ++){
        for(int j = 0; j <= n; j ++){
            std::cout << way[i][j] << " ";
        }
        std::cout << '\n';
    }
    */
    
    answer = way[m][n];
    return answer;
}