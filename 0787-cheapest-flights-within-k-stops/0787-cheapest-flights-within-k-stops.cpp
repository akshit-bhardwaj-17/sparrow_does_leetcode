class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int , pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>price(n,INT_MAX);
  price[src]=0;

        while(!q.empty())
        {
          auto it= q.front();
          int stops= it.first;
          int node= it.second.first;
          int cost= it.second.second;
          q.pop();
          if(stops>k)
          continue; //we cannot travel more from this path
         for(auto child: adj[node])
         {
            if(cost+child.second<price[child.first])
            {
               price[child.first]=cost+child.second;
               q.push({stops+1,{child.first,price[child.first]}});
            }
         }
       
        }

        if(price[dst]!=INT_MAX)
        return price[dst];
        return -1;

    }
};