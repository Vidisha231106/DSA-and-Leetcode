//429 - INEFFICIENT BUT WORKING CODE

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> answer;
        if (root==NULL) return answer;
        queue <Node*> q;
        q.push(root);
        while (q.empty()==false){
            int levelSize = q.size();
            vector <int> level;
            for (int i=0;i<levelSize; i++){
                Node * current = q.front();
                q.pop();
                level.push_back(current->val);
                for (int j=0; j<current->children.size(); j++){
                    q.push(current->children[j]);
                }
            }
            answer.push_back(level);
        }
        return answer;
    }
};