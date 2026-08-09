class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public: bool isvalid(int r,int c,int n)
{
    return r>=0&&r<n&& c>=0&&c<n;
}
    int largestIsland(vector<vector<int>>& grid) {
         int n = grid.size();
        
        DSU ds(n*n);
         for( int i =0;i<n;i++)
         {
            for( int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int dr [] ={-1,1,0,0};
                    int dc [] = {0,0,-1,1};
                    for( int x= 0;x<4;x++)
                    {
                        int nr= i+dr[x];
                        int nc=j+dc[x];

                        if(isvalid(nr,nc,n)&& grid[nr][nc])
                        {   int node =i*n+j;
                           int neighbour =nr*n+nc;
                           ds.unionBySize(node,neighbour);
                            
                        }
                    }
                }
            }
         }
     
     int ans=-1e9;
     for( int i =0;i<n;i++)
         {
            for( int j=0;j<n;j++)
            {  
                 unordered_set<int> s;
                if(grid[i][j]==0)
                {
                    int dr [] ={-1,1,0,0};
                    int dc [] = {0,0,-1,1};
                    for( int x= 0;x<4;x++)
                    {
                        int nr= i+dr[x];
                        int nc=j+dc[x];

                        if(isvalid(nr,nc,n)&& grid[nr][nc])
                        {  
                           s.insert(ds.findParent(nr*n+nc));
                            
                        }
                    }
                    int tsize=1;
                    for(int par:s)
                    {
                        tsize+=ds.size[par];

                    }
                    ans= max(ans,tsize);
                }
            }
         }

        for(int i=0;i<n*n;i++)
{
    ans=max(ans,ds.size[ds.findParent(i)]);
}
      return ans;
        
    }
};