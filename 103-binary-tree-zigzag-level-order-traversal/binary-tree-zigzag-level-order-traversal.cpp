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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // code here
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        queue<TreeNode*> que;
        que.push(root);
        bool lefttoright = true;
        while(!que.empty()){
            int size = que.size();
            vector<int> ans(size);
        
            for(int i=0;i<size;i++){
                TreeNode* front = que.front();
                que.pop();
                
                int index = lefttoright ? i : size - i - 1;
                ans[index] = front-> val;
                
                if(front-> left)que.push(front-> left);
                if(front-> right)que.push(front-> right);
            }
            lefttoright = !lefttoright;
            result.push_back(ans);
            
        }
        return result;
    }
};