    #include <queue>
    #include <vector>
    using namespace std;
    
  struct TreeNode
  {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {      
        vector<vector<int>> result;
        queue<TreeNode*> q;
        
        if (root == nullptr) return result;

        q.push(root);
        q.push(nullptr);

        vector<int> level;
        bool is_order_left = true;
        
        while (!q.empty())
        {
            auto next = q.front();
            q.pop();
            
            if (next != nullptr)
            {
                if (is_order_left)
                    level.push_back(next->val);
                else
                    level.insert(level.begin(), next->val);
                
                if (next->left != nullptr) q.push(next->left);
                if (next->right != nullptr) q.push(next->right);
            }
            else
            {
                result.push_back(level);
                level.clear();
                
                if (q.size() > 0) q.push(nullptr);
                
                is_order_left = !is_order_left;
            }
        }

        return result;
    }