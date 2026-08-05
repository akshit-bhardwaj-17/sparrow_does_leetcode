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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        DSU dsu(n);

        unordered_map<string, int> mailToNode;

       
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (mailToNode.find(mail) == mailToNode.end()) {
                    mailToNode[mail] = i;
                } else {
                    dsu.unionBySize(i, mailToNode[mail]);
                }
            }
        }
           vector<vector<string>> mergedMails(n);

        for( auto &it : mailToNode)
        {
            string email= it.first;
            int acc= it.second;
            int parent= dsu.findParent(acc);
            mergedMails[parent].push_back(email);

        }

        vector<vector<string>> ans;
        for(int i =0 ;i<n;i++)
        {
            if(mergedMails[i].empty())
            continue;

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(mergedMails[i].begin(),mergedMails[i].end());
            for(auto str : mergedMails[i] )
            {
                temp.push_back(str);
            }
            ans.push_back(temp);
        }
        




return ans;


    }
};