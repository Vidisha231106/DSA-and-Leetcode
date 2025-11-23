//559 - Maximum Depth of N-ary Tree
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
#include <algorithm>
class Solution {
public:
    void findDistances(Node *root, vector<int>& distances, int d){
        if (root==NULL){
            return;
        }
        if (root->children.empty()==true){
            distances.push_back(d);
            return;
        }
        for (int i=0; i<root->children.size(); i++) findDistances(root->children[i], distances, d+1);
    }


    int maxDepth(Node* root) {
        if (root==NULL) return 0;
        vector <int> distances;
        findDistances(root, distances, 1);
        return *max_element(distances.begin(), distances.end());
    }
};