//637 

//NOT VERY EFFICIENT

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> answer;
        if (root==NULL) return answer;
        queue <TreeNode*> q;
        q.push(root);
        while (q.empty()==false){
            int levelSize = q.size();
            vector <int> level;
            double avg=0;
            for (int i=0; i<levelSize; i++){
                TreeNode* current = q.front();
                q.pop();
                level.push_back(current->val);
                avg+=current->val;
                if (current->left!=NULL) q.push(current->left);
                if (current->right!=NULL) q.push(current->right);
            }
            answer.push_back((double)(avg/levelSize *1.0));
        }
        return answer;
    }
};