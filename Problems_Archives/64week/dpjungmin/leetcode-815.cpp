class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
            return 0;

        // buses[i] = the list of buses that include stop i in their route
        unordered_map<int, vector<int>> buses;

        for (int bus = 0; bus < routes.size(); bus++) {
            for (int stop : routes[bus]) {
                buses[stop].push_back(bus);
            }
        }

        vector<bool> vis(routes.size());
        queue<int> q;

        // Add all buses that tarvel source
        for (int bus : buses[source]) {
            vis[bus] = true;
            q.push(bus);
        }

        int ans = 0;

        while (!q.empty()) {
            ans++;
            int sz = q.size();
            // Exhuast the entire queue to simulate traveling one stop simultaneously
            while (sz--) {
                int b = q.front();
                q.pop();
                // Travel the entire bus routes
                for (int stop : routes[b]) {
                    if (stop == target)
                        return ans;
                    // Add all buses that we haven't took and that travel stop
                    for (int bus : buses[stop]) {
                        if (!vis[bus]) {
                            vis[bus] = true;
                            q.push(bus);
                        }
                    }
                }
            }
        }

        return -1;
    }
};
