// Strivers Sheet

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
		int timeToBurnTree(TreeNode* root, int start){
            //your code goes here
            queue <TreeNode*> q;
            unordered_map <TreeNode*, TreeNode*> mp;
            q.push(root);
            mp[root]=nullptr;
            TreeNode* temp=nullptr;
            while (q.empty()!=true){
                TreeNode* curr=q.front();
                if (curr->data==start) temp=curr;
                q.pop();
                if (curr->left){
                    q.push(curr->left);
                    mp[curr->left]=curr;
                }
                if (curr->right){
                    q.push(curr->right);
                    mp[curr->right]=curr;
                }
            }
            queue <pair<TreeNode*, int>> nq;
            nq.push({temp, 0});
            int max_time=INT_MIN;
            unordered_set <TreeNode*> visited;
            while (nq.empty()!=true){
                pair<TreeNode*, int> curr=nq.front();
                nq.pop();
                if (curr.first==nullptr) continue;
                if (visited.find(curr.first)!=visited.end()) continue;
                visited.insert(curr.first);
                max_time=max(max_time, curr.second);
                
                if (curr.first->left){
                    nq.push({curr.first->left, curr.second+1});
                }
                if (curr.first->right){
                    nq.push({curr.first->right, curr.second+1});
                }
                nq.push({mp[curr.first], curr.second+1});
            }
            return max_time;
		}	
};