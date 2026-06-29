/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public: stack<TreeNode*>st;
     void pushall(TreeNode * root)
     {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
     }
     bool hasNext()
     { 
        return !st.size()==0;
     }
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        TreeNode * curr= st.top();
        st.pop();
        pushall(curr->right);  //if it has right all the nodes will get pushed
  return curr->val;
    }
    
   
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */