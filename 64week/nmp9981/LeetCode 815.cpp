class Solution {
private:
    unordered_map<int,vector<int>> graph;//그래프

public:
    void SettingGraph(vector<vector<int>>& routes){
        for(int i=0;i<routes.size();i++){
            int routesSize = routes[i].size();
            for(int j=0;j<routesSize;j++){
                graph[routes[i][j]].push_back(i);//해당 지점은 몇번인가?
            }
        }
    }
    
    int Bus(vector<vector<int>>& routes,int start,int end){
        queue<pair<int,int>> q;
        q.push({start,0});

        while(!q.empty()){
            int x = q.front().first;
            int cnt = q.front().second;
            q.pop();

            //도착
            if(x==end){
                return cnt;
            }
            //다음 지점
            for(int i : graph[x]){
                for(int j=0;j<routes[i].size();j++){
                    q.push({routes[i][j],cnt+1});
                }
                routes[i].clear();
            }
        }
        return -1;//도달 불가
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        SettingGraph(routes);
        return Bus(routes,source,target);
    }
};
