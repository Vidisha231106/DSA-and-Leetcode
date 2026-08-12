// Strivers Sheet

/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
	public:
		vector<int> floorCeilOfBST(TreeNode* root,int key){
			//your code goes here
            vector< int> answer(2, -1);
            TreeNode* temp= root;
            while (root!=nullptr){
                if (root->data==key){
                    answer[0]=root->data;
                    answer[1]=root->data;
                    return answer;
                }
                if (root->data<key){
                    answer[0]=root->data;
                    root=root->right;
                }
                else{
                    answer[1]=root->data;
                    root=root->left;
                }
            }
            return answer;
		}
};