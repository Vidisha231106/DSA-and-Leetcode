// 116

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root==nullptr) return nullptr;
        queue <Node*> q;
        q.push(root);
        while (q.empty()==false){
            int levelSize = q.size();
            vector <Node*> level;
            for (int i=0; i<levelSize; i++){
                Node* curr = q.front();
                q.pop();
                level.push_back(curr);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            Node* temp = level[0];
            for (int i=0; i<levelSize-1; i++){
                level[i]->next = level[i+1];
                temp = temp->next;
            }
            temp->next = nullptr;

        }
        return root;
    }
};