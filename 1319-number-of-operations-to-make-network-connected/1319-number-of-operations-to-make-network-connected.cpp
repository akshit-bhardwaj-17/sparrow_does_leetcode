class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
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
    int makeConnected(int n, vector<vector<int>>& connections) {

        
        if (connections.size() < n - 1)
            return -1;

        DSU dsu(n);

        int extraEdges = 0;

        
        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            if (dsu.findParent(u) == dsu.findParent(v)) {
                extraEdges++;
            } else {
                dsu.unionBySize(u, v);
            }
        }

    
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.findParent(i) == i)
                components++;
        }

        int requiredEdges = components - 1;

        if (extraEdges >= requiredEdges)
            return requiredEdges;

        return -1;
    }
};