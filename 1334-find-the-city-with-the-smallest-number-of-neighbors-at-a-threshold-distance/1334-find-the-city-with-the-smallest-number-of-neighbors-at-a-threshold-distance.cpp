class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
  vector<vector<int>>dist(n,vector<int>(n,1e9));
  vector<int>count(n,0);
  for(int i =0;i<edges.size();i++)
  {
    auto it= edges[i];
    int a =it[0];
    int b=it[1];
    int w=it[2];
    if(w<=distanceThreshold)
    {
        dist[a][b]=w;
        dist[b][a]=w;
       
    }

  }
     for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (dist[i][k] == 1e9 || dist[k][j] == 1e9)
                continue;

            dist[i][j] = min(dist[i][j],
                             dist[i][k] + dist[k][j]);
         
        }
    }
}   
   for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if( i==j)
            continue;
       if(dist[i][j]<=distanceThreshold)
            {
                 count[i]++;
               
            }
        }
   }
      int ans = -1;
        int minimum = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (count[i] <= minimum) {
                minimum = count[i];
                ans = i;
            }
        }

        return ans;
  
    }
};