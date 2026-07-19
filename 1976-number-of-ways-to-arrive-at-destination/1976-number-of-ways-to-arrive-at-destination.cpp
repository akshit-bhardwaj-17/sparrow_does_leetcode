class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>>adj(n);
       for (int i = 0; i < roads.size(); i++)
        {
            auto it = roads[i];
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<
    pair<long long, int>,
    vector<pair<long long, int>>,
    greater<pair<long long, int>>> pq;

    vector<long long> time(n,LLONG_MAX);
    vector<int>ways(n,0);
    const int mod=1e9+7;

    pq.push({0,0});
    time[0]=0;
    ways[0]=1;
    while(!pq.empty())
    {
        auto it= pq.top();
        pq.pop();
        int node=it.second;
        long long t = it.first;
        if (t > time[node])
    continue;

        for( auto it:adj[node])
        {
            long long time2=it.second;
            int child =it.first;

            if(time2+time[node]<time[child])
            {
                time[child]=time2+time[node];
               ways[child] = ways[node];
                pq.push({time[child],child});

            }
            else if(time2+time[node]==time[child])
            {
              ways[child] = (ways[child] + ways[node]) % mod;
                
            }
        }
    }




   return ways[n-1]; }
}; 