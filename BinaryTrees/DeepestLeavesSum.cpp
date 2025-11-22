// MY CODE - inefficient

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
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> answer;
        if (root==NULL) return 0;
        queue <TreeNode*> q;
        q.push(root);
        int numLevels=0;
        while (q.empty()==false){
            int levelSize = q.size();
            vector <int> level;
            for (int i=0; i<levelSize; i++){
                TreeNode * current = q.front();
                q.pop();
                level.push_back(current->val);
                if (current->left!=NULL) q.push(current->left);
                if (current->right!=NULL) q.push(current->right);
            }
            numLevels++;
            answer.push_back(level);
        }
        int sum=0;
        for (int i=0; i< answer[numLevels-1].size(); i++){
            sum+=answer[numLevels-1][i];
        }
        return sum;
    }
};

//MORE EFFICIENT CODE: 

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

    vector<pair<int ,int>>res;
    int maxx=0;

    void dfs(TreeNode* root , int depth){

        if(!root) return;
        if(!root->left && !root->right){
            maxx=max(maxx , depth);
            res.push_back({depth ,root->val});
            return;
        }

        dfs(root->left , depth+1);
        dfs(root->right , depth+1);
    }
    int deepestLeavesSum(TreeNode* root) {

        dfs(root ,1);

        int ans=0;
        for(auto it : res){
            if(it.first==maxx)
            ans+=it.second;
        }    

        return ans;
    }
};