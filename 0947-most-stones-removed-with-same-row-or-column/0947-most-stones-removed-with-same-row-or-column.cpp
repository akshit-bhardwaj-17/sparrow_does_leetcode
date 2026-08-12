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
public:

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU ds(n);

        for ( int i =0;i<n;i++)
        {
            for(int j =i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    ds.unionBySize(i,j);
                }
            }
        }
        int components=0;
        for ( int i =0;i<n;i++)
        {
            if(ds.findParent(i)==i)
            {
                components++;
            }
        }
        return n-components;

    }
};