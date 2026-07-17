class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // dist[node][stopsLeft]
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        dist[src][k + 1] = 0;
        pq.push({0, {src, k + 1}});

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int cost = it.first;
            int node = it.second.first;
            int stopsLeft = it.second.second;

            if(node == dst)
                return cost;

            if(stopsLeft == 0)
                continue;

            for(auto child : adj[node])
            {
                int adjNode = child.first;
                int wt = child.second;

                if(cost + wt < dist[adjNode][stopsLeft - 1])
                {
                    dist[adjNode][stopsLeft - 1] = cost + wt;
                    pq.push({cost + wt, {adjNode, stopsLeft - 1}});
                }
            }
        }

        return -1;
    }
};