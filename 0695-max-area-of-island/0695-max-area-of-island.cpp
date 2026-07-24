class Solution {
public:
    void func(vector<vector<int>>& grid,vector<vector<bool>>&vis,int &area,int i,int j)
    {    int m = grid.size();
        int n =grid[0].size();
        if(i<0||i==m ||j<0||j>=n||vis[i][j]||grid[i][j]==0)
        return;
        vis[i][j]=true;
        area++;
        func(grid,vis,area,i+1,j);
          func(grid,vis,area,i,j+1);
            func(grid,vis,area,i-1,j);
              func(grid,vis,area,i,j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n =grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int ans= -1e9;
        for( int i =0;i<m;i++)
        {
            for( int j=0;j<n;j++)
            {
                int area=0;
                func(grid,vis,area,i,j);
                ans= max(ans,area);
            }
        }
   return ans;
    }
};