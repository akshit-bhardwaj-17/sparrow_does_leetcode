class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;
       int m = heights.size();
       int n = heights[0].size();
       vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
       dis[0][0]=0;
       pq.push({0,{0,0}});
       int dr[]={-1,1,0,0};
       int dc[]={0,0,-1,1};
       while(!pq.empty())
       {
        auto it = pq.top();
        int d=it.first;
        int r=it.second.first;
        int c=it.second.second;
        pq.pop();
        if(r==m-1&&c==n-1)
        return d;

        for(int i =0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0&&nr<m&&nc>=0&&nc<n)
            {
             int new_eff = max(d, abs(heights[r][c] - heights[nr][nc]));
               if(new_eff<dis[nr][nc])
              { dis[nr][nc]=new_eff;
               pq.push({new_eff,{nr,nc}});}
            }
        }
       }
    return -1;}
};